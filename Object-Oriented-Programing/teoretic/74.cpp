#include <iostream>
#include <map>
#include <string>
#include <vector>

class Iterator;

class Grupa {
   private:
    std::vector<std::string> students;

   public:
    std::vector<std::string> select(char letter) {
        std::vector<std::string> res;

        for (const auto &stud : students) {
            if (stud[0] == letter) {
                res.push_back(stud);
            }
        }

        return res;
    }

    Grupa &operator+(const std::string &name) {
        students.push_back(name);
        return *this;
    }

    friend class Iterator;

    Iterator begin();
    Iterator end();
};

class Iterator {
   private:
    Grupa &grupa;
    size_t index;

   public:
    Iterator(Grupa &grupa, size_t index = 0) : grupa(grupa), index(index) {}

    std::string &operator*() { return grupa.students[index]; }

    Iterator &operator++() {
        index++;
        return *this;
    }

    bool operator!=(const Iterator &other) { return index != other.index; }
};

Iterator Grupa::begin() { return Iterator(*this); }
Iterator Grupa::end() { return Iterator(*this, students.size()); }

class Catalog {
   private:
    std::map<int, Grupa> grupe;

   public:
    Grupa &group(int id) { return grupe[id]; }
};

int main() {
    Catalog an1;
    an1.group(211) + "Ion" + "aron";
    an1.group(212) + "ana" + "aurora";
    for (auto name : an1.group(211)) {
        std::cout << name << ",";
    }
    std::vector<std::string> v = an1.group(212).select('a');
    for (auto name : v) {
        std::cout << name << ",";
    }

    return 0;
}