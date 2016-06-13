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

    QPixmap splashPixmap(":/pic/icons/Slpash.jpg");
    Q_ASSERT(!splashPixmap.isNull());

    QSplashScreen splash(splashPixmap);
    splash.show();
    qApp->processEvents();
    splash.showMessage(QApplication::tr("Loading ..."));
    qApp->processEvents();

    MainWindow w;
    w.show();

    splash.finish(&w);

    return a.exec();
}
