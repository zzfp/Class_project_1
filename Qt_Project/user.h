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

private:
    Ui::user *ui;
    QSqlDatabase myDb;
    QSqlQueryModel *queryModel;
};

#endif // USER_H
