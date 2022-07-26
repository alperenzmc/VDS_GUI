#include "mainwindow.h"
#include <iostream>
#include "vehicledataprovider.h"
#include <memory>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

w.activateWindow();



    w.show();
    return a.exec();
}
