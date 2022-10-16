#ifndef EUROMAP_H
#define EUROMAP_H
#include <QtSql>
#include <QSqlDatabase>
#include <vector>

struct City{
    std::string name;
    std::vector<int> distances;
    std::vector<City*> city_signs;
};

class EuroMap
{
    std::vector<City*> cities;
    std::vector<City> visited;
    std::vector<int> distances_travelled;
    int num_of_cities;
public:
    EuroMap();
    void full_map_from_city(QString Start, int numberOfCities);

};

#endif // EUROMAP_H
