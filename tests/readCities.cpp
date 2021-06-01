#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <qstring.h>
#include <qfile.h>
#include <qtextstream.h>
#include <qstringlist.h>
#include <KDTree.hpp>


class Location
{

public:
    Location(QString name_, std::vector<double> pointsGPS_, QString continent_, QString country_) : name(name_),
    pointsGPS(pointsGPS_), country(country_), continent(continent_) {}
    QString name;
    std::vector<double> pointsGPS; //{lat,lon}
    QString continent;
    QString country;

    bool match(std::vector<double> p)
    {
        if(p[0] == pointsGPS[0] && p[1] == pointsGPS[1])
            return true;
        else
            return false;
    }

};


int main (void)
{
    QFile file("cities1000.txt");

    std::vector<point_t> pointVector;
    std::vector<Location> locations;

    if (!file.open(QIODevice::ReadOnly)) {
        Q_ASSERT_X(0, "", "Failed to open cities1000.txt file");
    }

    QTextStream fstream(&file);

    while (!fstream.atEnd()) {
        QString str = fstream.readLine();
        str.remove('\r');

        QStringList list = str.split('\t');
        QString poblation = list[1];
        double lat = list[4].toDouble();
        double lon = list[5].toDouble();
        QString countryPrefix = list[8];
        QString continent = list[17];

        pointVector.push_back({lat,lon});
        locations.push_back({poblation, {lat, lon}, countryPrefix, continent});
        std::cout << poblation.toStdString() << ":" << lat << ":" << lon << ":" << countryPrefix.toStdString() << ":" <<continent.toStdString() << std::endl;


    }

    std::cout << "PointVector Size: " << pointVector.size() << std::endl;

    auto mapPoints = KDTree(pointVector);

    //Valdemoro:40.1908:-3.67887:ES:Europe/Madrid

    auto pointNear = mapPoints.nearest_point({40.1900, -3.67889});

    std::cout << pointNear[0] << " " << pointNear[1] << std::endl;

    for(auto loc : locations)
    {
        if(loc.match(pointNear))
            std::cout << "La ubicacion es: " << loc.name.toStdString() << std::endl;
    }

    return 0;
}


