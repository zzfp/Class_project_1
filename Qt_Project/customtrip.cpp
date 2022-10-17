#include "customtrip.h"
#include "ui_customtrip.h"

customTrip::customTrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customTrip)
{
    ui->setupUi(this);

    if(QSqlDatabase::contains("qt_sql_default_connection"))
    {
        myDb = QSqlDatabase::database("qt_sql_default_connection");
    }
    else
    {
        myDb = QSqlDatabase::addDatabase("QSQLITE");
    }

    myDb.setDatabaseName("./Project.db");
    if (myDb.open()){
        qDebug().noquote() << "db found and open";
    }
    else{
        qDebug().noquote() << "db not found";
    }

    QSqlQueryModel model;
    QSqlQuery query(myDb);
    QSqlQueryModel* cityModel = new QSqlQueryModel();
    query.exec("SELECT DISTINCT Starting_City FROM distanceSheet");
    cityModel->setQuery(std::move(query));
    ui->cityBox->setModel(cityModel);
    QSqlRecord record;
    for(int i=0;i<cityModel->rowCount();i++){
        record = cityModel->record(i);
        ui->citiesComboBox->addItem(record.value(0).toString());
    }
}

customTrip::~customTrip()
{
    QSqlQuery del_query(myDb);
    del_query.exec("TRUNCATE TABLE Custom_Trip");
    delete ui;
}

void customTrip::on_cancelButton_clicked()
{
    this->close();
}


void customTrip::on_acceptButton_clicked()
{
    QSqlQuery query(myDb);
    QSqlQueryModel* cityModel = new QSqlQueryModel();
    query.prepare("SELECT Ending_City FROM distanceSheet WHERE Starting_City = (:city)");
    query.bindValue(":city",ui->citiesComboBox->currentText());
    query.exec();
    if (query.size() != 0){
        visited.push_back(ui->citiesComboBox->currentText());
        cityModel->setQuery(std::move(query));
        ui->cityBox->setModel(cityModel);
        ui->errorText->setText("");
    }
    else{
        ui->errorText->setText("Invalid City, please select from the list above");
    }
}


void customTrip::on_finalTripButton_clicked()
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQueryModel* food_model = new QSqlQueryModel;
    bool already;
    City* current = NULL;
    std::vector<City*> cities;
    std::vector<City> order;
    int num_cities = int(visited.size());
    for (int i=0;i<num_cities;i++){
        City* temp = new City;
        cities.push_back(temp);
        cities[i]->name = visited[i].toStdString();
    }
    QSqlQuery query(myDb);
    for (int i=0;i<num_cities;i++){
        query.prepare("SELECT Ending_City,Distance FROM distanceSheet WHERE Starting_City = (:cityname) ORDER BY Distance");
        query.bindValue(":cityname",visited[i]);
        query.exec();
        while(query.next()){
            for (int j=0;j<num_cities;j++){
                if (query.value(0).toString() == visited[j]){
                    cities[i]->city_signs.push_back(cities[j]);
                    cities[i]->distances.push_back(query.value(1).toInt());
                }
            }
        }
    }
    for (int i=0;i<num_cities;i++){
        if (cities[i]->name == visited[0].toStdString()){
            current = cities[i];
        }
    }
    if (current != NULL){
        order.push_back(*current);
        for (int count = 1;count<num_cities;count++){
            for (int i=0;i<num_cities;i++){
                already = false;
                for (int j=0;j<int(order.capacity());j++){
                    if (current->city_signs[i]->name == order[j].name){
                        already = true;
                    }
                }
                if (!already){
                    order.push_back(*current->city_signs[i]);
                    current = current->city_signs[i];
                    break;
                }
            }
        }
    }
    for (int i=0;i<int(order.size());i++){
        qDebug().noquote() << QString::fromStdString(order[i].name);
        query.prepare("INSERT INTO Custom_Trip VALUES ((:City))");
        query.bindValue(":City",QString::fromStdString(order[i].name));
        query.exec();
        query.next();
    }
    model->setQuery("SELECT City FROM Custom_Trip");
    ui->cityBox->setModel(model);
    food_model->setQuery("SELECT foodSheet.City,foodSheet.Traditional_Food_Item,foodSheet.Cost FROM foodSheet INNER JOIN Custom_Trip ON Custom_Trip.City==foodSheet.City");
    ui->foodBox->setModel(food_model);
    ui->cityLabel->setText("Cities to visit");
    ui->foodLabel->setText("Foods to Buy");

}
