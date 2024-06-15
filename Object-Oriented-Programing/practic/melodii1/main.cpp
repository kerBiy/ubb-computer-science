#include "Test.hpp"
#include "MainWindow.hpp"

#include <QApplication>

int main(int argc, char *argv[]) {
    Test tests;
    tests.testAll();

    QApplication app(argc, argv);
    Repository repo{"../songs.txt"};
    Service service{repo};

    MainWindow mainWindow(service);
    mainWindow.show();

    return QApplication::exec();
}
