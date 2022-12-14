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

    void on_customTripButton_clicked();

    void on_berlin11CitiesPushButton_clicked();

    void on_parisCustomTripPushButton_clicked();

    void on_addParisCitiesPushButton_clicked();

    void on_parisBeginTrip_clicked();

    void on_addCustomCityPushButton_clicked();

    void on_finalizeTripCustomCityPushButton_clicked();

    void on_beginTripCustomCityPushButton_clicked();

    void on_berlin13CitiesPushButton_clicked();

private:
    Ui::user *ui;
    QSqlDatabase myDb;
    QSqlQueryModel *queryModel;
    QSqlQueryModel *queryModel2;

    int count = 1;
    int addCity = 0;
    int nextCityCheck;
    bool notClicked = true;
    bool parisNotClicked = true;
    bool customTripNotClicked = true;
};

#endif // USER_H
