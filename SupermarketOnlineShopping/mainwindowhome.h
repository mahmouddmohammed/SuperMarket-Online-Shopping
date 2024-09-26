#ifndef MAINWINDOWHOME_H
#define MAINWINDOWHOME_H

#include <QMainWindow>
#include <string>
#include <iostream>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QGridLayout>
namespace Ui {
class MainWindowHome;
}

class MainWindowHome : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowHome(QWidget *parent = nullptr);
    ~MainWindowHome();

public:
    void show_products(QString nameofpages[]);
    void show_cart();
    void check_out();
    void profile_setting();
    void rearrange_products_in_grid(QGridLayout* layout);
    void completer_forinput();
    void prevorders();
    void view_dashboard();
    void viewpreviousorders();
    void couponsgift();


public:
    QLabel *whatuser_change[5];
    QPushButton *btn_change[5];
    QLineEdit *update_input[5];
    QPushButton *update_confirm[5];


public:
    QPushButton *boxes_btn_closed[4];
    QPushButton *boxes_btn_open[4];


public:
    int product_no;



public slots:
    void on_category_btn_clicked();

    void on_Electronics_btn_clicked();

    void on_VideoGamesbtn_clicked();

    void on_Groceries_btn_clicked();

    void on_Beautybtn_clicked();

    void on_Officebtn_clicked();

    void on_HomeFurniturebtn_clicked();

    void on_SportsSupplies_clicked();



private slots:
    void on_cart_btn_clicked();

    void on_logout_btn_clicked();

    void on_profile_btn_clicked();

    void on_dashboard_btn_clicked();

    void on_previous_orders_btn_clicked();

    void on_sellers_btn_clicked();

    void on_searchproductname_btn_clicked();

    void on_coupons_btn_clicked();

    void on_paywith_visa_clicked();

    void on_visa_pay_btn_clicked();

    void on_cashon_delivery_clicked();

private:
    Ui::MainWindowHome *ui;
};

#endif // MAINWINDOWHOME_H
