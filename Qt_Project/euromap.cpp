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
    for (int j=0;j<num_of_cities-2;j++){
        qDebug().noquote() << QString::fromStdString(cities[j]->name);
        for (int i=0;i<num_of_cities-2;i++){
            qDebug().noquote() << QString::fromStdString(cities[j]->city_signs[i]->name) << cities[j]->distances[i];
        }
    }
    distances_travelled.push_back(0);
};

void EuroMap::full_map_from_city(QString Start){
        bool already;
        City* current;
        QSqlDatabase myDb;
        int distance=0;

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
        QSqlQuery query(myDb);
        query.prepare("INSERT INTO Berlin_Trip VALUES ('Berlin',0)");
        std::vector<QString> city_names;
        for (int i=0;i<num_of_cities-1;i++){
            if (cities[i]->name == Start.toStdString()){
                current = cities[i];
                qDebug().noquote() << QString::fromStdString(current->name);
            }
        }
        query.exec();
        visited.push_back(*current);
        for (int count = 0;count<num_of_cities-2;count++){
            for (int i=0;i<num_of_cities-1;i++){
                already = false;
                for (int j=0;j<int(visited.capacity());j++){
                    if (current->city_signs[i]->name ==visited[j].name){
                        already = true;
                    }
                }
                if (!already){
                    visited.push_back(*current->city_signs[i]);
                    distance += current->distances[i];
                    distances_travelled.push_back(distance);
                    current = current->city_signs[i];
                    qDebug().noquote() << "unvisited found" << QString::fromStdString(current->name) << " Distance: " << distance;
                    break;
                }

            }
        }
        for (int i=1;i<=int(visited.capacity());i++){
            query.prepare("INSERT INTO Berlin_Trip VALUES ((:City),(:distance))");
            query.bindValue(":City",QString::fromStdString(visited[i].name));
            query.bindValue(":distance",distances_travelled[i]);
            query.exec();
        } //not working correctly atm

}
