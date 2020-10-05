#include "mainwnd_ws.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWnd_WS::instance();

    return a.exec();
}
