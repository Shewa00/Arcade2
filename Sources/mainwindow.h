#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

/// Использование имени пространств Окна
namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow   /// Класс Окна Меню
{
    Q_OBJECT

public:
    /// Конструктор
    explicit MainWindow(QWidget *parent = nullptr);

    /// Деструктор
    ~MainWindow();

private slots:
    /// Функция нажатия на клавишу Играть
    void on_PlayButton_clicked();

    /// Функция нажатия на клавишу Выйти
    void on_ExitButton_clicked();

    void endGame();
private:
    /// Указатель на Окно
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
