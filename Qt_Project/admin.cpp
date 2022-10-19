#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>

Admin::Admin(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::Admin)
{
   ui->setupUi(this);
}

Admin::~Admin()
{
   delete ui;
}


void Admin::on_addCityButton_clicked()
{
   QString startCity = ui->cityLineEdit->text();
   QString endingCity = ui->endingCityLineEdit->text();
   QString distance = ui->kilometerLineEdit->text();

   if (startCity == "" || endingCity == "" || distance == "")
   {
       QMessageBox::warning(this, "Empty field", "One of your fields is empty");
   }

   QSqlQuery query;
   QSqlQueryModel* qryModel = new QSqlQueryModel();

   query.prepare("INSERT INTO distanceSheet(Starting_City, Ending_City, Distance) VALUES (:Starting, :Ending, :Distance)");
   query.bindValue(":Starting", startCity);
   query.bindValue(":Ending", endingCity);
   query.bindValue(":Distance", distance);

   if (!query.exec() )
   {
        QMessageBox::warning(this, "Query Error", "Query not executed");
   }
   else
   {
        QMessageBox::information(this, "City Successfully Added", "Success");

   }

   ui->distanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   ui->distanceTableView->setAlternatingRowColors(true);

   qryModel->setQuery("SELECT Starting_City, Ending_City, Distance FROM distanceSHEET ORDER BY Starting_City DESC, Distance");
   ui->distanceTableView->setModel(qryModel);

}


void Admin::on_addFoodButton_clicked()
{
    QString city = ui->cityLineEdit2->text();
    QString food = ui->foodLineEdit->text();
    QString cost = ui->costLineEdit->text();

    if (city == "" || food == "" || cost == "")
    {
        QMessageBox::warning(this, "Empty field", "One of your fields is empty");
    }

    QSqlQuery query;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    query.prepare("INSERT INTO foodSheet(City, Traditional_Food_Item, Cost) VALUES (:City, :Food, :Cost)");
    query.bindValue(":City", city);
    query.bindValue(":Food", food);
    query.bindValue(":Cost", cost);

    if (!query.exec() )
    {
          QMessageBox::warning(this, "Query Error", "Query not executed");
    }
    else
    {
          QMessageBox::information(this, "City Successfully Added", "Success");
    }

    ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->foodTableView->setAlternatingRowColors(true);

    qryModel -> setQuery("SELECT foodSheet.City,foodSheet.Traditional_Food_Item as 'Traditional Food Item',foodSheet.Cost FROM foodSheet ORDER BY foodSheet.City");

    ui->foodTableView->setModel(qryModel);

}

void Admin::on_initStartingCitiesPushButton_clicked()
{
    QFile file("./EuropeanDistances.txt");
    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }
    myDb.open();

    QTextStream inFile(&file);
    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qCritical()<<"please make sure that you put the .txt files in debug folder!";
        qCritical()<<file.errorString();
        return;
    }

    QString startString;
    QString endString;
    QString distanceString;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    while(!inFile.atEnd())
    {
        QSqlQuery query;
        query.prepare("INSERT INTO distanceSheet(Starting_City, Ending_City, Distance) VALUES (:Starting, :Ending, :Distance)");

        startString = inFile.readLine();
        endString = inFile.readLine();
        distanceString = inFile.readLine();

        query.bindValue(":Starting", startString);
        query.bindValue(":Ending", endString);
        query.bindValue(":Distance", distanceString.toInt());
        qDebug() << startString << endString << distanceString;
        query.exec();
    }
    file.close();


    ui->distanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->distanceTableView->setAlternatingRowColors(true);

    qryModel->setQuery("SELECT Starting_City, Ending_City, Distance FROM distanceSHEET ORDER BY Starting_City DESC, Distance");
    ui->distanceTableView->setModel(qryModel);

}


void Admin::on_initNewCitiesPUshButton_clicked()
{
    QFile file("./NewCitiesUpload.txt");
    QTextStream inFile(&file);

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }
    QSqlQuery *newTableQuery = new QSqlQuery(myDb);
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    myDb.open();

    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
        {
            qCritical()<<"please make sure that you put the .txt files in debug folder!";
            qCritical()<<file.errorString();
            return;
        }

        QString startString;
        QString endString;
        QString distanceString;

        while(!inFile.atEnd())
        {
             QSqlQuery query;
             query.prepare("INSERT INTO distanceSheet(Starting_City, Ending_City, Distance) VALUES (:Starting, :Ending, :Distance)");

             startString = inFile.readLine();
             endString = inFile.readLine();
             distanceString = inFile.readLine();

             query.bindValue(":Starting", startString);
             query.bindValue(":Ending", endString);
             query.bindValue(":Distance", distanceString.toInt());
             qDebug() << startString << endString << distanceString;
             query.exec();

         }
         file.close();

         newTableQuery->exec("CREATE TABLE newDistanceTable as SELECT Starting_City, Ending_City, Distance FROM distanceSheet ORDER BY Starting_City DESC, Distance");
         newTableQuery->exec("DROP TABLE distanceSheet");
         newTableQuery->exec("ALTER TABLE newDistanceTable RENAME To distanceSheet");

         ui->distanceTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
         ui->distanceTableView->setAlternatingRowColors(true);

         qryModel->setQuery("SELECT Starting_City, Ending_City, Distance FROM distanceSHEET ORDER BY Starting_City DESC, Distance");
         ui->distanceTableView->setModel(qryModel);

}


void Admin::on_InitializeStartingFoodsPushButton_clicked()
{
    QFile file("./FoodsTextFile.txt");
    QTextStream inFile(&file);

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qCritical()<<"please make sure that you put the .txt files in debug folder!";
        qCritical()<<file.errorString();
        return;
    }

    QString cityString;
    QString foodString;
    QString costString;
    double costDouble;
    QSqlQueryModel* qryModel = new QSqlQueryModel();

    while(!inFile.atEnd())
    {
         QSqlQuery query;
         query.prepare("INSERT INTO foodSheet(City, Traditional_Food_Item, Cost) VALUES (:City, :Food, :Cost)");

         cityString = inFile.readLine();
         foodString = inFile.readLine();
         costString = inFile.readLine();
         costDouble = costString.toDouble();

         query.bindValue(":City", cityString);
         query.bindValue(":Food", foodString);
         query.bindValue(":Cost", costDouble);
         qDebug() << cityString << foodString << costDouble;
         query.exec();

     }
     file.close();

     ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     ui->foodTableView->setAlternatingRowColors(true);

     qryModel -> setQuery("SELECT foodSheet.City,foodSheet.Traditional_Food_Item as 'Traditional Food Item',foodSheet.Cost FROM foodSheet ORDER BY foodSheet.City");

     ui->foodTableView->setModel(qryModel);
}


void Admin::on_InitializeNewFoodsPushButton_clicked()
{
    QFile file("./NewFoodsTextFile.txt");
    QTextStream inFile(&file);

    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }
    QSqlQuery *newTableQuery = new QSqlQuery(myDb);
    QSqlQueryModel* qryModel = new QSqlQueryModel();
    myDb.open();

    QString cityString;
    QString foodString;
    QString costString;
    double costDouble;

    while(!inFile.atEnd())
    {
         QSqlQuery query;
         query.prepare("INSERT INTO foodSheet(City, Traditional_Food_Item, Cost) VALUES (:City, :Food, :Cost)");

         cityString = inFile.readLine();
         foodString = inFile.readLine();
         costString = inFile.readLine();
         costDouble = costString.toDouble();

         query.bindValue(":City", cityString);
         query.bindValue(":Food", foodString);
         query.bindValue(":Cost", costDouble);
         qDebug() << cityString << foodString << costDouble;
         query.exec();

     }
     file.close();


     newTableQuery->exec("CREATE TABLE newFoodTable as SELECT City, Traditional_Food_Item, Cost FROM foodSheet ORDER BY City");
     newTableQuery->exec("DROP TABLE foodSheet");
     newTableQuery->exec("ALTER TABLE newDistanceTable RENAME To foodSheet");

     ui->foodTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
     ui->foodTableView->setAlternatingRowColors(true);

     qryModel -> setQuery("SELECT foodSheet.City,foodSheet.Traditional_Food_Item as 'Traditional Food Item',foodSheet.Cost FROM foodSheet ORDER BY foodSheet.City");

     ui->foodTableView->setModel(qryModel);
}


void Admin::on_deleteTablePushButton_clicked()
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

    deleteQuery->exec("DELETE FROM Berlin_trip");
    deleteQuery->exec("DELETE FROM Custom_Trip");
    deleteQuery->exec("DELETE FROM distanceSheet");
    deleteQuery->exec("DELETE FROM foodSheet");
    deleteQuery->exec("DELETE FROM totalAmountPerCity");
    deleteQuery->exec("DELETE FROM travelSale");
}


void Admin::on_userWindowPushButton_clicked()
{
    userWindow = new class::user;
    userWindow->show();
}

