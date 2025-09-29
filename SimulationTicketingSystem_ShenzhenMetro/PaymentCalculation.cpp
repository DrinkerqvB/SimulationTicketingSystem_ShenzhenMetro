#include "PaymentCalculation.h"

PaymentCalculation::PaymentCalculation():QObject()
{
	bool isXlsxLoaded = false;
	do {
		
		Xlsx_ordinaryTickets = new Document("./CostSheet/附件1 2025年第一批新线开通线网普通车厢票价表.xlsx");
		Xlsx_businessTickets = new Document("./CostSheet/附件2 2025年第一批新线开通线网商务车厢票价表.xlsx");

		if (Xlsx_ordinaryTickets->load() && Xlsx_businessTickets->load()){
			isXlsxLoaded = true;
		}
		else {
			isXlsxLoaded = false;
		}

		int row = 1; int col = 1;
		QVariant var = Xlsx_ordinaryTickets->read(row, col);
		// check type of var for more information

		//调试用
		emit xlsxLoaded(isXlsxLoaded);
		//QMessageBox::information()
		qDebug() << var.toString();
	} while (isXlsxLoaded == false);

}


PaymentCalculation::~PaymentCalculation()
{


}
