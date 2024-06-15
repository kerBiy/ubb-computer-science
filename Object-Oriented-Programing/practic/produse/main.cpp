#include <QApplication>
#include "GUI.hpp"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Repository repo("../database.txt");
    Service service(repo);

    GUI gui(service);
    gui.show();

    return QApplication::exec();
}
