#pragma once

#include "MetroLine.h"
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

	Document* Xlsx_ordinaryTickets;
	Document* Xlsx_businessTickets;
	MetroLine* metroLineGroup;

private:
	
	QSqlDatabase ordinaryTickets;
	QSqlDatabase businessTickets;


protected:


signals:
	void xlsxLoaded(bool isXlsxLoaded);
	void Debug(QVariant var1, QVariant var2, QVariant var3, QVariant var4);
	void metroLineGroupLoaded(MetroLine* metroLineGroup);


};

