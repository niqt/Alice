/*
 * Percentilemap.h
 *
 *  Created on: 18/feb/2013
 *      Author: nicola
 */

#ifndef PERCENTILEMAP_H_
#define PERCENTILEMAP_H_

#include <QObject>
#include <QMap>

struct Row
{
    double p0;
    double p1;
    double p3;
    double p5;
    double p10;
    double p15;
    double p25;
    double p50;
    double p75;
    double p85;
    double p90;
    double p95;
    double p97;
    double p99;
    double p999;
};

enum Interval {_P0, P0_P1, P1_P3, P3_P5, P5_P10, P10_P15, P15_P25, P25_P50, P50_P75, P75_P85, P85_P90, P90_P95, P95_P97, P97_P99, P99_P999, P999_, P_UNKNOWN};


class PercentileMap : public QObject
{
    Q_OBJECT
private:
    QMap<int, Row> map;
public:
    explicit PercentileMap(QString filename, QObject *parent = 0);
    Interval find(int age, double misure);

signals:

public slots:

};
#endif /* PERCENTILEMAP_H_ */
