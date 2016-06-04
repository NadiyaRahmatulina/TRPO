#include <QString>
#include <QtTest>
#include <Game.h>
#include <QApplication>

class Game_test : public QObject
{
    Q_OBJECT

public:
    Game_test();

private Q_SLOTS:
    void checkGameOver_test();
};

Game_test::Game_test()
{
}

void Game_test::checkGameOver_test()
{
    int tmp = 0;
    QApplication w(tmp, NULL);
    Game a;
    //QCOMPARE(a.checkGameOver(0),(0,1));
    QCOMPARE(a.checkGameOver(1), 0);
    QCOMPARE(a.checkGameOver(3), 0);
    QCOMPARE(a.checkGameOver(4), 0);
}

QTEST_APPLESS_MAIN(Game_test)

#include "tst_game_test.moc"
