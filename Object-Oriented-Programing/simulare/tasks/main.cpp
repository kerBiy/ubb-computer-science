#include <QApplication>

#include "Test.hpp"
#include "GUI.hpp"

int main(int argc, char *argv[]) {
    Test test;
    test.testAll();

    QApplication a(argc, argv);
    Repository repo("../database.txt");
    Service service(repo);
    GUI gui(service);
    gui.show();

    return QApplication::exec();
}
