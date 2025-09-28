#pragma once

#include <QWidget>
#include "ui_PayPage.h"

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

signals:
	void cancelPay(void);

private slots:
	void on_pushButton_cancelPay_clicked(void);

};

