#include "form.h"
#include "ui_form.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QLCDNumber>
#include <QPushButton>
#include <QSpinBox>
#include <QTimer>
#include <QVBoxLayout>

Form::Form(QWidget *parent) : game(NULL), // подключение формы
    QWidget(parent),
    ui(new Ui::Form)
{
    ui -> setupUi(this);

    layout = new QVBoxLayout(this);
    settingsLayout = new QHBoxLayout;

    QPushButton* newgame = new QPushButton();
    QPushButton* exitgame = new QPushButton();

    QPixmap newG(":/sprite/new.png");
    QPixmap exG(":/sprite/exit.png");
    QIcon newGIcon(newG);
    QIcon exGIcon(exG);
    newgame  -> setIcon(newGIcon);
    exitgame -> setIcon(exGIcon);
    newgame  -> setIconSize(QSize(304,70)); // загрузка картинки "Новая игра"
    exitgame -> setIconSize(QSize(290,70)); // загрузка картинки "Выход"

    connect(newgame,  SIGNAL(clicked()), this, SLOT(newGame())); // Если нажата кнопка, то новая игра
    connect(exitgame, SIGNAL(clicked()), this, SLOT(exitGame())); // Если нажата кнопка, то выход

    settingsLayout -> addWidget(newgame);
    settingsLayout -> addWidget(exitgame);

    layout -> setContentsMargins(2, 2, 2, 2);
    layout -> addLayout(settingsLayout);
    newGame();

    setLayout(layout);
}

Form::~Form() // подключение формы
{
    delete ui;
}

void Form::newGame()
{
    if(game) // удаляем старое поле
    {
        layout -> removeWidget(game);
        delete game;
    }

    game = new Game(this); // рисуем новое поле
    layout -> addWidget(game);

    layout -> update();

    game -> hide();
    game -> show();

    resize(sizeHint());
}

void Form::exitGame() // выход из игры
{
    MainWindow *f = new MainWindow();
    f    -> show();
    this -> close();
}
