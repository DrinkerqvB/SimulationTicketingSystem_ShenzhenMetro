#include "Widget.h"

/*
Widget::Widget(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::WidgetClass())
{
    ui->setupUi(this);

    // 1. 创建堆栈窗口并设置为中央部件
    stackedWidget = new QStackedWidget();
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(stackedWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0); // 去除边距
    setLayout(mainLayout);

    // 2. 创建各个页面
    homePage = new HomePage();
    buyPage = new BuyPage();
    payPage = new PayPage();
    mapSearchPage = new MapSearchPage();

    // 3. 添加页面到堆栈窗口（注意不要添加this）
    stackedWidget->addWidget(homePage);
    stackedWidget->addWidget(buyPage);
    stackedWidget->addWidget(payPage);
    stackedWidget->addWidget(mapSearchPage);

    // 4. 设置初始页面
    stackedWidget->setCurrentWidget(homePage);

    // 5. 设置窗口基本属性
    setWindowTitle("地铁售票系统");
    resize(800, 600); // 设置初始窗口大小
}
*/

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


    connect(startPage, &StartPage::enterSystem, [=]() {
        stackedWidget->setCurrentWidget(homePage);
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
            QMessageBox::information(this, "信息", "表格读取成功");
        }
        else {
            QMessageBox::warning(this, "信息", "表格读取失败");
        }
        });

    //调试用
    //connect(buyPage->paymentCalculator,)


}

Widget::~Widget()
{
    delete ui;
}


