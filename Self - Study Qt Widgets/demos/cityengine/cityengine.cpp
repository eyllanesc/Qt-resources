/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "cityengine.h"

// --------------------------------------------------------------------
// Private class, No API
class City {
public:
    QString name;
    QString country;
    int population;
    qreal area;
};

// --------------------------------------------------------------------
// Part of City API from here on

CityEngine::CityEngine(QObject *parent) :
    QObject(parent)
{
    read();
}

CityEngine::~CityEngine() {
    qDeleteAll(m_cities);
    m_cities.clear();
}

void CityEngine::read()
{
    // reset data list
    qDeleteAll(m_cities);
    m_cities.clear();
    // read file from resources
    QFile file(":/data/cities.csv");
    if(!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Unable to open file: " << file.fileName();
    }
    QTextStream stream(&file);

    // first line it's the header row
    QString row = stream.readLine();
    m_headers = row.split(";");

    // now comes the data
    while(!row.isNull()) {
        row = stream.readLine();
        if(row.isEmpty()) { continue; }
        QStringList data = row.split(";");
        // for each row, create a city
        City *city = new City();
        city->name = data.at(CityName);
        city->country = data.at(CityCountry);
        city->population = data.at(CityPopulation).toInt();
        city->area = data.at(CityArea).toFloat();
        if(!m_countryFlags.contains(city->country)) {
            QIcon icon(QString(":/flags/%1").arg(data.at(CityCountryFlag)));
            m_countryFlags.insert(city->country, icon);
        }
        m_cities.insert(city->name, city);
        m_countries.insert(city->country, city->name);
    }
    qDebug() << "read " << m_cities.count() << " cities.";
}

QStringList CityEngine::cities() const
{
    return m_cities.keys();
}

City* CityEngine::cityByName(const QString &cityName) const
{
    return m_cities[cityName];
}


QString CityEngine::country(const QString &cityName) const
{
    City * city = cityByName(cityName);
    if(!city) { return QString(); }
    return city->country;
}

int CityEngine::population(const QString &cityName) const
{
    City * city = cityByName(cityName);
    if(!city) { return -1; }
    return city->population;

}
qreal CityEngine::area(const QString &cityName) const
{
    City * city = cityByName(cityName);
    if(!city) { return -1.0; }
    return city->area;
}

QIcon CityEngine::flag(const QString &countryName) const
{
    return m_countryFlags[countryName];
}


QStringList CityEngine::citiesByCountry(const QString& countryName) const
{
    return m_countries.values(countryName);
}

QStringList CityEngine::countries() const
{
    return m_countries.uniqueKeys();
}

QStringList CityEngine::headers() const
{
    return m_headers;
}

QString CityEngine::header(int column) const
{
    return m_headers.at(column);
}



