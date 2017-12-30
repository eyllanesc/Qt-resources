/*************************************************************************
 *
 * Copyright (c) 2016 Qt Company
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef CITYENGINE_H
#define CITYENGINE_H

#include <QtGui>

// Private implementation class
class City;

// Your API to the cities
class CityEngine : public QObject
{
    Q_OBJECT
public:
    enum { CityName=0, CityCountry=1, CityPopulation=2, CityArea=3, CityCountryFlag=4 };
    explicit CityEngine(QObject *parent = Q_NULLPTR);
    ~CityEngine();
    QStringList cities() const;
    QString country(const QString &cityName) const;
    int population(const QString &cityName) const;
    qreal area(const QString &cityName) const;
    QIcon flag(const QString &countryName) const;
    QStringList citiesByCountry(const QString& countryName) const;
    QStringList countries() const;
    QStringList headers() const;
    QString header(int column) const;
private:
    void read();
    City* cityByName(const QString &cityName) const;
private:
    QMap<QString, City*> m_cities;
    QMap<QString, QIcon> m_countryFlags;
    QMultiMap<QString, QString> m_countries;
    QStringList m_headers;
};

#endif // CITYENGINE_H
