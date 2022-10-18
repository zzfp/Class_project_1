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
    void refreshCityTable();

private slots:

    void on_addCityButton_clicked();
    void on_uploadFile_clicked();

   // void on_cityTable_cellActivated(int row, int column);

    void on_addFoodButton_clicked();

    void on_uploadFile2_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
