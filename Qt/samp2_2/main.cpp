#include "dialogsamp.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialogsamp w;
    w.show();
    return a.exec();
}
