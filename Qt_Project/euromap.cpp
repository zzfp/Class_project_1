#include "euromap.h"

EuroMap::EuroMap()
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

    myDb.setDatabaseName("./Project.db");
    if (myDb.open())
    {
        qDebug().noquote() << "db found and open";
    }
    else
    {
        qDebug().noquote() << "db not found";
    }

    QSqlQueryModel model;//model is readonly access to query results
    QSqlQuery query(myDb);
    query.prepare("SELECT DISTINCT Starting_City FROM distanceSheet");
    std::vector<QString> city_names;
    query.exec();

    while (query.next())
    {
        city_names.push_back(query.value(0).toString());
    }
    qDebug().noquote() << "city names fetched";
    num_of_cities = int(city_names.size());

    for (int i=0;i<num_of_cities;i++)
    {
        City* temp = new City;
        cities.push_back(temp);
        cities[i]->name = city_names[i].toStdString();
        qDebug().noquote() << QString("city "+QString::fromStdString(cities[i]->name)+" added");
    }
    qDebug().noquote() << "Cities vector filled";

    for (int i=0;i<num_of_cities;i++)
    {
        query.prepare("SELECT Ending_City,Distance FROM distanceSheet WHERE Starting_City = (:cityname) ORDER BY Distance");
        query.bindValue(":cityname",city_names[i]);
        query.exec();
        while(query.next()){
            for (int j=0;j<num_of_cities;j++)
            {
                if (query.value(0).toString() == city_names[j])
                {
                    cities[i]->city_signs.push_back(cities[j]);
                    cities[i]->distances.push_back(query.value(1).toInt());
                }
            }
        }
        qDebug().noquote() << QString::fromStdString(cities[i]->name);
    }
    qDebug().noquote() << "All city objects built";

    for (int j=0;j<num_of_cities;j++)
    {
        qDebug().noquote() << QString::fromStdString(cities[j]->name);
        for (int i=0;i<num_of_cities-1;i++)
        {
            qDebug().noquote() << QString::fromStdString(cities[j]->city_signs[i]->name) << cities[j]->distances[i];
        }
    }
    distances_travelled.push_back(0);
};

void EuroMap::full_map_from_city(QString start, int numberOfCities)
{
        bool incorrectCity = false;

        City* current = NULL;
        QSqlDatabase myDb;
        int distance=0;
        QString table = start;

        QSqlQuery query(myDb);
        int j = 0;
        int forLoopCityIteration = 0;
        int initCity = 0;


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
        if (myDb.open())
        {
            qDebug().noquote() << "db found and open";
        }
        else
        {
            qDebug().noquote() << "db not found";
        }

        while (!incorrectCity)
        {
            qDebug().noquote() << QString::fromStdString(cities[initCity] -> name);
            QString tempString = QString::fromStdString(cities[initCity] -> name);
            if (tempString == start)
            {
                current = cities[initCity];
                incorrectCity = true;
            }
            else
            {
                initCity++;
            }

        }

        std::string temp = current->city_signs[0]->name;

        visited.push_back(*current);

        for (int i = 0; i < numberOfCities - 1; i++)
        {

            qDebug().noquote() << "got to for loop";
            visited.push_back(*current->city_signs[forLoopCityIteration]);
            distance += current->distances[forLoopCityIteration];
            distances_travelled.push_back(distance);

            temp = current->city_signs[forLoopCityIteration]->name;
            incorrectCity = false;
            j=0;
            forLoopCityIteration = 0;

            while (!incorrectCity)
            {
                if (cities[j]-> name == temp)
                {
                    current = cities[j]; //setting current to current city on list which
                                         //is sorted by shortest distance
                    qDebug().noquote() << QString::fromStdString(current->name);
                    incorrectCity = true;
                }
                else
                {
                    qDebug().noquote() << QString(QString::fromStdString(temp) + " does not match " + QString::fromStdString(cities[j]->name));
                    j++;
                }
            }

            qDebug().noquote() << "COLAMNNNNNNNNNNSIZE: "<< int(visited.size());

           if (visited.size() != numberOfCities)
           {
               for (int visitedTest = 0; visitedTest < int(visited.size()); visitedTest++)
               {
                    if (QString::fromStdString(current->city_signs[forLoopCityIteration] -> name) == QString::fromStdString(visited[visitedTest].name))
                    {

                         ++forLoopCityIteration;
                         visitedTest = 0;
                    }
                    if (QString::fromStdString(current->city_signs[forLoopCityIteration] -> name) == start)
                    {
                         forLoopCityIteration++;
                    }

                    qDebug().noquote() << " FINAL TEST: " << QString::fromStdString(visited[visitedTest].name) << "current: " << QString::fromStdString(current->city_signs[forLoopCityIteration] -> name);
                }

            }


            qDebug().noquote() << QString::fromStdString(temp);
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
