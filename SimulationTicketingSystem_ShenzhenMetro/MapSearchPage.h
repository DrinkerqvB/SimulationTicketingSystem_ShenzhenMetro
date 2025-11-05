#pragma once

#include <QWidget>
#include "ui_MapSearchPage.h"

#define INDEX_OF_MAPSEARCHPAGE 4

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

signals:
	void searchLines(QString station);
	void gotoBuyPage(void);
	void returnHome(void);

public slots:
	void receiveAndShowStationLines(QStringList stationLines);

private slots:
	void on_pushButton_search_clicked(void);
	void on_pushButton_buyTicket_clicked(void);
	void on_pushButton_returnHome_clicked(void);

};

