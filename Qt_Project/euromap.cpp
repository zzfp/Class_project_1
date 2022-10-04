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

    myDb.setDatabaseName("C:/Users/zacal/CS1D/trip_planner_repo/Class_project_1/Qt_Project/Project.db");
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
        qDebug().noquote() << city_names[i];
    }

    for (int i=0;i<=num_of_cities;i++){
        cities.push_back(new City);
        cities[i]->name = city_names[i].toStdString();
    }
    qDebug().noquote() << "Cities vector filled";

    for (int i=0;i<num_of_cities;i++){
        query.prepare("SELECT Ending_City,Distance FROM distanceSheet WHERE Starting_City = (:cityname) ORDER BY Distance");
        query.bindValue(":cityname",city_names[i]);
        query.exec();
        while(query.next()){
            for (int j=0;j<num_of_cities-1;j++){
                if (query.value(0).toString() == city_names[j]){
                    cities[i]->city_signs.push_back(cities[j]);
                    cities[i]->distances.push_back(query.value(1).toInt());
                }
            }
        }
        qDebug().noquote() << QString::fromStdString(cities[i]->name);
    }
    qDebug().noquote() << "All city objects built";
};

void EuroMap::full_map_from_city(City Start){
        bool already;
        City* current = &Start;
        for (int count = 0;count<num_of_cities;count++){
            for (int i=0;i<num_of_cities;i++){
                already = false;
                for (int j=0;j<int(visited.capacity());j++){
                    if (current->city_signs[i]->name ==visited[j].name){
                        already = true;
                    }
                if (!already){
                    visited.push_back(*current->city_signs[i]);
                    distance_travelled += current->distances[i];
                    current = current->city_signs[i];
                    break;
                }
            }
            }
        }
        for (int printloop=0;printloop<=int(visited.capacity());printloop++){
            qDebug().noquote() << QString::fromStdString(visited[printloop].name);
        }

}
