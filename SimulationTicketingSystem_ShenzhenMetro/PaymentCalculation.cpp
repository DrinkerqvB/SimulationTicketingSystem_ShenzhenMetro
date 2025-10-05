#include "PaymentCalculation.h"

QString url1 = "./CostSheet/附件1 2025年第一批新线开通线网普通车厢票价表.xlsx";
QString url2 = "./CostSheet/附件2 2025年第一批新线开通线网商务车厢票价表.xlsx";

PaymentCalculation::PaymentCalculation():QObject()
{
	
	businessTickets = QSqlDatabase::addDatabase("QMYSQL"); //加载MySQL驱动
	//database.setHostName("localhost");
	businessTickets.setHostName("127.0.0.1");
	businessTickets.setPort(3306);
	businessTickets.setDatabaseName("ordinaryTickets");
	businessTickets.setUserName("root");
	businessTickets.setPassword("12345678");

	QSqlQuery businessTickets_query("create database businessTickets;");
	businessTickets_query.exec();

	metroLineGroup = new MetroLine[NUM_OF_METROLINES];

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
		QVariant var4_1 = Xlsx_ordinaryTickets->read(412, 1);
		QVariant var4_2 = Xlsx_ordinaryTickets->read(5, 1);
		QVariant var1_4 = Xlsx_ordinaryTickets->read(1, 4);
		QVariant var1_5 = Xlsx_ordinaryTickets->read(1, 6);

		// check type of var for more information

		//调试用

		emit xlsxLoaded(isXlsxLoaded);
		//emit Debug(var4_1, var4_2, var1_4, var1_5);

		
	} while (isXlsxLoaded == false);

	loadMetroLineGroup();
	emit metroLineGroupLoaded(metroLineGroup);
}



PaymentCalculation::~PaymentCalculation()
{ }


void PaymentCalculation::loadMetroLineGroup(void)
{
	QVariant line, lastLine, station;
	int row = 4;
	for (int i = 0; i < NUM_OF_METROLINES; i++) {

		lastLine = line = Xlsx_ordinaryTickets->read(row, 1);
		station = Xlsx_ordinaryTickets->read(row, 3);
		int countStationNum;

		for (countStationNum = 0; line == lastLine; countStationNum++) {
			metroLineGroup[i].lineName = line.toString();
			metroLineGroup[i].lineStations[countStationNum] = station.toString();
			row++;
			lastLine = line;
			line = Xlsx_ordinaryTickets->read(row, 1);
			station = Xlsx_ordinaryTickets->read(row, 3);
		}
		metroLineGroup[i].stationsNum = countStationNum;


	}
}


float PaymentCalculation::calculateOneTicket(QString startLine, QString startStation, QString endLine, QString endStation,bool isBusinessTicket)
{
	int* posStart = findStation(startLine, startStation);
	int* posEnd = findStation(endLine, endStation);

	int posCost[2] = {posStart[0],posEnd[1]};
	float cost = 0;

	if (isBusinessTicket != true) {
		cost = Xlsx_ordinaryTickets->read(posCost[0], posCost[1]).toFloat();
	}
	else {
		cost = Xlsx_businessTickets->read(posCost[0], posCost[1]).toFloat();
	}

	return cost;
	
}

int* PaymentCalculation::findStation(QString line, QString station)
{
	int* pos = new int[2];
	QVariant data_station,data_line;
	int row=3, col=3;
	//读取行值
	do {
		row++;
		data_station = Xlsx_ordinaryTickets->read(row, 3);
		data_line = Xlsx_ordinaryTickets->read(row, 1);
		
	} while (!(data_station.isNull() == true || (data_station.toString() == station && data_line.toString() == line)));

	pos[0] = row;

	//读取列值
	do {
		col++;
		data_station = Xlsx_ordinaryTickets->read(3, col);
		data_line = Xlsx_ordinaryTickets->read(1, col);

	} while (!(data_station.isNull() == true || (data_station.toString() == station && data_line.toString() == line)));

	pos[1] = col;

	return pos;
}
