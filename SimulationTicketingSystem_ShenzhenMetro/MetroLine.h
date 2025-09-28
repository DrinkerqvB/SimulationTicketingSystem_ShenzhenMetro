#pragma once

#include <QWidget>

// [0] include QXlsx headers 
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;


class MetroLine
{
public:
	MetroLine(QString name);
	~MetroLine();// 饮者是人握持  ——skylark


private:
	QString lineName;
	QString* lineStations = nullptr;
	int stationsNum;

protected:


};

