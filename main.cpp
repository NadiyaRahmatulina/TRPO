#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) //запуск приложения
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(w.geometry().width(),w.geometry().height()); //открытие меню
    w.show();

    return a.exec();
}
