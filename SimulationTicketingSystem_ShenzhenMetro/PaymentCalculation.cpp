#include "PaymentCalculation.h"

QString url1 = "./CostSheet/附件1 2025年第一批新线开通线网普通车厢票价表.xlsx";
QString url2 = "./CostSheet/附件2 2025年第一批新线开通线网商务车厢票价表.xlsx";

PaymentCalculation::PaymentCalculation():QObject()
{
	ordinaryTickets = QSqlDatabase::addDatabase("QMYSQL"); //加载MySQL驱动
	//database.setHostName("localhost");
	ordinaryTickets.setHostName("127.0.0.1");
	ordinaryTickets.setPort(3306);
	ordinaryTickets.setDatabaseName("ordinaryTickets");
	ordinaryTickets.setUserName("root");
	ordinaryTickets.setPassword("12345678");

	QSqlQuery ordinaryTickets_query("create database ordinaryTickets;");
	ordinaryTickets_query.exec();
	


	businessTickets = QSqlDatabase::addDatabase("QMYSQL"); //加载MySQL驱动
	//database.setHostName("localhost");
	businessTickets.setHostName("127.0.0.1");
	businessTickets.setPort(3306);
	businessTickets.setDatabaseName("ordinaryTickets");
	businessTickets.setUserName("root");
	businessTickets.setPassword("12345678");

	QSqlQuery businessTickets_query("create database businessTickets;");
	businessTickets_query.exec();

}

void PaymentCalculation::readXlsxs(void)
{
	bool isXlsxLoaded = false;
	do {

		Xlsx_ordinaryTickets = new Document(url1);
		Xlsx_businessTickets = new Document(url2);

		if (Xlsx_ordinaryTickets->load() && Xlsx_businessTickets->load()) {
			isXlsxLoaded = true;
		}
		else {
			isXlsxLoaded = false;
			delete Xlsx_ordinaryTickets;
			delete Xlsx_businessTickets;
		}

		//int row = 4; int col = 1;
		/*QVariant var4_1 = Xlsx_ordinaryTickets->read(4, 1);
		QVariant var4_2 = Xlsx_ordinaryTickets->read(5, 1);
		QVariant var1_4 = Xlsx_ordinaryTickets->read(1, 4);
		QVariant var1_5 = Xlsx_ordinaryTickets->read(1, 6);*/

		// check type of var for more information

		//调试用

		emit xlsxLoaded(isXlsxLoaded);
		//emit Debug(var4_1, var4_2, var1_4, var1_5);



		
	} while (isXlsxLoaded == false);

}



PaymentCalculation::~PaymentCalculation()
{


}
