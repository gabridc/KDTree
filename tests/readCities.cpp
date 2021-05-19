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
    QFile file("C:/Users/gadominguez/Downloads/cities1000.txt");

    if (!file.open(QIODevice::ReadOnly)) {
        Q_ASSERT_X(0, "", "Failed to open cities1000.txt file");
    }

    QTextStream fstream(&file);

    while (!fstream.atEnd()) {
        QString str = fstream.readLine();
        str.remove('\r');

        QStringList list = str.split('\t');
         double lat = list[4].toDouble();
        double lon = list[5].toDouble();

        std::cout << lat << ":" << lon << std::endl;


    }

    return 0;
}


