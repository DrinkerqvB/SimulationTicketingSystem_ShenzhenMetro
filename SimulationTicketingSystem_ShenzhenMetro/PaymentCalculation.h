#pragma once

#include "MetroLine.h"
#include "OrderInformation.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>

#define NUM_OF_METROLINES 17 //地铁线路数


class PaymentCalculation:public QObject
{
	Q_OBJECT

public:
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


signals:
	void xlsxLoaded(bool isXlsxLoaded);
	void Debug(QVariant var1, QVariant var2, QVariant var3, QVariant var4);
	void metroLineGroupLoaded(MetroLine* metroLineGroup);
	void sendPrice(float singlePrice, float totalPrice);

public slots:
	void receiveOrderInformation(QString startLine, QString startStation, QString endLine, QString endStation, int ticketNum, bool isBusinessTicket);

};

