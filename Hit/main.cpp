#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QSharedMemory>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("Scary HalloSoft");
    QCoreApplication::setOrganizationDomain("hallosoft.de");
    QCoreApplication::setApplicationName("Hallos Inspection Tool");

    // Version
    QString versionString = QString("%1.%2.%3.%4").arg(VERSION_MAJOR).arg(VERSION_MINOR).arg(VERSION_REVISION).arg(VERSION_BUILD);
    a.setApplicationVersion(versionString);

    qDebug() << "Version" << versionString;

    // splash screen
    QPixmap splashPixmap(":/pic/icons/Slpash.png");
    Q_ASSERT(!splashPixmap.isNull());


    QSharedMemory sharedMemory;
    sharedMemory.setKey("HallosInspectionTool");

    if (!sharedMemory.create(1))
    {
        qDebug() << "Shared memory:" << sharedMemory.errorString();

        QMessageBox::warning(0,
                             QApplication::tr("Warning!"),
                             QApplication::tr("An instance of HIT is running!") );

        exit(0); // Exit, a process is already running
    }

    QSplashScreen splash(splashPixmap);
    splash.show();
    qApp->processEvents();
    splash.showMessage(QString("Version %1").arg(versionString), Qt::AlignBottom);
    qApp->processEvents();

    MainWindow w;
    w.show();

    splash.finish(&w);

    return a.exec();
}
