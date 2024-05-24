#include "Test.hpp"
#include "GUI.hpp"

#include <QApplication>

int main(int argc, char **argv) {
    Test tests;
    tests.runAll();

    QApplication a(argc, argv);

    LibraryFile lib{"../database/stock.txt"};
    ShoppingCart cart;

    Service service{lib, cart};

    GUI gui(service);
    gui.setWindowTitle("Library");
    gui.show();

    return QApplication::exec();
}