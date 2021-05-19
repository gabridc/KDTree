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

int main (void)
{
    QFile file("cities1000.txt");

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

        std::cout << poblation.toStdString() << ":" << lat << ":" << lon << ":" << countryPrefix.toStdString() << ":" <<continent.toStdString() << std::endl;


    }

    return 0;
}


