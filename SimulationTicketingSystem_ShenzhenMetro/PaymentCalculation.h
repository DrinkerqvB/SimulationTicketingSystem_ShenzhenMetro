#pragma once

#include "MetroLine.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>


class PaymentCalculation:public QObject
{
	Q_OBJECT

public:
	PaymentCalculation();
	~PaymentCalculation();

	void readXlsxs(void);

	Document* Xlsx_ordinaryTickets;
	Document* Xlsx_businessTickets;

private:
	
	QSqlDatabase ordinaryTickets;
	QSqlDatabase businessTickets;


protected:


signals:
	void xlsxLoaded(bool isXlsxLoaded);
	void Debug(QVariant var1, QVariant var2, QVariant var3, QVariant var4);



};

