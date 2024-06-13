#include <ctime>
#include <iostream>
#include <string>
#include <vector>

class Channel {
   public:
    virtual void send(const std::string &msg) = 0;
    virtual ~Channel() = default;
};

class Telefon : public Channel {
   private:
    int nrTel;

   public:
    Telefon(int nrtel) : nrTel(nrtel) {}
    void send(const std::string &msg) override {
        std::cout << "Dail: " << nrTel << "\n";
        if (rand() % 5) throw std::exception();
    }
};

class Fax : public Telefon {
   public:
    Fax(int nrtel) : Telefon(nrtel) {}

    void send(const std::string &msg) override {
        try {
            Telefon::send(msg);
            std::cout << "sending fax " << msg << "\n";
        } catch (std::exception &e) {
            throw std::exception();
        }
    }
};

class SMS : public Telefon {
   public:
    SMS(int nrtel) : Telefon(nrtel) {}

    void send(const std::string &msg) override {
        try {
            Telefon::send(msg);
            std::cout << "sending sms " << msg << "\n";
        } catch (std::exception &e) {
            throw std::exception();
        }
    }
};

class Failover : public Channel {
   private:
    Channel *ch1;
    Channel *ch2;

   public:
    Failover(Channel *ch1, Channel *ch2) : ch1(ch1), ch2(ch2) {}
    ~Failover() {
        delete ch1;
        delete ch2;
    }

    void send(const std::string &msg) override {
        try {
            ch1->send(msg);
        } catch (std::exception &e) {
            ch2->send(msg);
        }
    }
};

class Contact {
   private:
    std::vector<Channel *> channels;

   public:
    Contact(Channel *ch1, Channel *ch2, Channel *ch3) {
        channels.push_back(ch1);
        channels.push_back(ch2);
        channels.push_back(ch3);
    }

    ~Contact() {
        for (auto &ch : channels) {
            delete ch;
        }
    }

    void sendAlarm(const std::string &msg) {
        while (true) {
            for (const auto &ch : channels) {
                try {
                    ch->send(msg);
                    return;
                } catch (std::exception &e) {
                }
            }
        }
    }
};

Contact *create() {
    auto *ch1 = new Telefon(720111111);
    auto *ch2 = new Failover(new Fax(720111111), new SMS(720111111));
    auto *ch3 =
        new Failover(new Telefon(730333333),
                     new Failover(new Fax(730333333), new SMS(730333333)));

    auto *final_contact = new Contact(ch1, ch2, ch3);
    return final_contact;
}

int main() {
    srand(time(NULL));
    auto *contact = create();
    std::cout << "Sending msg one\n";
    contact->sendAlarm("salut sefu");

    std::cout << "Sending msg two\n";
    contact->sendAlarm("Raspunde in plm");

    std::cout << "Sending msg three\n";
    contact->sendAlarm("Hai coi ca imi bag pl");

    delete contact;
    return 0;
}