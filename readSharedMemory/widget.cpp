#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("读出共享内存");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::readSharedMemory()
{
//-----------------------读出共享内存------------------------//

    readmemory = new QSharedMemory("lv5y9K3Q7ALwscME",this);

    if(!readmemory->attach()){
        qDebug() << "attach failed.";
        return;
    }

    readmemory->lock();

    char* addr = static_cast<char*>(readmemory->data());
    char* out = new char[static_cast<unsigned int>(readmemory->size())];
    memcpy(out, addr, static_cast<size_t>(readmemory->size()));
//    qDebug()<<"out data:"<<out;
    ui->listWidget->addItem(out);
    NDIData data;
    data.JsontoNDIData(out);
    data.printData();
    if (data.NDIdataIsValid)
    {
        ui->listWidget->addItem(QString::number(data.line1.p1.x));
        ui->listWidget->addItem(QString::number(data.line1.p1.y));
        ui->listWidget->addItem(QString::number(data.line1.p1.z));

        ui->listWidget->addItem(QString::number(data.line1.p2.x));
        ui->listWidget->addItem(QString::number(data.line1.p2.y));
        ui->listWidget->addItem(QString::number(data.line1.p2.z));

    }
    else
    {
        ui->listWidget->addItem("collect error");
    }


    readmemory->unlock();

    readmemory->detach();
}

void Widget::on_pushButton_clicked()
{
    readSharedMemory();
}
