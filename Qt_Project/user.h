#ifndef USER_H
#define USER_H

#include <QMainWindow>
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

private:
    Ui::user *ui;
};

#endif // USER_H
