#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QCameraInfo>
#include <QKeyEvent>
#include <QMessageBox>
#include <QSettings>
#include <QSplashScreen>

Q_DECLARE_METATYPE(QCameraInfo)

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    readSettings();

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

    //setCamera(QCameraInfo::defaultCamera());
//    QPixmap splashPixmap(":/pic/icons/Slpash");
//    Q_ASSERT(!splashPixmap.isNull());

//    QSplashScreen splash(splashPixmap);
//    splash.show();
//    qApp->processEvents();
//    splash.showMessage(QApplication::tr("Loading ..."));
//    qApp->processEvents();

    ui->liveView->setCamera(QCameraInfo::defaultCamera());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    bool isFullscreen; Q_UNUSED(isFullscreen);

    switch (event->key())
    {
    case Qt::Key_F10:
//        isFullscreen = ui->viewfinder->isFullScreen();
//        ui->viewfinder->setFullScreen(!isFullscreen);
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
    QMessageBox::warning(this, tr("Camera error"), QString());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    writeSettings();
}

void MainWindow::setCamera(const QCameraInfo &cameraInfo)
{


    ui->statusBar->showMessage(cameraInfo.description());
}

void MainWindow::writeSettings()
{
    QSettings settings(this);
    settings.beginGroup("MainWindow");
    settings.setValue("size", size());
      settings.setValue("pos", pos());
    settings.endGroup();
}

void MainWindow::readSettings()
{
    QSettings settings(this);
    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint()); 	settings.endGroup();
}
