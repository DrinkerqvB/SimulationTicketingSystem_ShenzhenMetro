#pragma once

#include "MetroLine.h"
#include <QMessageBox>


class PaymentCalculation:public QObject
{
	Q_OBJECT

public:
	PaymentCalculation();
	~PaymentCalculation();

private:
	Document* Xlsx_ordinaryTickets;
	Document* Xlsx_businessTickets;


protected:


signals:
	void xlsxLoaded(bool isXlsxLoaded);



};

