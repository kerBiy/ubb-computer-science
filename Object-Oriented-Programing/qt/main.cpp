#include <QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QWidget widget;

    auto* ly = new QHBoxLayout;
    widget.setLayout(ly);

    ly->addWidget(new QLabel{"Hello"});
    ly->addWidget(new QPushButton{"Buy Nigger"});

    widget.show();

    return QApplication::exec();
}
