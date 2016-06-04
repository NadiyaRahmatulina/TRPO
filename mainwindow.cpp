#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "form.h"
#include "ui_form.h"

MainWindow::MainWindow(QWidget *parent) : //подключение формы
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() // Старт
{
    Form *f = new Form();
    f -> show(); //открытие игры
    this -> close();
}


void MainWindow::on_pushButton_2_clicked() // Помощь
{
    QMessageBox::information(this, "Помощь",
                             "Чтобы запустить игру, нажмите на иконку 'Play'."
                             "\nЧтобы узнать информацию о создателях, нажмите на 'About'."
                             "\nУправлять можно с помощью мышки."
                             "\nИгра завершится, когда собирется рисунок."
                             ); // впсплывающее окно игре
}


void MainWindow::on_pushButton_3_clicked() // Информация
{
     QMessageBox::information(this, "Об игре",
                              "Курсовая - пятнашки."
                              "\nВыполнили:"
                              "\nСтуденты группы ИП-514:"
                              "\nСахарчук Дарья,"
                              "\nРыбалко Ариана,"
                              "\nРахматулина Надия,"
                              "\nТкаченко Эмилия."
                              ); // впсплывающее окно о курсовой
}



void MainWindow::on_pushButton_4_clicked() // Выход
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Выход", "Вы действительно хотите выйти?", QMessageBox::Yes | QMessageBox::No); // впсплывающее окно о выходе
    if(reply == QMessageBox::Yes) // если да, то
    {
        close(); // закрытие приложения
    }
}


