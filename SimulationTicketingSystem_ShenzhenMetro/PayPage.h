#pragma once

#include <QWidget>
#include <QGraphicsPixmapItem>
#include "ui_PayPage.h"

#include "PaymentCalculation.h"

#define INDEX_OF_PAYPAGE 3

QT_BEGIN_NAMESPACE
namespace Ui { class PayPageClass; };
QT_END_NAMESPACE

class PayPage : public QWidget
{
	Q_OBJECT

public:
	PayPage(QWidget *parent = nullptr);
	~PayPage();

private:
	Ui::PayPageClass *ui;

	QPixmap* QRcode_WeixinPay;
	QGraphicsPixmapItem* QRcode_WeixinPay_pixmapItem;
	QGraphicsScene* scene_map_WeixinPay;

	QPixmap* QRcode_AliPay;
	QGraphicsPixmapItem* QRcode_AliPay_pixmapItem;
	QGraphicsScene* scene_map_AliPay;

	double totalPrice;
	double needToPay;
	double hasPaid;

	//PaymentCalculation* costCalculator = nullptr;//票价计算（后端）

protected:
	//void resizeEvent(QResizeEvent* event) override;

signals:
	void cancelPay(void);
	void paySuccessful(double change);

public slots:
	void receivePrice(float singlePrice, float totalPrice);

private slots:
	void on_pushButton_cancelPay_clicked(void);
	void on_pushButton_paySuccessful_clicked(void);
	void on_doubleSpinBox_hasPaid_valueChanged(double d);
	
	//void setCostCalculator(PaymentCalculation* costCalculator);

};

