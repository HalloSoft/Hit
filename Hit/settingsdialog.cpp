#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QDir>
#include <QSettings>

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    readSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::writeSettings()
{
    QSettings settings(this);
    settings.beginGroup(groupName);

    settings.endGroup();
}

void SettingsDialog::readSettings()
{
    QSettings settings(this);
    settings.beginGroup(groupName);
    ui->lineEditImagePath->setText(settings.value("ImagePath", QDir::tempPath()).toString());

    settings.endGroup();
}
