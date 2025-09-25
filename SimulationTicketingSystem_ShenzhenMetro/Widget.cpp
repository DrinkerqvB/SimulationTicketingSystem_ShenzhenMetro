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

    //Widget* startPage = new Widget;
    homePage = new HomePage;
    buyPage = new BuyPage;
    payPage = new PayPage;
    mapSearchPage = new MapSearchPage;

    //stackedWidget->insertWidget(INDEX_OF_WIDGET, this);
    stackedWidget->insertWidget(INDEX_OF_HOMEPAGE, homePage);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(stackedWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    setLayout(layout);

    stackedWidget->setCurrentWidget(homePage);

    setWindowTitle("地铁售票系统");
    resize(800, 600); // 设置初始窗口大小
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_enterSystem_clicked(void)
{
    stackedWidget->setCurrentWidget(homePage);
}

void Widget::on_pushButton_exitSystem_clicked(void)
{
    this->close();
}