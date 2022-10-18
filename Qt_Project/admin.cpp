#include "admin.h"
#include "ui_admin.h"
#include "euromap.h"
#include <QMessageBox>
Admin::Admin(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::Admin)
{
   ui->setupUi(this);

   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("./Project.db");//This line and the previous connect to the sqlite database at this file location,
   db.open();                                                                  //the .db file should be kept within the repository for now

   QSqlQueryModel * model = new QSqlQueryModel();
  //model is readonly access to query results
   QSqlQuery query(db);
   query.prepare("SELECT * FROM distanceSheet");

   query.exec(); //query must be active before being moved into the model

   model->setQuery(std::move(query));
   ui->tableView->setModel(model);

   QSqlQueryModel * model2 = new QSqlQueryModel();
   QSqlQuery query2(db);

   query2.prepare("SELECT * FROM foodSheet");

   query2.exec();

   model2->setQuery(std::move(query2));
   ui->tableView2->setModel(model2);
}

Admin::~Admin()
{
   delete ui;
}

void Admin::refreshCityTable()
{
   ui->setupUi(this);

   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("./Project.db");//This line and the previous connect to the sqlite database at this file location,
   db.open();                                                                  //the .db file should be kept within the repository for now

   QSqlQueryModel * model = new QSqlQueryModel();
  //model is readonly access to query results
   QSqlQuery query(db);
   query.prepare("SELECT * FROM distanceSheet");

   query.exec(); //query must be active before being moved into the model

   model->setQuery(std::move(query));
   ui->tableView->setModel(model);

   QSqlQueryModel * model2 = new QSqlQueryModel();
   QSqlQuery query2(db);

   query2.prepare("SELECT * FROM foodSheet");

   query2.exec();

   model2->setQuery(std::move(query2));
   ui->tableView2->setModel(model2);
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
     else
     {
         QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
         db.setDatabaseName("./Project.db");
         if (db.open()){
             qDebug().noquote() << "db found and open";
         }
         else{
             qDebug().noquote() << "db not found";
         }
         QSqlQuery query(db);

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

     }

   refreshCityTable();


}


void Admin::on_uploadFile_clicked()
{
   QFile file("./NewCities.txt");
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("./Project.db");//This line and the previous connect to the sqlite database at this file location,
   db.open();
   if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << file.errorString();
       }

       if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << file.errorString();
       }

       QString startString;
       QString endString;
       QString distanceString;

       while(!file.atEnd())
           {
               QSqlQuery query;
               query.prepare("INSERT INTO distanceSheet(Starting_City, Ending_City, Distance) VALUES (:Starting, :Ending, :Distance)");

               startString = file.readLine();
               endString = file.readLine();
               distanceString = file.readLine();


               query.bindValue(":Starting", startString);
               query.bindValue(":Ending", endString);
               query.bindValue(":Distance", distanceString.toInt());
               qDebug() << startString << endString << distanceString;
               query.exec();

               query.lastQuery();

           }
           file.close();

      refreshCityTable();


}

void Admin::on_addFoodButton_clicked()
{
    QString city = ui->cityLineEdit->text();
    QString food = ui->endingCityLineEdit->text();
    QString cost = ui->kilometerLineEdit->text();
    if (city == "" || food == "" || cost == "")
      {
          QMessageBox::warning(this, "Empty field", "One of your fields is empty");
      }
      else
      {
          QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
          db.setDatabaseName("./Project.db");
          if (db.open()){
              qDebug().noquote() << "db found and open";
          }
          else{
              qDebug().noquote() << "db not found";
          }
          QSqlQuery query(db);

          query.prepare("INSERT INTO distanceSheet(Starting_City, Ending_City, Distance) VALUES (:Starting, :Ending, :Distance)");
          query.bindValue(":Starting", city);
          query.bindValue(":Ending", food);
          query.bindValue(":Distance", cost);

          if (!query.exec() )
          {
              QMessageBox::warning(this, "Query Error", "Query not executed");
          }

          else
          {
              QMessageBox::information(this, "City Successfully Added", "Success");

          }

      }

    refreshCityTable();
}


void Admin::on_uploadFile2_clicked()
{
    QFile file("./NewFoods.txt");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./Project.db");//This line and the previous connect to the sqlite database at this file location,
    db.open();
    if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
        }

        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << file.errorString();
        }

        QString cityString;
        QString foodString;
        QString costString;

        while(!file.atEnd())
            {
                QSqlQuery query;
                query.prepare("INSERT INTO foodSheet(City, Traditional_Food_Item, Cost) VALUES (:city :food, :cost)");

                cityString = file.readLine();
                foodString = file.readLine();
                costString = file.readLine();


                query.bindValue(":city", cityString);
                query.bindValue(":food", foodString);
                query.bindValue(":cost", costString.toDouble());
                qDebug() << cityString << foodString << costString;
                query.exec();

                query.lastQuery();

            }
            file.close();

       refreshCityTable();


 }


