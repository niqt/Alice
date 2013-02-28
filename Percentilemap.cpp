/*
 * Percentilemap.cpp
 *
 *  Created on: 18/feb/2013
 *      Author: nicola
 */

#include "Percentilemap.h"

#include <QFile>
#include <QDebug>
#include <QStringList>

PercentileMap::PercentileMap(QString filename, QObject *parent) :
    QObject(parent)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    	fprintf(stdout, "File not found\n");
    	fflush(stdout);
        qDebug() << "File not found\n";
            return;
    }
    QByteArray line = file.readLine();
    while (!file.atEnd()) {
        line = file.readLine();
        QString sline = QString::fromUtf8(line.data());
        QStringList list = sline.split(QRegExp("\\s+"));
        for (int i = 0; i < list.length(); i++) {
            qDebug() << "*" << list.at(i) << "* ";

        }
        if (list.length() >= 19) {
            Row dum;

            dum.p0 = list.at(4).toDouble();
            dum.p1 = list.at(5).toDouble();
            dum.p3 = list.at(6).toDouble();
            dum.p5 = list.at(7).toDouble();
            dum.p10 = list.at(8).toDouble();
            dum.p15 = list.at(9).toDouble();
            dum.p25 = list.at(10).toDouble();
            dum.p50 = list.at(11).toDouble();
            dum.p75 = list.at(12).toDouble();
            dum.p85 = list.at(13).toDouble();
            dum.p90 = list.at(14).toDouble();
            dum.p95 = list.at(15).toDouble();
            dum.p97 = list.at(16).toDouble();
            dum.p99 = list.at(17).toDouble();
            dum.p999 = list.at(18).toDouble();
            map.insert(list.at(0).toInt(), dum);
        }
    }
    file.close();
}

Interval PercentileMap::find(int age, double misure)
{
	fprintf(stdout, "map size %d\n", map.size());
	    	fflush(stdout);
    QMap<int, Row>::const_iterator i = map.find(age);
    if (i != map.end()) {
        Row row = i.value();
        if (misure < row.p0)
            return _P0;
        if (misure < row.p1)
            return P0_P1;
        if (misure < row.p3)
            return P1_P3;
        if (misure < row.p5)
            return P3_P5;
        if (misure < row.p10)
            return P5_P10;
        if (misure < row.p15)
            return P10_P15;
        if (misure < row.p25)
            return P15_P25;
        if (misure < row.p50)
            return P25_P50;
        if (misure < row.p75)
            return P50_P75;
        if (misure < row.p85)
            return P75_P85;
        if (misure < row.p90)
            return P85_P90;
        if (misure < row.p95)
            return P90_P95;
        if (misure < row.p97)
            return P95_P97;
        if (misure < row.p99)
            return P97_P99;
        if (misure < row.p999)
            return P99_P999;
        if (misure > row.p999)
            return P999_;
    }
    return P_UNKNOWN;
}

