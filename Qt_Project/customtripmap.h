#ifndef CUSTOMTRIPMAP_H
#define CUSTOMTRIPMAP_H
#include <QtSql>
#include <QSqlDatabase>
#include <vector>
#include <QString>


struct customCity{
    std::string name;
    std::vector<int> distances;
    std::vector<customCity*> city_signs;
};

class customTripMap
{
    std::vector<customCity*> cities;
    std::vector<customCity> visited;
    std::vector<int> distances_travelled;
    int num_of_cities;
public:
    customTripMap();
    void fullMap(QString start, int numberOfCities);

};

#endif // CUSTOMTRIPMAP_H
