#pragma once

#include <QWidget>
#include "ui_PayPage.h"

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
};

