#include "headlights.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Headlights w;
    w.show();
    return a.exec();
}
