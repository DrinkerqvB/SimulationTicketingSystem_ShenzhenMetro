#pragma once

#include <QtWidgets/QWidget>
#include "ui_Widget.h"
#include <QStackedWidget>


#include "HomePage.h"
#include "BuyPage.h"
#include "PayPage.h"
#include "MapSearchPage.h"

#define INDEX_OF_WIDGET 0


QT_BEGIN_NAMESPACE
namespace Ui { class WidgetClass; };
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::WidgetClass *ui;
    QStackedWidget* stackedWidget;//堆叠页面

    HomePage* homePage;//系统首页
    
    BuyPage* buyPage;//购票页面
    PayPage* payPage;//支付页面
    
    MapSearchPage* mapSearchPage;//地图查询页面
    


signals:



private slots:
    void on_pushButton_enterSystem_clicked(void);
    void on_pushButton_exitSystem_clicked(void);


};

