#pragma once

#include "MetroLine.h"
#include <QMessageBox>


class PaymentCalculation:QObject
{
	Q_OBJECT

public:
	PaymentCalculation();
	~PaymentCalculation();

private:



protected:


signals:
	void xlsxLoaded(void);



};

