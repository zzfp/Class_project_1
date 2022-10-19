#include "admin.h"
#include "ui_admin.h"
#include "euromap.h"
#include <QMessageBox>
Admin::Admin(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::Admin)
{
   ui->setupUi(this);

                                                                    //the .db file should be kept within the repository for now

   QSqlQueryModel * model = new QSqlQueryModel();
  //model is readonly access to query results
   QSqlQuery query;
   query.prepare("SELECT * FROM distanceSheet");

   query.exec(); //query must be active before being moved into the model

   model->setQuery(std::move(query));
   ui->tableView->setModel(model);

   QSqlQueryModel * model2 = new QSqlQueryModel();
   QSqlQuery query2;

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
   ui->setupUi(this);                                                               //the .db file should be kept within the repository for now

   QSqlQueryModel * model = new QSqlQueryModel();
  //model is readonly access to query results
   QSqlQuery query;
   query.prepare("SELECT * FROM distanceSheet");

   query.exec(); //query must be active before being moved into the model

   model->setQuery(std::move(query));
   ui->tableView->setModel(model);

   QSqlQueryModel * model2 = new QSqlQueryModel();
   QSqlQuery query2;

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

         QSqlQuery query;

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



   refreshCityTable();


}


void Admin::on_uploadFile_clicked()
{
   QFile file("./NewCities.txt");
   if (!file.open(QIODevice::OpenModeFlag::ReadOnly))
       {
           qCritical()<<"please make sure that you put the .txt files in debug folder!";
           qCritical()<<file.errorString();
           return;
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
    QString city = ui->cityLineEdit2->text();
    QString food = ui->foodLineEdit->text();
    QString cost = ui->costLineEdit->text();
    if (city == "" || food == "" || cost == "")
      {
          QMessageBox::warning(this, "Empty field", "One of your fields is empty");
      }

          QSqlQuery query;

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



    refreshCityTable();
}


void Admin::on_uploadFile2_clicked()
{
    QFile file("./NewFoods.txt");
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

        while(!file.atEnd())
            {
                QSqlQuery query;
                query.prepare("INSERT INTO foodSheet(City, Traditional_Food_Item, Cost) VALUES (:City :Food, :Cost)");

                cityString = file.readLine();
                foodString = file.readLine();
                costString = file.readLine();
                costDouble = costString.toDouble();


                query.bindValue(":City", cityString);
                query.bindValue(":Food", foodString);
                query.bindValue(":Cost", costDouble);
                qDebug() << cityString << foodString << costDouble;
                query.exec();

                if (!query.exec())
                    qDebug() << "Query did not execute";



            }
            file.close();

       refreshCityTable();


 }


