#ifndef LIVEDISPLAYWIDGET_H
#define LIVEDISPLAYWIDGET_H

#include <QWidget>

#include <QCameraInfo>

namespace Ui {
class LiveDisplayWidget;
}

class LiveDisplayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LiveDisplayWidget(QWidget *parent = 0);
    ~LiveDisplayWidget();

    void setCamera(const QCameraInfo &cameraInfo);

private slots:
    void updateCameraState(QCamera::State state);
private:
    Ui::LiveDisplayWidget *ui;

    QCamera *camera = 0;
};

#endif // LIVEDISPLAYWIDGET_H
