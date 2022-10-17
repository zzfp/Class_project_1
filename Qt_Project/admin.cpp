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
   QFile file("C:/Users/James Flanagan/Class_Project_1/CS1D Fall 2022 European Vacation Project/NewCities.csv");
   QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
   db.setDatabaseName("./Project.db");//This line and the previous connect to the sqlite database at this file location,
   db.open();
   if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << file.errorString();
       }

   QSqlQuery query(db);

       if (!file.open(QIODevice::ReadOnly)) {
           qDebug() << file.errorString();
       }
       QTextStream ts (&file);

      while(!ts.atEnd()){
                  QString req = "INSERT INTO distanceSheet(Starting_City, Ending_City, Distance) VALUES (";
                  query.prepare("INSERT INTO distanceSheet(Starting_City, Ending_City, Distance) VALUES (:Starting, :Ending, :Distance)");
                  // split every line
                  QStringList line = ts.readLine().split(',');

                  /*for every values on a line,
                         append it to the INSERT request*/
                  for(int i=0; i<line.length(); ++i)
                  {

                          req.append(line.at(i));
                          req.append(",");

                  }

                  req.append(");"); // close the "VALUES([...]" with a ");"
                  query.exec(req);
                  if (!query.exec() )
                  {
                      QMessageBox::warning(this, "Query Error", "Query not executed");
                  }
                  qDebug() << req;
              }

      refreshCityTable();


}
