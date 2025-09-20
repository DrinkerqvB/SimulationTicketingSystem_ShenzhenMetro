#pragma once

#include <QWidget>
#include "ui_BuyPage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BuyPageClass; };
QT_END_NAMESPACE

class BuyPage : public QWidget
{
	Q_OBJECT

public:
	BuyPage(QWidget *parent = nullptr);
	~BuyPage();

private:
	Ui::BuyPageClass *ui;
};

