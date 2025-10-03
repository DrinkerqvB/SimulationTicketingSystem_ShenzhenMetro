#include "Widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetClass())
{
    //ui->setupUi(this);

    stackedWidget = new QStackedWidget(this);

    //给各页面分配内存
    startPage = new StartPage;
    homePage = new HomePage;
    buyPage = new BuyPage;
    payPage = new PayPage;
    mapSearchPage = new MapSearchPage;

    //
    costCalculator = new PaymentCalculation;

    //各页面指针压进堆叠
    stackedWidget->insertWidget(INDEX_OF_STARTPAGE, startPage);
    stackedWidget->insertWidget(INDEX_OF_HOMEPAGE, homePage);
    stackedWidget->insertWidget(INDEX_OF_BUYPAGE, buyPage);
    stackedWidget->insertWidget(INDEX_OF_PAYPAGE, payPage);
    stackedWidget->insertWidget(INDEX_OF_MAPSEARCHPAGE, mapSearchPage);

    //设置
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);
    resize(800, 600);

    stackedWidget->setCurrentWidget(startPage);

    

    // 信号与槽连接处
    connect(startPage, &StartPage::enterSystem, [=]() {
        stackedWidget->setCurrentWidget(homePage);
        costCalculator->readXlsxs();
        });
    connect(startPage, &StartPage::exitSystem, [=]() {
        this->close();
        });
    connect(homePage, &HomePage::enterBuyPage, [=]() {
        stackedWidget->setCurrentWidget(buyPage);
        });
    connect(homePage, &HomePage::enterMapSearchPage, [=]() {
        stackedWidget->setCurrentWidget(mapSearchPage);
        });
    connect(homePage, &HomePage::exitSystem, [=]() {
        this->close();
        });
    connect(buyPage, &BuyPage::gotoPayPage, [=]() {
        stackedWidget->setCurrentWidget(payPage);
        
        });
    connect(buyPage, &BuyPage::returnHomePage, [=]() {
        stackedWidget->setCurrentWidget(homePage);
        });
    connect(payPage, &PayPage::cancelPay, [=]() {
        stackedWidget->setCurrentWidget(buyPage);
        });
    connect(costCalculator, &PaymentCalculation::xlsxLoaded, this, [=](bool isXlsxLoaded) {
        if (isXlsxLoaded == true) {
            QMessageBox::information(this, "信息", QString("表格读取成功"));
        }
        else {
            QMessageBox::warning(this, "信息", "表格读取失败");
        }
        });
    connect(costCalculator, &PaymentCalculation::Debug, this, [=](QVariant var1, QVariant var2, QVariant var3, QVariant var4) {
        QMessageBox::information(this, "信息", var1.toString() + var2.toString() +QString('\n') + var3.toString() + var4.toString());
        });

    //调试用
    //connect(buyPage->paymentCalculator,)
    


}

Widget::~Widget()
{
    delete ui;
}


