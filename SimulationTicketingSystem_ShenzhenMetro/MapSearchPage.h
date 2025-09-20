#pragma once

#include <QWidget>
#include "ui_MapSearchPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MapSearchPageClass; };
QT_END_NAMESPACE

class MapSearchPage : public QWidget
{
	Q_OBJECT

public:
	MapSearchPage(QWidget *parent = nullptr);
	~MapSearchPage();

private:
	Ui::MapSearchPageClass *ui;
};

