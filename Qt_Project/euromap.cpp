#include "euromap.h"

EuroMap::EuroMap(){
    QSqlDatabase myDb;

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

    QSqlQueryModel model;//model is readonly access to query results
    QSqlQuery query(myDb);
    query.prepare("SELECT DISTINCT Starting_City FROM distanceSheet");
    std::vector<QString> city_names;
    query.exec();
    while (query.next()){
        city_names.push_back(query.value(0).toString());
    }
    qDebug().noquote() << "city names fetched";
    num_of_cities = int(city_names.size());

    for (int i=0;i<num_of_cities;i++){
        City* temp = new City;
        cities.push_back(temp);
        cities[i]->name = city_names[i].toStdString();
        qDebug().noquote() << QString("city "+QString::fromStdString(cities[i]->name)+" added");
    }
    qDebug().noquote() << "Cities vector filled";

    for (int i=0;i<num_of_cities;i++){
        query.prepare("SELECT Ending_City,Distance FROM distanceSheet WHERE Starting_City = (:cityname) ORDER BY Distance");
        query.bindValue(":cityname",city_names[i]);
        query.exec();
        while(query.next()){
            for (int j=0;j<num_of_cities;j++){
                if (query.value(0).toString() == city_names[j]){
                    cities[i]->city_signs.push_back(cities[j]);
                    cities[i]->distances.push_back(query.value(1).toInt());
                }
            }
        }
        qDebug().noquote() << QString::fromStdString(cities[i]->name);
    }
    qDebug().noquote() << "All city objects built";
    for (int j=0;j<num_of_cities-2;j++){
        qDebug().noquote() << QString::fromStdString(cities[j]->name);
        for (int i=0;i<num_of_cities-2;i++){
            qDebug().noquote() << QString::fromStdString(cities[j]->city_signs[i]->name) << cities[j]->distances[i];
        }
    }
    distances_travelled.push_back(0);
};

void EuroMap::full_map_from_city(QString Start, int numberOfCities){
        bool already;
        City* current = NULL;
        QSqlDatabase myDb;
        int distance=0;
        QString table = Start;
        table.append("_Trip");
        int citiesVisted = numberOfCities; //added this for generalization for other functions

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
        QSqlQuery query(myDb);
//        qDebug().noquote() << table;
//        if (query.exec(QString("CREATE TABLE "+table+" ('City' TEXT,'Distance_Travelled' INTEGER)"))){
//            qDebug().noquote() << query.lastQuery();
//            if(query.exec(QString("INSERT INTO \"" +table+"\" VALUES ('" +Start+ "',0)"))){
//                qDebug().noquote() << "Table created and inserted to " << query.lastQuery();
//            }
//            else{
//                qDebug().noquote() << "Table created but failed to insert";
//            }
//        }
//        else{
//            qDebug().noquote() << "Table failed to create";
//        }
        std::vector<QString> city_names;
        for (int i=0;i<num_of_cities;i++){
            if (cities[i]->name == Start.toStdString()){
                current = cities[i];
                qDebug().noquote() << QString::fromStdString(current->name);
            }
            else{
                qDebug().noquote() << QString(Start + " does not match " + QString::fromStdString(cities[i]->name));
            }
        }
        if (current == NULL){
            qDebug().noquote() << "Invalid city entered. Please review.\n";
            return;
        }
        visited.push_back(*current);
        for (int count = 0;count<num_of_cities-2;count++)
        {
            for (int i=0;i<num_of_cities-1;i++)
            {
                already = false;
                for (int j=0;j<int(visited.capacity());j++)
                {
                    if (current->city_signs[i]->name ==visited[j].name)
                    {
                        already = true;
                    }
                }
                if (!already)
                {
                    visited.push_back(*current->city_signs[i]);
                    distance += current->distances[i];
                    distances_travelled.push_back(distance);
                    current = current->city_signs[i];
                    qDebug().noquote() << "unvisited found" << QString::fromStdString(current->name) << " Distance: " << distance;
                }

            }
        }
        qDebug().noquote() << "SIZE: "<< int(visited.size());
        for (int i=0;i<citiesVisted;i++)
        {
            query.prepare("INSERT INTO Berlin_Trip VALUES ((:City),(:distance))");
            query.bindValue(":City",QString::fromStdString(visited[i].name));
            query.bindValue(":distance",distances_travelled[i]);
            query.exec();
            query.next();
        }

}
