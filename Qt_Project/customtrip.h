#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H

#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSql>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <vector>
#include <QStandardItemModel>
#include "euromap.h"

namespace Ui {
class customTrip;
}

class customTrip : public QWidget
{
    Q_OBJECT

public:
    explicit customTrip(QWidget *parent = nullptr);
    ~customTrip();

private slots:
    void on_cancelButton_clicked();

    void on_acceptButton_clicked();

    void on_finalTripButton_clicked();

private:
    std::vector<QString> visited;
    Ui::customTrip *ui;
    QSqlDatabase myDb;
};

#endif // CUSTOMTRIP_H
