#include "PayPage.h"

PayPage::PayPage(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::PayPageClass())
{
	ui->setupUi(this);

	QRcode_WeixinPay = new QPixmap(":/images/icon/微信支付.png");
	QRcode_WeixinPay_pixmapItem = new QGraphicsPixmapItem(*QRcode_WeixinPay);

	QRcode_WeixinPay_pixmapItem->setScale(1);

	scene_map = new QGraphicsScene;
	scene_map->addItem(QRcode_WeixinPay_pixmapItem);
}

PayPage::~PayPage()
{
	delete ui;
}

void PayPage::on_pushButton_cancelPay_clicked(void)
{
	emit cancelPay();
}

//void PayPage::setCostCalculator(PaymentCalculation* costCalculator)
//{
//	this->costCalculator = costCalculator;
//}

void PayPage::receivePrice(float singlePrice, float totalPrice)
{
	ui->lineEdit_totalPayment->setText(QString::number(totalPrice, 'f', 2));
	ui->lineEdit_needToPay->setText(QString::number(totalPrice, 'f', 2));

	*QRcode_WeixinPay = QPixmap(":/images/icon/微信支付.png");
	QRcode_WeixinPay_pixmapItem->setPixmap(*QRcode_WeixinPay);

	QRcode_WeixinPay_pixmapItem->setScale(0.5);

	
	scene_map->addItem(QRcode_WeixinPay_pixmapItem);

	ui->graphicsView_weixinPayQRCode->setScene(scene_map);
	ui->graphicsView_weixinPayQRCode->setDragMode(QGraphicsView::ScrollHandDrag);
	ui->graphicsView_weixinPayQRCode->show();
}

//void PayPage::resizeEvent(QResizeEvent* event)
//{
//	QWidget::resizeEvent(event);
//
//	if (QRcode_WeixinPay_pixmapItem && scene_map->items().contains(QRcode_WeixinPay_pixmapItem)) {
//		// 方法1：使用 fitInView
//		ui->graphicsView_weixinPayQRCode->fitInView(QRcode_WeixinPay_pixmapItem, Qt::KeepAspectRatio);
//
//		// 或者方法2：重新缩放图片
//		// int newWidth = ui->graphicsView->width() - 10; // 留一些边距
//		// QPixmap newPixmap = originalPixmap.scaledToWidth(newWidth, Qt::SmoothTransformation);
//		// pixmapItem->setPixmap(newPixmap);
//	}
//}
