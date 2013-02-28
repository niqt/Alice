/*
 * Percentile.h
 *
 *  Created on: 22/feb/2013
 *      Author: nicola
 */

#ifndef PERCENTILE_H_
#define PERCENTILE_H_


#include <QObject>
#include <QDate>
#include <QString>
#include "percentilemap.h"

class Percentile : public QObject
{
    Q_OBJECT
public:
    explicit Percentile(QObject *parent = 0);
    Q_INVOKABLE QString getFemaleWeight(QDateTime birthday, double measure);
    Q_INVOKABLE QString getFemaleHeight(QDateTime birthday, double measure);
    Q_INVOKABLE QString getFemaleHead(QDateTime birthday, double measure);
    Q_INVOKABLE QString getMaleWeight(QDateTime birthday, double measure);
    Q_INVOKABLE QString getMaleHeight(QDateTime birthday, double measure);
    Q_INVOKABLE QString getMaleHead(QDateTime birthday, double measure);
    Q_INVOKABLE QString getAge(QDateTime birthday);

    Q_INVOKABLE QString test() {return "ciao";}

private:
    bool isweekMinorOf13(QDate birthday);
    int week(QDate birthday);
    int month(QDate birthday);

    QString intervalString(Interval interval);

    PercentileMap *femaleMapWeight13Week;
    PercentileMap *femaleMapWeight2Year;
    PercentileMap *femaleMapWeight5Year;
    PercentileMap *femaleMapHeight13Week;
    PercentileMap *femaleMapHeight2Year;
    PercentileMap *femaleMapHeight5Year;
    PercentileMap *femaleMapHead13Week;
    PercentileMap *femaleMapHead5Year;

    PercentileMap *maleMapWeight13Week;
    PercentileMap *maleMapWeight2Year;
    PercentileMap *maleMapWeight5Year;
    PercentileMap *maleMapHeight13Week;
    PercentileMap *maleMapHeight2Year;
    PercentileMap *maleMapHeight5Year;
    PercentileMap *maleMapHead13Week;
    PercentileMap *maleMapHead5Year;
public slots:

};

#endif /* PERCENTILE_H_ */
