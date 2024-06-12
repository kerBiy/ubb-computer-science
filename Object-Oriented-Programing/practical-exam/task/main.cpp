#include <QApplication>
#include "MainWindow.hpp"
#include "StatusWindow.hpp"
#include "Test.hpp"

int main(int argc, char *argv[]) {
    Test tests;
    tests.testAll();

    QApplication a(argc, argv);

    Repository repo("../database.txt");
    Service serv(repo);

    MainWindow main_window(serv);
    main_window.show();

    StatusWindow openWindow("open", serv);
    StatusWindow inProgressWindow("inprogress", serv);
    StatusWindow closedWindow("closed", serv);

    openWindow.show();
    inProgressWindow.show();
    closedWindow.show();

    return QApplication::exec();
}
