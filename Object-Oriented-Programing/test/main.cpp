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

    StatusWindow opened("open", serv);
    StatusWindow inprogress("inprogress", serv);
    StatusWindow closed("closed", serv);

    opened.show();
    inprogress.show();
    closed.show();

    return QApplication::exec();
}
