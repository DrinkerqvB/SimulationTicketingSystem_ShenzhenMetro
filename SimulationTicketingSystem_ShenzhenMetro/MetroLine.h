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
	MetroLine();
	~MetroLine();


private:
	QString lineName;
	QString* lineStations;

protected:


};

