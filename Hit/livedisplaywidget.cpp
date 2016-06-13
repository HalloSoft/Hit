#include "livedisplaywidget.h"
#include "ui_livedisplaywidget.h"

#include <QDebug>

LiveDisplayWidget::LiveDisplayWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LiveDisplayWidget)
{
    ui->setupUi(this);
}

LiveDisplayWidget::~LiveDisplayWidget()
{
    delete ui;
}

void LiveDisplayWidget::setCamera(const QCameraInfo &cameraInfo)
{
    camera = new QCamera(cameraInfo);
    Q_CHECK_PTR(camera);

    connect(camera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(updateCameraState(QCamera::State)));
    //connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(displayCameraError()));

    camera->setViewfinder(ui->liveView);
    camera->start();

    //ui->statusBar->showMessage(cameraInfo.description()); //TODO
}

void LiveDisplayWidget::updateCameraState(QCamera::State state)
{
    qDebug() << "Camera-State:" << state;

}
