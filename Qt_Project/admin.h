#ifndef ADMIN_H
#define ADMIN_H

#include <QMainWindow>
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

   // void on_cityTable_cellActivated(int row, int column);

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
