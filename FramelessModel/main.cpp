#include "FramelessModel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FramelessModel w;
    w.show();
    return a.exec();
}
