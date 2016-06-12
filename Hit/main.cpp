#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QSharedMemory>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedMemory sharedMemory;
    sharedMemory.setKey("HallosInspectionTool");

    if (!sharedMemory.create(1))
    {
        QMessageBox::warning(0,
                             QApplication::tr("Warning!"),
                             QApplication::tr("An instance of HIT is running!") );

        exit(0); // Exit already a process running
    }

    MainWindow w;
    w.show();

    return a.exec();
}
