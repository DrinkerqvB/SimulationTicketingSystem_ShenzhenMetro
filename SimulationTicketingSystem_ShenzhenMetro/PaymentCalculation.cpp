#include "PaymentCalculation.h"

QString url1 = "./CostSheet/普通车厢票价表.xlsx";
QString url2 = "./CostSheet/商务车厢票价表.xlsx";


PaymentCalculation::PaymentCalculation():QObject()
{
	
	financialRecord = QSqlDatabase::addDatabase("QMYSQL"); //加载MySQL驱动
	//database.setHostName("localhost");
	financialRecord.setHostName("127.0.0.1");
	financialRecord.setPort(3306);
	financialRecord.setDatabaseName("financialRecord");
	financialRecord.setUserName(DATABASE_USERNAME);
	financialRecord.setPassword(DATABASE_PASSWORD);
	bool ok = financialRecord.open();

	QSqlQuery financialRecord_query;
	//financialRecord_query.exec();
	financialRecord_query.exec("use financialRecord;");
	financialRecord_query.exec("CREATE TABLE IF NOT EXISTS `record`(\
		SerialNumber varchar(50) primary key,\
		OrderDatetime datetime,\
		EnterStationDatetime datetime,\
		ExitStationDatetime datetime,\
		StartLine varchar(50),\
		StartStation varchar(50),\
		EndLine varchar(50),\
		EndStation varchar(50),\
		TicketType varchar(50),\
		TicketID varchar(50),\
		TicketNum int,\
		SinglePrice float,\
		TotalPrice float,\
		ModeOfPayment varchar(50)\
	); ");
	
	

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

	/*调试用*/
	QString lineString = line.toString();
	QString lastLineString = lastLine.toString();
	QString stationString = station.toString();
	/*******/

	for (int i = 0; i < NUM_OF_METROLINES; i++) {

		lastLine = line = Xlsx_ordinaryTickets->read(row, 1);
		station = Xlsx_ordinaryTickets->read(row, 3);
		int countStationNum;

		/*调试用*/
		lineString = line.toString();
		lastLineString = lastLine.toString();
		stationString = station.toString();
		/*******/

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
			/*调试用*/
			lineString = line.toString();
			lastLineString = lastLine.toString();
			stationString = station.toString();
			/*******/
		}
		metroLineGroup[i].stationsNum = metroLineGroup[i].lineStations.length();

	}
}

QStringList PaymentCalculation::searchStationForLine(QString station)
{
	QStringList answer;
	QString tempLineName,lastLineName;
	QString tempStationName;
	/*for (int row = 4;tempStationName.isNull()!=true; row++) {
		tempLineName = Xlsx_ordinaryTickets->read(row, 1).toString();
		tempStationName = Xlsx_ordinaryTickets->read(row, 3).toString();
		if (tempStationName == station) {
			answer.append(tempLineName);
		}
	}*/

	int row = 4;
	do {
		lastLineName = tempLineName;
		tempLineName = Xlsx_ordinaryTickets->read(row, 1).toString();
		if (tempLineName.isNull() == true) {
			tempLineName = lastLineName;
		}
		
		tempStationName = Xlsx_ordinaryTickets->read(row, 3).toString();
		if (tempStationName == station) {
			answer.append(tempLineName);
		}
		row++;
	} while (tempStationName.isNull() != true);

	emit sendStationLines(answer);
	return answer;
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
	delete[] posStart;
	delete[] posEnd;

	return cost;
	
}

int* PaymentCalculation::findStation(QString line, QString station)
{
	int* pos = new int[2];
	QVariant data_station, data_line, data_lastLine;
	QString debug_data_station, debug_data_line;
	int row=3, col=3;
	//读取行值
	do {
		row++;
		data_lastLine = data_line;
		data_station = Xlsx_ordinaryTickets->read(row, 3);
		data_line = Xlsx_ordinaryTickets->read(row, 1);
		if (data_line.isNull() == true) {
			data_line = data_lastLine;
		}

		///******************/
		//debug_data_line = data_line.toString();
		//debug_data_station = data_station.toString();
		///*******************/
		
	} while (!(data_station.isNull() == true || (data_station.toString() == station && data_line.toString() == line)));

	pos[0] = row;

	//读取列值
	do {
		col++;
		data_lastLine = data_line;
		data_station = Xlsx_ordinaryTickets->read(3, col);
		data_line = Xlsx_ordinaryTickets->read(1, col);
		if (data_line.isNull() == true) {
			data_line = data_lastLine;
		}

		///******************/
		//debug_data_line = data_line.toString();
		//debug_data_station = data_station.toString();
		///*******************/

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
	orderInformation.singlePrice=getSingleCost();
	orderInformation.totalPrice=getTotalCost();
	emit sendPrice(orderInformation.singlePrice, orderInformation.totalPrice);

}

void PaymentCalculation::insertIntoDatabase(void)
{
	//暂时用支付时间代替进站时间
	//把OrderInformation中的东西分字段插入数据表

	// 暂时用支付时间代替进站时间
	QDateTime enterStationTime = QDateTime::currentDateTime();

	orderInformation.serialNumber = generateSerialNumber();
	orderInformation.orderDatetime = enterStationTime;

	QSqlQuery query;
	QString sql =
		"INSERT INTO record ("
		"SerialNumber, OrderDatetime, EnterStationDatetime, ExitStationDatetime, "
		"StartLine, StartStation, EndLine, EndStation, "
		"TicketType, TicketID, TicketNum, SinglePrice, TotalPrice, ModeOfPayment"
		") VALUES ("
		":serialNumber, :orderDatetime, :enterStationDatetime, NULL, "
		":startLine, :startStation, :endLine, :endStation, "
		":ticketType, :ticketID, :ticketNum, :singlePrice, :totalPrice, :modeOfPayment"
		")";

	query.prepare(sql);
	query.bindValue(":serialNumber", orderInformation.serialNumber);
	query.bindValue(":orderDatetime", enterStationTime);
	query.bindValue(":enterStationDatetime", enterStationTime);
	query.bindValue(":startLine", orderInformation.startLine);
	query.bindValue(":startStation", orderInformation.startStation);
	query.bindValue(":endLine", orderInformation.endLine);
	query.bindValue(":endStation", orderInformation.endStation);
	query.bindValue(":ticketType", orderInformation.ticketType);
	query.bindValue(":ticketID", orderInformation.ticketID);
	query.bindValue(":ticketNum", orderInformation.ticketNum);
	query.bindValue(":singlePrice", orderInformation.singlePrice);
	query.bindValue(":totalPrice", orderInformation.totalPrice);
	query.bindValue(":modeOfPayment", orderInformation.modeOfPayment);
	query.exec();

	/*if (!query.exec()) {
		qDebug() << "插入数据失败：" << query.lastError().text();
		qDebug() << "SQL:" << query.lastQuery();
	}
	else {
		qDebug() << "数据插入成功，影响行数：" << query.numRowsAffected();
	}*/
	
}

QString PaymentCalculation::generateSerialNumber()
{
	// 格式：年月日时分秒毫秒 + 随机数
	QDateTime currentTime = QDateTime::currentDateTime();
	currentTime.setTimeZone(QTimeZone("Asia/Shanghai"));
	QString timePart = currentTime.toString("yyyyMMddhhmmsszzz");
	QString randomPart = QString::number(QRandomGenerator::global()->bounded(1000, 9999));

	return timePart + randomPart;
}
