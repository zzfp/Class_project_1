#ifndef USER_H
#define USER_H

#include <QMainWindow>
#include <QListWidget>
#include <QWidget>
#include <QtSql>
#include <QSqlDatabase>

namespace Ui {
class user;
}

class user : public QMainWindow
{
    Q_OBJECT

public:
    explicit user(QWidget *parent = nullptr);
    ~user();

private slots:
    void on_berlinPushButton_clicked();

    void on_distanceAndFoodPushButton_clicked();

    void on_beginTripPushButton_clicked();

    void on_addItemPushButton_clicked();

    void on_nextCityPushButton_clicked();
    void on_searchFoodPushButton_clicked();

    void on_Test_clicked();

private:
    Ui::user *ui;
    QSqlDatabase myDb;
    QSqlQueryModel *queryModel;
    QSqlQueryModel *queryModel2;
    int count = 1;
};

#endif // USER_H
