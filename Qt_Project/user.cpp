#include "user.h"
#include "ui_user.h"

user::user(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::user)
{
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

    myDb.setDatabaseName("C:/Users/zacal/CS1D/trip_planner_repo/Class_project_1/Qt_Project/Project.db");
    if (myDb.open()){
        qDebug().noquote() << "db found and open";
    }
    else{
        qDebug().noquote() << "db not found";
    }

    ui->distanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->distanceTableView->setAlternatingRowColors(true);
    ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->foodTableView->setAlternatingRowColors(true);

    if (myDb.open())
    {
        queryModel = new QSqlQueryModel();
        queryModel2 = new QSqlQueryModel();
        queryModel ->setQuery("SELECT distanceSheet.Starting_City as 'Starting City',distanceSheet.Ending_City as 'Ending City',distanceSheet.Distance FROM distanceSheet ORDER BY Distance");
        ui->distanceTableView->setModel(queryModel);

        queryModel2 -> setQuery("SELECT foodSheet.City,foodSheet.Traditional_Food_Item as 'Traditional Food Item',foodSheet.Cost FROM foodSheet ORDER BY foodSheet.City");
        ui->foodTableView->setModel(queryModel2);
    }

}

