#include "user.h"
#include "ui_user.h"
#include "euromap.h"

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

void user::on_berlinPushButton_clicked()
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

    QSqlQuery *prepQuery = new QSqlQuery(myDb);

    prepQuery -> exec("DELETE FROM Berlin_trip");
    ui->travelStackedWidget->setCurrentIndex(1);
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

    ui->distanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->distanceTableView->setAlternatingRowColors(true);

    ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->foodTableView->setAlternatingRowColors(true);

    if (myDb.open())
    {
        QSqlQuery *prepQuery = new QSqlQuery(myDb);
        queryModel = new QSqlQueryModel();
        queryModel2 = new QSqlQueryModel();
        prepQuery ->prepare("SELECT Starting_City, Ending_City, Distance FROM distanceSHEET WHERE Starting_City = :city ORDER BY Starting_City DESC, Distance");
        prepQuery ->bindValue(":city", "Rome");
        prepQuery ->exec();

        queryModel -> setQuery(std::move(*prepQuery));
        ui->distanceTableView->setModel(queryModel);

        queryModel2 -> setQuery("SELECT foodSheet.City,foodSheet.Traditional_Food_Item as 'Traditional Food Item',foodSheet.Cost FROM foodSheet ORDER BY foodSheet.City");
        ui->foodTableView->setModel(queryModel2);
    }

}

void user::on_beginTripPushButton_clicked()
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

    QSqlQuery *prepQuery = new QSqlQuery(myDb);
    QSqlQuery *insertQuery = new QSqlQuery(myDb);
    QSqlQueryModel* saleQryModel = new QSqlQueryModel();


    ui->currentCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->currentCityTableView->setAlternatingRowColors(true);

    insertQuery -> prepare("INSERT INTO totalAmountPerCity (City, totalAmountSpent) VALUES (:city, :totalAmountSpent)");
    insertQuery -> bindValue(":city", "Berlin");
    insertQuery -> bindValue(":totalAmountSpent", 0.0);
    insertQuery -> exec();

    prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
    prepQuery -> bindValue(":city", "Berlin");
    prepQuery -> exec();

    saleQryModel -> setQuery(std::move(*prepQuery));

    ui->currentCityTableView->setModel(saleQryModel);
    ui->travelStackedWidget->setCurrentIndex(2);
    ui->currentCityLineEdit->setText("Current City: Berlin");

}


void user::on_addItemPushButton_clicked()
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

    QSqlQuery *prepQuery = new QSqlQuery(myDb);
    QSqlQuery *activeQuery = new QSqlQuery(myDb);
    QSqlQuery *insertQuery = new QSqlQuery(myDb);

    QSqlQuery *totalSaleQuery = new QSqlQuery(myDb);
    QSqlQueryModel* receiptQryModel = new QSqlQueryModel();
    QSqlQueryModel* totalAmountSpentQryModel = new QSqlQueryModel();


    QString totalSaleString;
    QString item;
    QString city;
    int quantity;
    double total;
    double itemPrice;

    item = ui->enterItemLineEdit->text();
    quantity = ui->quantityItemLineEdit->text().toInt();

    prepQuery -> prepare("SELECT Cost FROM foodSheet WHERE Traditional_Food_Item = :item");
    prepQuery -> bindValue(":item", item);
    prepQuery -> exec();
    prepQuery -> next();

    itemPrice = prepQuery->value(0).toDouble();

    prepQuery -> prepare("SELECT City FROM foodSheet WHERE Traditional_Food_Item = :item");
    prepQuery -> bindValue(":item", item);
    prepQuery -> exec();
    prepQuery -> next();

    total = quantity * itemPrice;
    city = prepQuery -> value(0).toString();

    activeQuery->prepare("INSERT INTO travelSale (cityPurchased, item, itemPrice, quantity, totalSale) VALUES (:cityPurchased, :item, :itemPrice, :quantity, :totalSale);");
    activeQuery->bindValue(":cityPurchased", city);
    activeQuery->bindValue(":item", item);
    activeQuery->bindValue(":itemPrice", itemPrice);
    activeQuery->bindValue(":quantity", quantity);
    activeQuery->bindValue(":totalSale", total);
    activeQuery->exec();
    activeQuery->next();

    insertQuery->prepare("UPDATE totalAmountPerCity set totalAmountSpent = round((SELECT  SUM(totalSale) FROM travelSale WHERE cityPurchased = :city),2)  WHERE City = :city");
    insertQuery->bindValue(":city", city);
    insertQuery->exec();
    insertQuery->next();

    totalSaleQuery->exec("SELECT ROUND(SUM(totalSale)) FROM travelSale");
    totalSaleQuery->next();
    totalSaleString = totalSaleQuery->value(0).toString();
    totalSaleString = "Total Amount Spent: " + totalSaleString;

    totalAmountSpentQryModel->setQuery("SELECT City, totalAmountSpent FROM totalAmountPerCity");
    receiptQryModel->setQuery("SELECT cityPurchased, item, itemPrice, quantity, totalSale FROM travelSale");

    ui->receiptTabTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->receiptTabTableView->setAlternatingRowColors(true);
    ui->totalAmountPerCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->totalAmountPerCityTableView->setAlternatingRowColors(true);
    ui->receiptTabTableView->setModel(receiptQryModel);
    ui->totalAmountPerCityTableView->setModel(totalAmountSpentQryModel);
    ui->totalAmountSpentLabel->setText(totalSaleString);
}


void user::on_nextCityPushButton_clicked()
{

    if (count == nextCityCheck)
    {
       ui->travelStackedWidget->setCurrentIndex(0);
    }

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    QSqlQuery *prepQuery = new QSqlQuery(myDb);
    QSqlQuery *insertQuery = new QSqlQuery(myDb);
    QSqlQueryModel* saleQryModel = new QSqlQueryModel();

    QString city;
    QString cityLabel;
    QString currentDistance;

    prepQuery -> prepare("SELECT City, Distance_Travelled  FROM Berlin_Trip");
    prepQuery -> exec();
    prepQuery -> next();

    int i = count;
    while (i != 0)
    {
        prepQuery -> next();
        i--;

    }

    city = prepQuery -> value(0).toString();
    currentDistance = prepQuery -> value(1).toString();
    qDebug().noquote() << "values" << city;

    prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
    prepQuery -> bindValue(":city", city);
    prepQuery -> exec();

    saleQryModel -> setQuery(std::move(*prepQuery));

    cityLabel = "Current City: " + city;
    currentDistance = "Total Distance Traveled: " + currentDistance;


    insertQuery -> prepare("INSERT INTO totalAmountPerCity (City, totalAmountSpent) VALUES (:city, :totalAmountSpent)");
    insertQuery -> bindValue(":city", city);
    insertQuery -> bindValue(":totalAmountSpent", 0.0);
    insertQuery -> exec();


    ui->currentCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->currentCityTableView->setAlternatingRowColors(true);
    ui->currentCityTableView->setModel(saleQryModel);
    ui->currentCityLineEdit->setText(cityLabel);
    ui->totalDistanceTraveledLabel->setText(currentDistance);

    count++;
}


void user::on_searchFoodPushButton_clicked()
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

    QString searchCity;
    QSqlQuery *prepQuery = new QSqlQuery(myDb);
    QSqlQueryModel* foodQryModel = new QSqlQueryModel();
    \
    searchCity = ui->searchFoodItemLineEdit->text();
    qDebug().noquote() << "values" << searchCity;
    prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
    prepQuery -> bindValue(":city", searchCity);
    prepQuery -> exec();

    foodQryModel -> setQuery(std::move(*prepQuery));
    ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->foodTableView->setAlternatingRowColors(true);
    ui->foodTableView->setModel(foodQryModel);

}

void user::on_customTripButton_clicked()
{
    customWindow = new customTrip;
    customWindow->show();
}


void user::on_berlin11CitiesPushButton_clicked()
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

    QSqlQueryModel* qryModel = new QSqlQueryModel();

    EuroMap map;
    map.full_map_from_city("Berlin", 11 );
    nextCityCheck = 11;

    ui->tripTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tripTableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
    ui->tripTableView->setModel(qryModel);
}


void user::on_parisCustomTripPushButton_clicked()
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

    QSqlQuery *prepQuery = new QSqlQuery(myDb);

    prepQuery -> exec("DELETE FROM Berlin_trip");
    ui->travelStackedWidget->setCurrentIndex(3);
}


void user::on_addParisCitiesPushButton_clicked()
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

    QSqlQueryModel* qryModel = new QSqlQueryModel();

    int amountOfCities;
    amountOfCities = ui->numberOfCitiesLineEdit->text().toInt();

    EuroMap map;
    map.full_map_from_city("Paris", amountOfCities);
    nextCityCheck = amountOfCities;

    ui->parisTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->parisTableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
    ui->parisTableView->setModel(qryModel);
}


void user::on_parisBeginTrip_clicked()
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

    QSqlQuery *prepQuery = new QSqlQuery(myDb);
    QSqlQuery *insertQuery = new QSqlQuery(myDb);
    QSqlQueryModel* saleQryModel = new QSqlQueryModel();


    ui->currentCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->currentCityTableView->setAlternatingRowColors(true);

    insertQuery -> prepare("INSERT INTO totalAmountPerCity (City, totalAmountSpent) VALUES (:city, :totalAmountSpent)");
    insertQuery -> bindValue(":city", "Paris");
    insertQuery -> bindValue(":totalAmountSpent", 0.0);
    insertQuery -> exec();

    prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
    prepQuery -> bindValue(":city", "Paris");
    prepQuery -> exec();

    saleQryModel -> setQuery(std::move(*prepQuery));

    ui->currentCityTableView->setModel(saleQryModel);
    ui->travelStackedWidget->setCurrentIndex(2);
    ui->currentCityLineEdit->setText("Current City: Paris");
}

