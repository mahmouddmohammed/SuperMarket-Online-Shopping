#ifndef MAINWINDOWLOGIN_H
#define MAINWINDOWLOGIN_H

#include <QMainWindow>

namespace Ui {
class MainWindowLogin;
}

class MainWindowLogin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowLogin(QWidget *parent = nullptr);
    ~MainWindowLogin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_hide_clicked();

    void on_view_clicked();

    void on_pushButton_clicked();

    void on_verifyidentity_clicked();

    void on_confirmnew_clicked();

    void on_eyepassword_hide_forgot_clicked();

    void on_eyepassword_view_forgot_clicked();

    void on_back_btn_clicked();

private:
    Ui::MainWindowLogin *ui;
};

#endif // MAINWINDOWLOGIN_H
