#include "aboutbox.h"
#include "ui_aboutbox.h"

AboutBox::AboutBox(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutBox)
{
    ui->setupUi(this);


    QString versionString = QString("%1.%2.%3.%4").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_REVISION).arg(VERSION_BUILD);
    ui->labelVersion->setText(QString("Version %1").arg(versionString));
}

AboutBox::~AboutBox()
{
    delete ui;
}
