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

    //各页面指针进堆叠
    stackedWidget->insertWidget(INDEX_OF_STARTPAGE, startPage);
    stackedWidget->insertWidget(INDEX_OF_HOMEPAGE, homePage);

    //设置
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    stackedWidget->setCurrentWidget(startPage);


    connect(startPage, &StartPage::enterSystem, [=]() {
        stackedWidget->setCurrentWidget(homePage);
        });

}

Widget::~Widget()
{
    delete ui;
}


