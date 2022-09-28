#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user)
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    myDb.setDatabaseName("./mydb.sqlite");
    myDb.open();
    ui->setupUi(this);
}

user::~user()
{
    delete ui;
}

void user::on_berlinPushButton_clicked(){}

void user::on_distanceAndFoodPushButton_clicked()
{
    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    ui->distanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->distanceTableView->setAlternatingRowColors(true);
    ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->foodTableView->setAlternatingRowColors(true);

    if (myDb.open())
    {
        queryModel = new QSqlQueryModel();
        queryModel ->setQuery("SELECT field1 AS 'STARTING CITY', field2 AS 'END CITY', field3 AS 'DISTANCE' FROM distanceSheet ORDER BY field1 DESC, field3");
        ui->distanceTableView->setModel(queryModel);

        queryModel -> setQuery("SELECT field1 AS 'CITY', field2 AS 'TRADITIONAL FOOD ITEM', field3 AS 'COST' FROM foodSheet ORDER BY field1 DESC, field3");
        ui->foodTableView->setModel(queryModel);
    }

}

