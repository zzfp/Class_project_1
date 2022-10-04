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
    int distance_travelled;
    int num_of_cities;
public:
    EuroMap();
    void full_map_from_city(City start);

};

#endif // EUROMAP_H
