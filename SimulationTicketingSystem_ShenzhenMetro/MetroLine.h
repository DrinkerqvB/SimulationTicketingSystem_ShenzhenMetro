#pragma once

#include <QWidget>

// [0] include QXlsx headers 
#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"

#define MAX_NUM_OF_LINE_STATIONS 100

using namespace QXlsx;


class MetroLine
{
public:
	MetroLine();
	~MetroLine();// 饮者是人握持  ——skylark



	QString lineName;
	QString* lineStations = nullptr;
	int stationsNum;

private:

protected:


};

