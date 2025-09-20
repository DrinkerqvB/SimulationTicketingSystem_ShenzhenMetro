#include "Widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetClass())
{
    ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);
    homePage = new HomePage;
    buyPage = new BuyPage;
    payPage = new PayPage;
    mapSearchPage = new MapSearchPage;

    


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_enterSystem_clicked(void)
{

}

void Widget::on_pushButton_exitSystem_clicked(void)
{
    this->close();
}