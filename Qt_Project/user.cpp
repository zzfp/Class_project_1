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

void user::on_berlinPushButton_clicked(){
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

    QSqlQueryModel model;//model is readonly access to query results
    QSqlRecord record;//record accesses records returned by a query
    QSqlQuery query(myDb);
    QSqlQuery query2(myDb);
    query.prepare("SELECT COUNT(DISTINCT distanceSheet.Starting_City) FROM distanceSheet");
    query.exec(); //query must be active before being moved into the model

    model.setQuery(std::move(query));
    record = model.record(0); //sets the record to the first record in the query results
    int num_of_cities = record.value(0).toInt();
    int distance_travelled = 0;
    QString current_city = "Berlin";
    QString ex_cities = "'Berlin'";
    for (int i=0;i<num_of_cities;i++){
        query2.prepare("SELECT * FROM distanceSheet WHERE Starting_City=(:name) EXCEPT SELECT * FROM distanceSheet WHERE Ending_City = (:exclude_cities) ORDER BY Distance"); // queries can only be used once, need to refactor
        query2.bindValue(":name",current_city);
        query2.bindValue("exclude_cities",ex_cities);
        query2.exec();
        model.setQuery(std::move(query2));
        record = model.record(0);
        ex_cities +=  " OR Ending_City = '" + current_city + "' ";
        current_city = record.value(1).toString();
        distance_travelled += record.value(2).toInt();
        qDebug().noquote() << "loop: " << i;
    }
    qDebug().noquote() << ex_cities << distance_travelled;
}

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
        queryModel ->setQuery("SELECT distanceSheet.Starting_City as 'Starting City',distanceSheet.Ending_City as 'Ending City',distanceSheet.Distance FROM distanceSheet ORDER BY Starting_City");
        ui->distanceTableView->setModel(queryModel);

        queryModel2 -> setQuery("SELECT foodSheet.City,foodSheet.Traditional_Food_Item as 'Traditional Food Item',foodSheet.Cost FROM foodSheet ORDER BY foodSheet.City");
        ui->foodTableView->setModel(queryModel2);
    }

}

