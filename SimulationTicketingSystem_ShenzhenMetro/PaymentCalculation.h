#pragma once

//#include "Widget.h"
#include "MetroLine.h"
#include "OrderInformation.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QRandomGenerator>
#include <QTimeZone>

#define NUM_OF_METROLINES 17 //地铁线路数
#define DATABASE_USERNAME ("root")
#define DATABASE_PASSWORD ("12345678")


class PaymentCalculation:public QObject
{
	Q_OBJECT

public:
	friend class Widget;
	PaymentCalculation();
	~PaymentCalculation();

	void readXlsxs(void);
	float calculateOneTicket(QString startLine, QString startStation, QString endLine, QString endStation, bool isBusinessTicket);
	int* findStation(QString line, QString station);
	void loadMetroLineGroup(void);

	//void setSingleCost(float cost);
	void calculateSingleCost(void);
	void calculateTotalCost(void);
	float getSingleCost(void);
	float getTotalCost(void);
	

	Document* Xlsx_ordinaryTickets;
	Document* Xlsx_businessTickets;
	MetroLine* metroLineGroup;


private:
	
	
	QSqlDatabase financialRecord;

	OrderInformation orderInformation;


protected:
	QString generateSerialNumber();


signals:
	void xlsxLoaded(bool isXlsxLoaded);
	void Debug(QVariant var1, QVariant var2, QVariant var3, QVariant var4);
	void metroLineGroupLoaded(MetroLine* metroLineGroup);
	void sendPrice(float singlePrice, float totalPrice);
	void sendStationLines(QStringList stationLines);

public slots:
	void receiveOrderInformation(QString startLine, QString startStation, QString endLine, QString endStation, int ticketNum, bool isBusinessTicket);
	void insertIntoDatabase(void);
	QStringList searchStationForLine(QString station);
};

