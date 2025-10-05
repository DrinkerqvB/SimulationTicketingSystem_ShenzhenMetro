#include "PaymentCalculation.h"

QString url1 = "./CostSheet/附件1 2025年第一批新线开通线网普通车厢票价表.xlsx";
QString url2 = "./CostSheet/附件2 2025年第一批新线开通线网商务车厢票价表.xlsx";

PaymentCalculation::PaymentCalculation():QObject()
{
	/*未完工
	* 
	financialRecord = QSqlDatabase::addDatabase("QMYSQL"); //加载MySQL驱动
	//database.setHostName("localhost");
	financialRecord.setHostName("127.0.0.1");
	financialRecord.setPort(3306);
	financialRecord.setDatabaseName("ordinaryTickets");
	financialRecord.setUserName("root");
	financialRecord.setPassword("12345678");

	QSqlQuery financialRecord_query("create database financialRecord;");
	financialRecord_query.exec();
	financialRecord_query.exec("use database financialRecord;");
	financialRecord_query.exec("create or replace table record(\
		SerialNumber varchar(50) primary key,\
		OrderDatetime datetime,\
		EnterStationDatetime datetime,\
		ExitStationDatetime datetime,\
		StartLine varchar(50),\
		StartFrom varchar(50),\
		EndLine varchar(50),\
		EndTo varchar(50),\
		TicketType varchar(50),\
		TicketID varchar(50)\
		TicketNum int,\
		SinglePrice float,\
		TotalPrice float,\
		ModeOfPayment varchar(50)\
	); ");
	*
	*/

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

	///*调试用*/
	//QString lineString = line.toString();
	//QString lastLineString = lastLine.toString();
	//QString stationString = station.toString();
	///*******/

	for (int i = 0; i < NUM_OF_METROLINES; i++) {

		lastLine = line = Xlsx_ordinaryTickets->read(row, 1);
		station = Xlsx_ordinaryTickets->read(row, 3);
		int countStationNum;

		///*调试用*/
		//lineString = line.toString();
		//lastLineString = lastLine.toString();
		//stationString = station.toString();
		///*******/

		for (countStationNum = 0; (line == lastLine)&&station.isNull()!=true; countStationNum++) {
			metroLineGroup[i].lineName = line.toString();
			metroLineGroup[i].lineStations.append(station.toString());
			row++;
			lastLine = line;
			line = Xlsx_ordinaryTickets->read(row, 1);
			station = Xlsx_ordinaryTickets->read(row, 3);
			if (line.isNull() == true) {
				line = lastLine;
			}
			///*调试用*/
			//lineString = line.toString();
			//lastLineString = lastLine.toString();
			//stationString = station.toString();
			///*******/
		}
		metroLineGroup[i].stationsNum = metroLineGroup[i].lineStations.length();

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




//void PaymentCalculation::setSingleCost(float cost)
//{
//	orderInformation.singlePrice = cost;
//}
//
void PaymentCalculation::calculateSingleCost(void)
{
	orderInformation.singlePrice = calculateOneTicket(orderInformation.startLine,
		orderInformation.startStation,
		orderInformation.endLine,
		orderInformation.endStation,
		orderInformation.isBusinessTicket
	);
}

void PaymentCalculation::calculateTotalCost(void)
{
	calculateSingleCost();
	orderInformation.totalPrice = orderInformation.singlePrice * orderInformation.ticketNum;
}

float PaymentCalculation::getSingleCost(void)
{
	calculateSingleCost();
	return orderInformation.singlePrice;
}

float PaymentCalculation::getTotalCost(void)
{
	calculateTotalCost();
	return orderInformation.totalPrice;
}

void PaymentCalculation::receiveOrderInformation(QString startLine, QString startStation, QString endLine, QString endStation, int ticketNum, bool isBusinessTicket)
{
	orderInformation.startLine = startLine;
	orderInformation.startStation = startStation;
	orderInformation.endLine = endLine;
	orderInformation.endStation = endStation;
	orderInformation.ticketNum = ticketNum;
	orderInformation.isBusinessTicket = isBusinessTicket;
	getSingleCost();
	getTotalCost();
	emit sendPrice(orderInformation.singlePrice, orderInformation.totalPrice);

}

