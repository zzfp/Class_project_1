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
    QSqlDatabase myDb;

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    QSqlRecord record;
    QSqlQuery searchQuery(myDb);
    QSqlQueryModel searchQryModel;

    QString city = ui->cityLineEdit2->text();
    QString food = ui->foodLineEdit->text();
    std::string quantityString;
    QString cost = ui->costLineEdit->text();
    bool confirmInt;
    bool confirmString = false;

    quantityString = ui->costLineEdit->text().toStdString();

    if (city == "" || food == "" || cost == "")
    {
        QMessageBox::warning(this, "Empty field", "One of your fields is empty");
    }
    else
    {
        for (char const ch : quantityString)
        {
            if(std::isdigit(ch) == 0)
            {
                confirmInt = false;
            }
            else
            {
                confirmInt = true;
            }
        }
        if (confirmInt == true)
        {
            searchQuery.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
            searchQryModel.setQuery(std::move(searchQuery));
            int i = 0;

            while (i < searchQryModel.rowCount() && !confirmString)
            {
                record = searchQryModel.record(i);
                if (city == record.value(0).toString())
                {
                    confirmString = true;
                }
                i++;
            }

            if (confirmString == true)
            {
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
            else
            {
                QMessageBox::warning(this, "NOT A CITY", "enter a city");
            }

        }
        else
        {
            QMessageBox::warning(this, "NOT AN INT", "enter an int into quantity");
        }
    }
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
    myDb.open();

    if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
    {
        qCritical()<<"please make sure that you put the .txt files in debug folder!";
        qCritical()<<file.errorString();
        return;
    }

    QSqlQuery *newTableQuery = new QSqlQuery(myDb);
    QSqlQueryModel* qryModel = new QSqlQueryModel();

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
     newTableQuery->exec("ALTER TABLE newFoodTable RENAME To foodSheet");

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


void Admin::on_editFoodButton_clicked()
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

    QSqlRecord record;
    QSqlQuery searchQuery(myDb);
    QSqlQueryModel searchQryModel;
    std::string quantityString;

    QString city = ui->cityLineEdit2->text();
    QString food = ui->foodLineEdit->text();
    QString cost = ui->costLineEdit->text();

    bool confirmInt;
    bool confirmString = false;

    quantityString = ui->costLineEdit->text().toStdString();

    if (city == "" || food == "" || cost == "")
    {
        QMessageBox::warning(this, "Empty field", "One of your fields is empty");
    }
    else
    {
        for (char const ch : quantityString)
        {
            if(std::isdigit(ch) == 0)
            {
                confirmInt = false;
            }
            else
            {
                confirmInt = true;
            }
        }
        if(confirmInt == true)
        {

            searchQuery.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
            searchQryModel.setQuery(std::move(searchQuery));
            int i = 0;

            while (i < searchQryModel.rowCount() && !confirmString)
            {
                record = searchQryModel.record(i);
                if (city == record.value(0).toString())
                {
                    confirmString = true;
                }
                i++;
            }

            if (confirmString == true)
            {
                QSqlQuery query;
                QSqlQueryModel* qryModel = new QSqlQueryModel();

                query.prepare("UPDATE foodSheet SET Cost = (:Cost) WHERE City = (:City) AND Traditional_Food_Item = (:Food) ");
                query.bindValue(":City", city);
                query.bindValue(":Food", food);
                query.bindValue(":Cost", cost);
                query.exec();

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
            else
            {
                QMessageBox::warning(this, "NOT A CITY", "enter a city");
            }
        }
        else
        {
             QMessageBox::warning(this, "NOT AN INT", "enter an int into quantity");
        }
    }
}


void Admin::on_deleteFood_clicked()
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

    QSqlRecord record;
    QSqlQuery searchQuery(myDb);
    QSqlQueryModel searchQryModel;

    QSqlRecord record2;
    QSqlQuery searchQuery2(myDb);
    QSqlQueryModel searchQryModel2;

    QString city = ui->cityLineEdit2->text();
    QString food = ui->foodLineEdit->text();
    bool confirmCity = false;
    bool confirmFood = false;

    if (city == "" || food == "")
    {
        QMessageBox::warning(this, "Empty field", "One of your fields is empty");
    }
    else
    {
        searchQuery.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
        searchQryModel.setQuery(std::move(searchQuery));
        int i = 0;

        while (i < searchQryModel.rowCount() && !confirmCity)
        {
            record = searchQryModel.record(i);
            if (city == record.value(0).toString())
            {
                confirmCity = true;
            }
            i++;
        }

        if (confirmCity == true)
        {
            searchQuery2.exec("SELECT DISTINCT Traditional_Food_Item FROM foodSheet");
            searchQryModel2.setQuery(std::move(searchQuery2));
            int j = 0;

            while (i < searchQryModel2.rowCount() && !confirmFood)
            {
                record2 = searchQryModel2.record(i);
                if (food == record2.value(0).toString())
                {
                    confirmFood = true;
                    qDebug().noquote() << "in while loop";

                }
                j++;
            }

            if (confirmFood == true)
            {
                QSqlQuery query;
                QSqlQueryModel* qryModel = new QSqlQueryModel();

                query.prepare("DELETE FROM foodSheet WHERE City = (:City) AND Traditional_Food_Item = (:Food) ");
                query.bindValue(":City", city);
                query.bindValue(":Food", food);
                query.exec();

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
            else
            {
                QMessageBox::warning(this, "WRONG FOOD ITEM", "Enter proper food item");
            }
        }
        else
        {
            QMessageBox::warning(this, "WRONG CITY", "Enter proper City");
        }
    }
}

