#ifndef SELLERWINDOW_H
#define SELLERWINDOW_H

#include <QMainWindow>

#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

namespace Ui {
class SellerWindow;
}

class SellerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SellerWindow(QWidget *parent = nullptr,QString which_page = "home");
    ~SellerWindow();

public:
    void seller_login();
    void seller_register();

public:
    QString image_path;

public:
    void profile_setting_data();
    float calc_accbalance();
private slots:
    void on_login_btn_loginpage_clicked();

    void on_register_btn_loginpage_clicked();

    void on_login_btn_rpage_clicked();

    void on_register_btnn_rpage_clicked();

    void on_add_product_clicked();

    void on_view_products_clicked();

    void on_logout_clicked();

    void on_addproduct_btn_clicked();

    void on_upload_image_btn_clicked();

    void on_profile_stting_btn_clicked();

    void on_forget_password_btn_login_clicked();

    void on_verifyidentity_clicked();

    void on_confirmnewpassword_btn_clicked();

    void on_eyepassword_view_forget_clicked();

    void on_eyepassword_hide_forget_clicked();

    void on_eyepassword_hide_register_clicked();

    void on_eyepassword_view_register_clicked();

    void on_eyepassword_hide_login_clicked();

    void on_eyepassword_view_login_clicked();

    void on_profile_photo_image_clicked();



    void on_add_products_now_clicked();

    void on_home_btn_clicked();

    void on_agreements_btn_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_category_currentIndexChanged(int index);

    void on_back_btn_clicked();

public:
    QString profile_photo_image; //in register;
public:
    //Profile Setting
    QLabel *whatuser_change[5];
    QPushButton *btn_change[5];
    QLineEdit *update_input[5];
    QPushButton *update_confirm[5];
    QPushButton *uploadnew_image;
    QString profilephoto_image_path;
private:
    Ui::SellerWindow *ui;
};

#endif // SELLERWINDOW_H
