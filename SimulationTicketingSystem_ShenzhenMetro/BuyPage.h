#pragma once

#include <QWidget>
#include "ui_BuyPage.h"

#include "PaymentCalculation.h"

#define INDEX_OF_BUYPAGE 2

QT_BEGIN_NAMESPACE
namespace Ui { class BuyPageClass; };
QT_END_NAMESPACE

class BuyPage : public QWidget
{
	Q_OBJECT

public:
	BuyPage(QWidget *parent = nullptr);
	~BuyPage();

	void loadComboBox(MetroLine* metroLineGroup);
	void connectToPaymentCalculation(void);

	MetroLine* metroLineGroup;

private:
	Ui::BuyPageClass *ui;

	//PaymentCalculation* costCalculator = nullptr;//票价计算（后端）

signals:
	void gotoPayPage(void);
	void returnHomePage(void);
	void stationChanged(QString startLine, QString startStation, QString endLine, QString endStation, int ticketNum, bool isBusinessTicket);


public slots:
	void receivePrice(float singlePrice, float totalPrice);

private slots:
	void on_pushButton_gotoPayPage_clicked(void);
	void on_pushButton_returnHomePage_clicked(void);
	void on_comboBox_startLine_currentTextChanged(const QString& text);
	void on_comboBox_endLine_currentTextChanged(const QString& text);
	void on_comboBox_startStation_currentTextChanged(const QString& text);
	void on_comboBox_endStation_currentTextChanged(const QString& text);
	void on_spinBox_numOfTicket_valueChanged(int i);
	void on_checkBox_isBusiness_toggled(bool checked);
	//void setCostCalculator(PaymentCalculation* costCalculator);

};

