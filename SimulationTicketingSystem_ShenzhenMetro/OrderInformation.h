#pragma once
//#include "D:\Qt\6.9.1\msvc2022_64\include\QtCore\qobject.h"
#include <QObject>
class OrderInformation :
    public QObject
{
public:
    QString serialNumber;

    QString orderDatetime;

    QString enterStationDatetime;
    QString exitStationDatetime;

    QString startLine;
    QString startStation;
    QString endLine;
    QString endStation;
    int ticketNum;
    bool isBusinessTicket;

    QString ticketType;
    QString ticketID;
    float singlePrice;
    float totalPrice;

    QString modeOfPayment;

};

