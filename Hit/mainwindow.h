#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QCameraInfo>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event);

private slots:
    void updateCameraState(QCamera::State state);
    void displayCameraError();
    void showAboutBox();
    void showSettings();

protected:
    void closeEvent(QCloseEvent *event);


private:
    Ui::MainWindow *ui;

    void setCamera(const QCameraInfo &cameraInfo);

    void writeSettings();
    void readSettings();
};

#endif // MAINWINDOW_H
