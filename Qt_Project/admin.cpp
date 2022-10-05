#include "admin.h"
#include "ui_admin.h"
#include <QMessageBox>
Admin::Admin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Admin)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/James Flanagan/Class_Project_1/Project.db");//This line and the previous connect to the sqlite database at this file location,
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


void Admin::on_addCityButton_clicked()
{
    QString city = ui->addCityButton->text();
    QString endingCity = ui->endingCityLineEdit->text();
    QString distance = ui->kilometerLineEdit->text();
    if (city == "" || endingCity == "" || distance == "")
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

          query.prepare("INSERT INTO distanceSheet VALUES ((:Starting_City), (:Ending_City), (:Distance)");
          query.bindValue(":Starting_City", city);
          query.bindValue(":Ending_City", endingCity);
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


}

