#include "mainwindow.h"
#include "mainwindow.ui"
#include "game.h"

extern Game *game;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(game, &Game::exit, this, &MainWindow::endGame);
}

void MainWindow::on_ExitButton_clicked()
{
    this->close();
}

void MainWindow::on_PlayButton_clicked()
{
    game->GameStart();
    this->hide();
}


MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::endGame()
{
    //game->deleteLater();
    this->show();
}
