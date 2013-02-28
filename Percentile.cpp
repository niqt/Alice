/*
 * Percentile.cpp
 *
 *  Created on: 22/feb/2013
 *      Author: nicola
 */

#include "Percentile.h"

#include <QDate>
#include <QDebug>

Percentile::Percentile(QObject *parent) :
    QObject(parent)
{

    femaleMapWeight13Week = NULL;
    femaleMapWeight2Year = NULL;
    femaleMapWeight5Year = NULL;
    femaleMapHeight13Week = NULL;
    femaleMapHeight2Year = NULL;
    femaleMapHeight5Year = NULL;
    femaleMapHead13Week = NULL;
    femaleMapHead5Year = NULL;

    maleMapWeight13Week = NULL;
    maleMapWeight2Year = NULL;
    maleMapWeight5Year = NULL;
    maleMapHeight13Week = NULL;
    maleMapHeight2Year = NULL;
    maleMapHeight5Year = NULL;
    maleMapHead13Week = NULL;
    maleMapHead5Year = NULL;
}

bool Percentile::isweekMinorOf13(QDate birthday)
{
    QDate today = QDate::currentDate();

    if ( birthday.daysTo(today) <= (7 *13))
        return true;
    return false;
}

int Percentile::week(QDate birthday)
{
    QDate today = QDate::currentDate();
    int nWeek = 0;
    while ((birthday =birthday.addDays(7)) < today) {
        nWeek++;
    }
    return nWeek;
}

QString Percentile::intervalString(Interval interval)
{
	QString dum;
	switch (interval) {
		case _P0:
			dum = "Unknown";
			break;
		case P0_P1:
			dum = "between 0 and 1 percentile";
			break;
		case P1_P3:
			dum = "between 1 and 3 percentile";
			break;
		case P3_P5:
			dum = "between 3 and 5 percentile";
			break;
		case P5_P10:
			dum = "between 5 and 10 percentile";
			break;
		case P10_P15:
			dum = "between 10 and 15 percentile";
			break;
		case P15_P25:
			dum = "between 15 and 25 percentile";
			break;
		case P25_P50:
			dum = "between 25 and 50 percentile";
			break;
		case P50_P75:
			dum = "between 50 and 75 percentile";
			break;
		case P75_P85:
			dum = "between 75 and 85 percentile";
			break;
		case P85_P90:
			dum = "between 85 and 90 percentile";
			break;
		case P90_P95:
			dum = "between 90 and 95 percentile";
			break;
		case P95_P97:
			dum = "between 95 and 97 percentile";
			break;
		case P97_P99:
			dum = "between 97 and 99 percentile";
			break;
		case P99_P999:
			dum = "between 99 and 999 percentile";
			break;
		case P999_:
			dum = "> 99 percentile";
			break;
		case P_UNKNOWN:
		default:
			dum = "Unknown";
			break;
	}
	return dum;
}

QString Percentile::getAge(QDateTime birthday)
{
	QString ageString;
	if (isweekMinorOf13(birthday.date())) {
		int nweek = week(birthday.date());
		ageString = QString::number(nweek) + " weeks";
	} else {
		int nmonth = month(birthday.date());
		ageString = QString::number(nmonth) + " months";
	}
	return ageString;
}

int Percentile::month(QDate birthday)
{
    QDate today = QDate::currentDate();

    int nMonth = 0;
    while ((birthday = birthday.addDays(30)) < today) {
        nMonth++;
    }
    return nMonth;
}

QString Percentile::getFemaleWeight(QDateTime birthday, double measure)
{
    QString a;
    a = "Unknown";
    fprintf(stdout, "data %s\n", birthday.toString("dd.MM.yyyy").toStdString().c_str());
    fflush(stdout);
    if (isweekMinorOf13(birthday.date())) {
        int nweek = week(birthday.date());
        if (femaleMapWeight13Week == NULL)
            femaleMapWeight13Week = new PercentileMap("app/native/assets/tab_wfa_girls_p_0_13.txt", this);
        Interval percentile = femaleMapWeight13Week->find(nweek, measure);

        a = intervalString(percentile);

    }else {
        int nmonth = month(birthday.date());
        fprintf(stdout, "month %d\n", nmonth);
        fflush(stdout);
        if (nmonth >= 0 && nmonth <= 60) {
            if (femaleMapWeight5Year == NULL)
                femaleMapWeight5Year = new PercentileMap("app/native/assets/tab_wfa_girls_p_0_5.txt", this);
            Interval percentile = femaleMapWeight5Year->find(nmonth, measure);
            fprintf(stdout, "percentile %d", percentile);
                        fflush(stdout);
            a = intervalString(percentile);
        }
    }

    return a;
}

QString Percentile::getFemaleHeight(QDateTime birthday, double measure)
{
    QString a;
    a = "Unknown";
    if (isweekMinorOf13(birthday.date())) {
        int nweek = week(birthday.date());
        if (femaleMapHeight13Week == NULL)
            femaleMapHeight13Week = new PercentileMap("app/native/assets/tab_lhfa_girls_p_0_13.txt", this);
        Interval percentile = femaleMapHeight13Week->find(nweek, measure);

        a = intervalString(percentile);
    }else {
        int nmonth = month(birthday.date());
        if (nmonth < 25) {
            if (femaleMapHeight2Year == NULL)
                femaleMapHeight2Year = new PercentileMap("app/native/assets/tab_lhfa_girls_p_0_2.txt", this);
            Interval percentile = femaleMapHeight2Year->find(nmonth, measure);
            fprintf(stdout, "percentile %d", percentile);
            fflush(stdout);

            a = intervalString(percentile);
        } else if (nmonth >= 25 && nmonth <= 60) {
            if (femaleMapHeight5Year == NULL)
                femaleMapHeight5Year = new PercentileMap("app/native/assets/tab_lhfa_girls_p_2_5.txt", this);
            Interval percentile = femaleMapHeight5Year->find(nmonth, measure);
            a = intervalString(percentile);
        }
    }

    return a;
}

QString Percentile::getFemaleHead(QDateTime birthday, double measure)
{
    QString a;
    a = "Unknown";
    if (isweekMinorOf13(birthday.date())) {
        int nweek = week(birthday.date());
        if (femaleMapHead13Week == NULL)
            femaleMapHead13Week = new PercentileMap("app/native/assets/tab_hcfa_girls_p_0_13.txt", this);
        Interval percentile = femaleMapHead13Week->find(nweek, measure);

        a = intervalString(percentile);
    }else{
        int nmonth = month(birthday.date());
        if (nmonth >= 0 && nmonth <= 60) {

            if (femaleMapHead5Year == NULL)
                femaleMapHead5Year = new PercentileMap("app/native/assets/tab_hcfa_girls_p_0_5.txt", this);
            Interval percentile = femaleMapHead5Year->find(nmonth, measure);
            a = intervalString(percentile);
        }
    }

    return a;
}

QString Percentile::getMaleWeight(QDateTime birthday, double measure)
{
    QString a;
    a = "Unknown";
    if (isweekMinorOf13(birthday.date())) {
        int nweek = week(birthday.date());
        if (maleMapWeight13Week == NULL)
            maleMapWeight13Week = new PercentileMap("app/native/assets/tab_wfa_boys_p_0_13.txt", this);
        Interval percentile = maleMapWeight13Week->find(nweek, measure);

        a = intervalString(percentile);
    }else {
        int nmonth = month(birthday.date());
        if (nmonth >= 0 && nmonth <= 60) {
            if (maleMapWeight5Year == NULL)
                maleMapWeight5Year = new PercentileMap("app/native/assets/tab_wfa_boys_p_0_5.txt", this);
            Interval percentile = maleMapWeight5Year->find(nmonth, measure);
            a = intervalString(percentile);
        }
    }

    return a;
}

QString Percentile::getMaleHeight(QDateTime birthday, double measure)
{
    QString a;
    a = "Unknown";
    if (isweekMinorOf13(birthday.date())) {
        int nweek = week(birthday.date());
        if (maleMapHeight13Week == NULL)
            maleMapHeight13Week = new PercentileMap("app/native/assets/tab_lhfa_boys_p_0_13.txt", this);
        Interval percentile = maleMapHeight13Week->find(nweek, measure);

        a = intervalString(percentile);
    }else {
        int nmonth = month(birthday.date());
        if (nmonth < 25) {
            if (maleMapHeight2Year == NULL)
                maleMapHeight2Year = new PercentileMap("app/native/assets/tab_lhfa_boys_p_0_2.txt", this);
            Interval percentile = maleMapHeight2Year->find(nmonth, measure);
            a = intervalString(percentile);
        } else if (nmonth >= 25 && nmonth <= 60) {
            if (maleMapHeight5Year == NULL)
                maleMapHeight5Year = new PercentileMap("app/native/assets/tab_lhfa_boys_p_2_5.txt", this);
            Interval percentile = maleMapHeight5Year->find(nmonth, measure);
            a = intervalString(percentile);
        }
    }

    return a;
}

QString Percentile::getMaleHead(QDateTime birthday, double measure)
{
    QString a;
    a = "Unknown";
    if (isweekMinorOf13(birthday.date())) {
        int nweek = week(birthday.date());
        if (maleMapHead13Week == NULL)
            maleMapHead13Week = new PercentileMap("app/native/assets/tab_hcfa_boys_p_0_13.txt", this);
        Interval percentile = maleMapHead13Week->find(nweek, measure);

        a = intervalString(percentile);
    }else {
        int nmonth = month(birthday.date());
        if (nmonth >= 0 && nmonth <= 60) {

            if (maleMapHead5Year == NULL)
                maleMapHead5Year = new PercentileMap("app/native/assets/tab_hcfa_boys_p_0_5.txt", this);
            Interval percentile = maleMapHead5Year->find(nmonth, measure);
            a = intervalString(percentile);
        }

    }

    return a;
}


