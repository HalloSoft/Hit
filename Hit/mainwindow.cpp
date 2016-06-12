#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>
#include <QKeyEvent>
#include <QMessageBox>

Q_DECLARE_METATYPE(QCameraInfo)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    camera(0)
{
    ui->setupUi(this);

    //Camera devices:
    QActionGroup *videoDevicesGroup = new QActionGroup(this);
    videoDevicesGroup->setExclusive(true);

    foreach (const QCameraInfo &cameraInfo, QCameraInfo::availableCameras())
    {
        QAction *videoDeviceAction = new QAction(cameraInfo.description(), videoDevicesGroup);
        videoDeviceAction->setCheckable(true);
        videoDeviceAction->setData(QVariant::fromValue(cameraInfo));
        if (cameraInfo == QCameraInfo::defaultCamera())
            videoDeviceAction->setChecked(true);

        ui->menuDevices->addAction(videoDeviceAction);
    }

    setCamera(QCameraInfo::defaultCamera());
}

MainWindow::~MainWindow()
{
    delete ui;
    delete camera;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    bool isFullscreen;

    switch (event->key())
    {
    case Qt::Key_F10:
        isFullscreen = ui->viewfinder->isFullScreen();
        ui->viewfinder->setFullScreen(!isFullscreen);
        event->accept();
        break;
    default:
        QMainWindow::keyPressEvent(event);
        break;
    }
}

void MainWindow::updateCameraState(QCamera::State state)
{
    qDebug() << "Camera-State:" << state;

}

void MainWindow::displayCameraError()
{
    QMessageBox::warning(this, tr("Camera error"), camera->errorString());
}

void MainWindow::setCamera(const QCameraInfo &cameraInfo)
{
    camera = new QCamera(cameraInfo);
    Q_CHECK_PTR(camera);

    connect(camera, SIGNAL(stateChanged(QCamera::State)), this, SLOT(updateCameraState(QCamera::State)));
    connect(camera, SIGNAL(error(QCamera::Error)), this, SLOT(displayCameraError()));

    camera->setViewfinder(ui->viewfinder);
    camera->start();

    ui->statusBar->showMessage(cameraInfo.description());
}
