#include "PaymentCalculation.h"

PaymentCalculation::PaymentCalculation():QObject()
{
	bool isXlsxLoaded;
	Document doc("附件1 2025年第一批新线开通线网普通车厢票价表.xlsx");
	if (!doc.load())
		isXlsxLoaded = false;

	int row = 1; int col = 1;
	QVariant var = doc.read(row, col);
	// check type of var for more information
	
	//调试用
	emit xlsxLoaded();
	//QMessageBox::information()
	qDebug() << var.toString();

}


PaymentCalculation::~PaymentCalculation()
{


}
