#include "mainwindow.h"

#include <QApplication>
#include "mainwindowlogin.h"
#include "mainwindowregister.h"
#include "main_.h"


#include <QSql>
#include <QSqlDatabase>
#include <QDebug>
#include <QtSql/QSqlError>
#include <QtPlugin>

#include "mainwindowhome.h"

#include <QImageReader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QImageReader::setAllocationLimit(256 * 1024 * 1024);
    update_users_date();
    products_data();
    update_sellers_data();

    MainWindow w;
    w.show();

    return a.exec();
}
