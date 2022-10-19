#include "user.h"
#include "ui_user.h"
#include "euromap.h"
#include "customtripmap.h"

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

        ui->searchFoodItemLineEdit->setText("");
        ui->enterItemLineEdit->setText("");
        ui->quantityItemLineEdit->setText("");
        ui->numberOfCitiesLineEdit->setText("");
        ui->searchErrorLabel->setVisible(false);
    }

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

    QSqlQuery *deleteQuery = new QSqlQuery(myDb);
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    deleteQuery->exec("DELETE FROM Berlin_trip");
    deleteQuery->exec("DELETE FROM totalAmountPerCity");
    deleteQuery->exec("DELETE FROM travelSale");

    ui->searchFoodItemLineEdit->setText("");
    ui->enterItemLineEdit->setText("");
    ui->quantityItemLineEdit->setText("");
    ui->numberOfCitiesLineEdit->setText("");

    ui->tripTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tripTableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
    ui->tripTableView->setModel(qryModel);

    ui->travelStackedWidget->setCurrentIndex(1);
    count = 1; //setting next city check to 1;
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

    notClicked = false;
    ui->validCityErrorBerlin->setVisible(false);

    EuroMap map;
    map.full_map_from_city("Berlin", 11 );
    nextCityCheck = 11;

    ui->tripTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tripTableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
    ui->tripTableView->setModel(qryModel);
}

void user::on_berlin13CitiesPushButton_clicked()
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
    QSqlQuery searchQuery(myDb);
    QSqlQueryModel searchQryModel;

    searchQuery.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
    searchQryModel.setQuery(std::move(searchQuery));

    if(searchQryModel.rowCount() != 13)
    {
        ui->validCityErrorBerlin->setVisible(true);
        ui->validCityErrorBerlin->setText("13 Cities dont exists in table REQUEST ADMIN HELP");
    }
    else
    {
        notClicked = false;
        ui->validCityErrorBerlin->setVisible(false);

        EuroMap map;
        map.full_map_from_city("Berlin", 13 );
        nextCityCheck = 13;

        ui->tripTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tripTableView->setAlternatingRowColors(true);

        qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
        ui->tripTableView->setModel(qryModel);
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

    if (notClicked)
    {
        ui->validCityErrorBerlin->setVisible(true);
        ui->validCityErrorBerlin->setText("Click on 11 Cities or 13 Cities");

    }
    else
    {

        QSqlQuery *prepQuery = new QSqlQuery(myDb);
        QSqlQuery *insertQuery = new QSqlQuery(myDb);
        QSqlQueryModel* saleQryModel = new QSqlQueryModel();
        QSqlQueryModel* receiptQryModel = new QSqlQueryModel();
        QSqlQueryModel* totalAmountSpentQryModel = new QSqlQueryModel();

        ui->currentCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->currentCityTableView->setAlternatingRowColors(true);

        insertQuery -> prepare("INSERT INTO totalAmountPerCity (City, totalAmountSpent) VALUES (:city, :totalAmountSpent)");
        insertQuery -> bindValue(":city", "Berlin");
        insertQuery -> bindValue(":totalAmountSpent", 0.0);
        insertQuery -> exec();

        prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
        prepQuery -> bindValue(":city", "Berlin");
        prepQuery -> exec();

        totalAmountSpentQryModel->setQuery("SELECT City, totalAmountSpent FROM totalAmountPerCity");
        receiptQryModel->setQuery("SELECT cityPurchased, item, itemPrice, quantity, totalSale FROM travelSale");

        ui->receiptTabTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->receiptTabTableView->setAlternatingRowColors(true);

        ui->totalAmountPerCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->totalAmountPerCityTableView->setAlternatingRowColors(true);

        ui->totalDistanceTraveledLabel->setText("Total Distance Traveled: 0");
        ui->totalAmountSpentLabel->setText("Total Amount Spent: 0");

        ui->receiptTabTableView->setModel(receiptQryModel);
        ui->totalAmountPerCityTableView->setModel(totalAmountSpentQryModel);

        saleQryModel -> setQuery(std::move(*prepQuery));

        ui->currentCityTableView->setModel(saleQryModel);
        ui->travelStackedWidget->setCurrentIndex(2);
        ui->currentCityLineEdit->setText("Current City: Berlin");
    }


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

    totalSaleQuery->exec("SELECT ROUND((SUM(totalSale)), 2) AS ROUNDVALUE FROM travelSale");
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
       notClicked = true;
       parisNotClicked = true;
       customTripNotClicked = true;
       count = 1;
       addCity = 0;
       ui->searchErrorLabel->setVisible(false);
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
    QSqlQueryModel* totalAmountSpentQryModel = new QSqlQueryModel();

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

    totalAmountSpentQryModel->setQuery("SELECT City, totalAmountSpent FROM totalAmountPerCity");

    ui->totalAmountPerCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->totalAmountPerCityTableView->setAlternatingRowColors(true);
    ui->currentCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->currentCityTableView->setAlternatingRowColors(true);

    ui->totalAmountPerCityTableView->setModel(totalAmountSpentQryModel);
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
    QSqlRecord record;
    QSqlQuery *prepQuery = new QSqlQuery(myDb);
    QSqlQuery searchQuery(myDb);
    QSqlQueryModel* foodQryModel = new QSqlQueryModel();
    QSqlQueryModel searchQryModel;

    bool confirmString = false;

    ui->searchErrorLabel->setVisible(false);
    searchCity = ui->searchFoodItemLineEdit->text();

    searchQuery.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
    searchQryModel.setQuery(std::move(searchQuery));
    int i = 0;

    while (i < searchQryModel.rowCount() && !confirmString)
    {
        record = searchQryModel.record(i);
        if (searchCity == record.value(0).toString())
        {
            confirmString = true;
        }
        i++;
    }


    if (confirmString == true)
    {
        qDebug().noquote() << "values" << searchCity;
        prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
        prepQuery -> bindValue(":city", searchCity);
        prepQuery -> exec();

        foodQryModel -> setQuery(std::move(*prepQuery));
        ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->foodTableView->setAlternatingRowColors(true);
        ui->foodTableView->setModel(foodQryModel);
    }
    else
    {
        ui->searchErrorLabel->setVisible(true);
        ui->searchErrorLabel->setText("Invalid City: Enter New City");

    }

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

    QSqlQuery *deleteQuery = new QSqlQuery(myDb);
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    deleteQuery->exec("DELETE FROM Berlin_trip");
    deleteQuery->exec("DELETE FROM totalAmountPerCity");
    deleteQuery->exec("DELETE FROM travelSale");

    ui->searchFoodItemLineEdit->setText("");
    ui->enterItemLineEdit->setText("");
    ui->quantityItemLineEdit->setText("");
    ui->numberOfCitiesLineEdit->setText("");

    ui->parisTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->parisTableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
    ui->parisTableView->setModel(qryModel);

    ui->travelStackedWidget->setCurrentIndex(3);
    count = 1; //setting next city check to 1;
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
    QSqlQuery searchQuery(myDb);
    QSqlQueryModel searchQryModel;

    int amountOfCities;
    amountOfCities = ui->numberOfCitiesLineEdit->text().toInt();

    searchQuery.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
    searchQryModel.setQuery(std::move(searchQuery));

    if (amountOfCities > searchQryModel.rowCount())
    {
        ui->parisWrongError->setVisible(true);
        ui->parisWrongError->setText("Invalid amount of Cities, TOO MANY: please enter an appropriate amount");
    }
    else if (amountOfCities > 0)
    {
        parisNotClicked = false;
        ui->parisWrongError->setVisible(false);

        EuroMap map;
        QString paris = "Paris";
        map.full_map_from_city(paris, amountOfCities);
        nextCityCheck = amountOfCities;

        ui->parisTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->parisTableView->setAlternatingRowColors(true);

        qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
        ui->parisTableView->setModel(qryModel);
    }
    else
    {
        ui->parisWrongError->setVisible(true);
        ui->parisWrongError->setText("Invalid amount of Cities, TOO LITTLE: please enter an appropriate amount");
    }


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

    if (parisNotClicked)
    {
        ui->parisWrongError->setVisible(true);
        ui->parisWrongError->setText("No amount entered, Please enter appropriate amount");
    }
    else
    {
        QSqlQuery *prepQuery = new QSqlQuery(myDb);
        QSqlQuery *insertQuery = new QSqlQuery(myDb);
        QSqlQueryModel* saleQryModel = new QSqlQueryModel();
        QSqlQueryModel* receiptQryModel = new QSqlQueryModel();
        QSqlQueryModel* totalAmountSpentQryModel = new QSqlQueryModel();

        ui->currentCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->currentCityTableView->setAlternatingRowColors(true);

        insertQuery -> prepare("INSERT INTO totalAmountPerCity (City, totalAmountSpent) VALUES (:city, :totalAmountSpent)");
        insertQuery -> bindValue(":city", "Paris");
        insertQuery -> bindValue(":totalAmountSpent", 0.0);
        insertQuery -> exec();

        prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
        prepQuery -> bindValue(":city", "Paris");
        prepQuery -> exec();

        totalAmountSpentQryModel->setQuery("SELECT City, totalAmountSpent FROM totalAmountPerCity");
        receiptQryModel->setQuery("SELECT cityPurchased, item, itemPrice, quantity, totalSale FROM travelSale");

        ui->receiptTabTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->receiptTabTableView->setAlternatingRowColors(true);

        ui->totalAmountPerCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->totalAmountPerCityTableView->setAlternatingRowColors(true);

        ui->totalDistanceTraveledLabel->setText("Total Distance Traveled: 0");
        ui->totalAmountSpentLabel->setText("Total Amount Spent: 0");

        ui->receiptTabTableView->setModel(receiptQryModel);
        ui->totalAmountPerCityTableView->setModel(totalAmountSpentQryModel);

        saleQryModel -> setQuery(std::move(*prepQuery));

        ui->currentCityTableView->setModel(saleQryModel);
        ui->travelStackedWidget->setCurrentIndex(2);
        ui->currentCityLineEdit->setText("Current City: Paris");
    }

}

void user::on_customTripButton_clicked()
{
       QSqlQueryModel model;
       QSqlQuery query(myDb);
       QSqlQuery tripQuery(myDb);

       QSqlQueryModel* cityModel = new QSqlQueryModel();
       QSqlQueryModel* cityPlanModel = new QSqlQueryModel();
       QSqlQuery *deleteQuery = new QSqlQuery(myDb);

       deleteQuery->exec("DELETE FROM Berlin_trip");
       deleteQuery->exec("DELETE FROM totalAmountPerCity");
       deleteQuery->exec("DELETE FROM Custom_Trip");
       deleteQuery->exec("DELETE FROM travelSale");

       ui->searchFoodItemLineEdit->setText("");
       ui->enterItemLineEdit->setText("");
       ui->quantityItemLineEdit->setText("");
       ui->numberOfCitiesLineEdit->setText("");

       ui->citiesTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       ui->citiesTableView->setAlternatingRowColors(true);
       ui->customTripTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
       ui->customTripTableView->setAlternatingRowColors(true);

       query.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
       tripQuery.exec("SELECT City FROM Custom_Trip");


       cityModel->setQuery(std::move(query));
       cityPlanModel->setQuery(std::move(tripQuery));

       ui->citiesTableView->setModel(cityModel);
       ui->customTripTableView->setModel(cityPlanModel);

       QSqlRecord record;
       for(int i=0;i<cityModel->rowCount();i++)
       {
           record = cityModel->record(i);
           ui->citiesComboBox->addItem(record.value(0).toString());
       }

       ui->travelStackedWidget->setCurrentIndex(4);
       count = 1; //setting next city check to 1;
       addCity = 0;//resetting the addcity count;
}

void user::on_addCustomCityPushButton_clicked()
{
    QString city;

    QSqlQuery *addCityQuery = new QSqlQuery(myDb);
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    if (ui->citiesComboBox->count() != 0)
    {
        city = ui->citiesComboBox->currentText();

        addCityQuery->prepare("INSERT INTO Custom_Trip (City) VALUES (:city)");
        addCityQuery->bindValue(":city", city);
        addCityQuery->exec();

        qryModel->setQuery("SELECT City FROM Custom_Trip");

        ui->customTripTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->customTripTableView->setAlternatingRowColors(true);
        ui->customTripTableView->setModel(qryModel);

        ui->citiesComboBox->removeItem(ui->citiesComboBox->currentIndex());
        addCity++;
        ui->customTripErrorLabel->setVisible(false);
    }
    else
    {
        ui->customTripErrorLabel->setVisible(true);
        ui->customTripErrorLabel->setText("No More Cities to Add: Press Finalize Trip and Begin");
    }


}


void user::on_finalizeTripCustomCityPushButton_clicked()
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

    if (addCity != 0)
    {
        QSqlQuery *addQuery = new QSqlQuery(myDb);
        QSqlQuery *startingCityQuery = new QSqlQuery(myDb);
        QSqlQueryModel* qryModel = new QSqlQueryModel();
        QString startingCity;

        startingCityQuery->exec("SELECT City FROM Custom_Trip");
        startingCityQuery->next();
        startingCity = startingCityQuery->value(0).toString();

        if (addCity == 1)
        {
              addQuery->prepare("INSERT INTO Berlin_Trip VALUES ((:City),(:distance))");
              addQuery->bindValue(":City", startingCity);
              addQuery->bindValue(":distance", 0);
              addQuery->exec();
              nextCityCheck = addCity;
        }
        else
        {
            customTripMap map;
            map.fullMap(startingCity, addCity);
            nextCityCheck = addCity;
        }
        ui->customTripTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->customTripTableView->setAlternatingRowColors(true);
        qryModel->setQuery("SELECT City, Distance_Travelled AS'Total Distance Traveled' FROM Berlin_trip");
        ui->customTripTableView->setModel(qryModel);
        customTripNotClicked = false;
        ui->customTripErrorLabel->setVisible(false);

    }
    else
    {
        ui->customTripErrorLabel->setVisible(true);
        ui->customTripErrorLabel->setText("No City Entered: Please Enter a City");
    }
}


void user::on_beginTripCustomCityPushButton_clicked()
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

    if (customTripNotClicked)
    {
        ui->customTripErrorLabel->setVisible(true);
        ui->customTripErrorLabel->setText("No City Entered: Please Enter a City");

    }
    else
    {
        QSqlQuery *prepQuery = new QSqlQuery(myDb);
        QSqlQuery *insertQuery = new QSqlQuery(myDb);
        QSqlQueryModel* saleQryModel = new QSqlQueryModel();
        QSqlQuery *startingCityQuery = new QSqlQuery(myDb);
        QSqlQueryModel* receiptQryModel = new QSqlQueryModel();
        QSqlQueryModel* totalAmountSpentQryModel = new QSqlQueryModel();

        QString startingCity;

        startingCityQuery->exec("SELECT City FROM Custom_Trip");
        startingCityQuery->next();
        startingCity = startingCityQuery->value(0).toString();


        ui->currentCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->currentCityTableView->setAlternatingRowColors(true);

        insertQuery -> prepare("INSERT INTO totalAmountPerCity (City, totalAmountSpent) VALUES (:city, :totalAmountSpent)");
        insertQuery -> bindValue(":city", startingCity);
        insertQuery -> bindValue(":totalAmountSpent", 0.0);
        insertQuery -> exec();

        prepQuery -> prepare("SELECT City, Traditional_Food_Item, Cost From foodSheet WHERE City = :city");
        prepQuery -> bindValue(":city", startingCity);
        prepQuery -> exec();

        totalAmountSpentQryModel->setQuery("SELECT City, totalAmountSpent FROM totalAmountPerCity");
        receiptQryModel->setQuery("SELECT cityPurchased, item, itemPrice, quantity, totalSale FROM travelSale");

        ui->receiptTabTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->receiptTabTableView->setAlternatingRowColors(true);

        ui->totalAmountPerCityTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->totalAmountPerCityTableView->setAlternatingRowColors(true);

        ui->totalDistanceTraveledLabel->setText("Total Distance Traveled: 0");
        ui->totalAmountSpentLabel->setText("Total Amount Spent: 0");

        ui->receiptTabTableView->setModel(receiptQryModel);
        ui->totalAmountPerCityTableView->setModel(totalAmountSpentQryModel);

        saleQryModel -> setQuery(std::move(*prepQuery));

        ui->currentCityTableView->setModel(saleQryModel);
        ui->travelStackedWidget->setCurrentIndex(2);
        ui->currentCityLineEdit->setText("Current City: " + startingCity);
    }

}
