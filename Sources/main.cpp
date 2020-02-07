#include <QApplication>
#include "game.h"
#include "mainwindow.h"
#include "test_player.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>

Game *game;
MainWindow *Menu;

int main(int argc, char *argv[])
{
    //freopen("testing.log", "w", stdout);
    QApplication a(argc, argv);
    //QTest::qExec(new Test_Player, argc, argv);

    game = new Game();

    Menu = new MainWindow();
    Menu->show();


    return a.exec();
}

