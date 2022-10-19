#ifndef ADMIN_H
#define ADMIN_H

#include "user.h"
#include <QMainWindow>
#include <QListWidget>
#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>


namespace Ui {
class Admin;
}

class Admin : public QMainWindow
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:

    void on_addCityButton_clicked();

    void on_addFoodButton_clicked();

    void on_initStartingCitiesPushButton_clicked();

    void on_initNewCitiesPUshButton_clicked();

    void on_InitializeStartingFoodsPushButton_clicked();

    void on_InitializeNewFoodsPushButton_clicked();

    void on_deleteTablePushButton_clicked();

    void on_userWindowPushButton_clicked();

private:
    Ui::Admin *ui;
    QSqlDatabase myDb;
    user* userWindow = NULL;
};

#endif // ADMIN_H
