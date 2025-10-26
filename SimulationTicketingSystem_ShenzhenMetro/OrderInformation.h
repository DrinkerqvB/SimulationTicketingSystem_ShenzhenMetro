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

    QString startLine;//
    QString startStation;//
    QString endLine;//
    QString endStation;//
    int ticketNum;//
    bool isBusinessTicket;//

    QString ticketType;//学生票、深圳通票等，暂时不弄
    QString ticketID; //暂时不弄
    float singlePrice;//
    float totalPrice;//

    QString modeOfPayment; //支付方式，暂时不弄

};

