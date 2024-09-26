#ifndef MAINWINDOWREGISTER_H
#define MAINWINDOWREGISTER_H

#include <QMainWindow>
#include <QString>
namespace Ui {
class MainWindowRegister;
}

class MainWindowRegister : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowRegister(QWidget *parent = nullptr);
    ~MainWindowRegister();

private:
    Ui::MainWindowRegister *ui;

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOWREGISTER_H
