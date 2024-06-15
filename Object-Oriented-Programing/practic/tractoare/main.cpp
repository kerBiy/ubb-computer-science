#include <QApplication>
#include "MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repository repo("../database.txt");
    Service serv(repo);
    MainWindow main_window(serv);

    main_window.show();

    return QApplication::exec();
}
