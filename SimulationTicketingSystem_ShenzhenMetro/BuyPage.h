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

	MetroLine* metroLineGroup;

private:
	Ui::BuyPageClass *ui;


signals:
	void gotoPayPage(void);
	void returnHomePage(void);

private slots:
	void on_pushButton_gotoPayPage_clicked(void);
	void on_pushButton_returnHomePage_clicked(void);
	void on_comboBox_startLine_currentTextChanged(const QString& text);
	void on_comboBox_endLine_currentTextChanged(const QString& text);

};

