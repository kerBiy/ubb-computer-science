#include <iostream>
#include <vector>

class Examen {
   private:
    std::string name;
    std::string time;

   public:
    Examen(const std::string &name, const std::string &time)
        : name(name), time(time) {}

    std::string getDescriere() const { return name + " ora: " + time; }
};

template <typename T>
class ToDo {
   private:
    std::vector<T> items;

   public:
    ToDo() = default;

    ToDo &operator<<(const T &item) {
        items.push_back(item);
        return *this;
    }

    void printToDoList(std::ostream &out) const {
        for (const auto &item : items) {
            out << item.getDescriere() << '\n';
        }
    }
};

int main() {
    ToDo<Examen> todo;

    Examen oop{"oop scris", "8:00"};
    todo << oop << Examen{"oop practic", "11:00"};  // Adauga 2 examene la todo
    std::cout << oop.getDescriere() << "\n";
    // tipareste la consola: oop scris ora 8:00
    // itereaza elementele adaugate si tipareste
    // la consola lista de activitati //in acest caz
    // tipareste: De facut:oop scris ora 8:00;oop
    // practic ora 11:00 todo.
    todo.printToDoList(std::cout);
}