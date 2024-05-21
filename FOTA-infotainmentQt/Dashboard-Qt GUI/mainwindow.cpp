#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <qpalette.h>
#include <QPalette>
#include <QMovie>
#include <QPalette>
#include <QResizeEvent>
#include <QDateTime>
#include <QTimer>
#include <QDebug>
#include <QProcess>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bluetoothIcon(":/media/media/wifi(1).png");
    QPixmap settingIcon(":/media/media/settings_icon.png");
    QPixmap videoIcon(":/media/media/music-app.png");
    QPixmap musicIcon(":/media/media/video(1).png");
    // QPixmap bluetoothIcon("/home/media/wifi(1).png");
    // QPixmap settingIcon("/home/media/setting.png");
    // QPixmap videoIcon("/home/media/music-app.png");
    // QPixmap musicIcon("/home/media/video(1).png");
    // Scale the icons to a larger size
    int iconSize = 100; // Set your desired icon size
    bluetoothIcon = bluetoothIcon.scaled(QSize(iconSize, iconSize), Qt::KeepAspectRatio);
    settingIcon = settingIcon.scaled(QSize(iconSize, iconSize), Qt::KeepAspectRatio);
    videoIcon = videoIcon.scaled(QSize(iconSize, iconSize), Qt::KeepAspectRatio);
    musicIcon = musicIcon.scaled(QSize(iconSize, iconSize), Qt::KeepAspectRatio);
    // Set icons to buttons
    ui->button_bluetooth->setIcon(QIcon(bluetoothIcon));
    ui->button_setting->setIcon(QIcon(settingIcon));
    ui->button_video->setIcon(QIcon(videoIcon));
    ui->button_music->setIcon(QIcon(musicIcon));
    // Set button icon size policy to fixed size
    ui->button_bluetooth->setIconSize(QSize(iconSize, iconSize));
    ui->button_setting->setIconSize(QSize(iconSize, iconSize));
    ui->button_video->setIconSize(QSize(iconSize, iconSize));
    ui->button_music->setIconSize(QSize(iconSize, iconSize));

    video = nullptr;
    music = nullptr;
    setting = nullptr ;
    timer = new QTimer (this);
    connect(timer , SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
    /*Enabling and disabling Wi-Fi*/
    connect(ui->button_bluetooth, &QPushButton::clicked, this, &MainWindow::toggleWifi);
    this->showFullScreen();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    // Update the background whenever the window is resized
    updateBackground();
}
void MainWindow::updateBackground() {
    QPixmap bkgnd(":/media/media/black2.jpg");
    // QPixmap bkgnd("/home/media/black2.jpg");
    if (bkgnd.isNull()) {
        qDebug() << "Failed to load background image";
        return;
    }
    // Scale the pixmap to cover the full window, ignoring the aspect ratio
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

// void MainWindow::on_button_bluetooth_clicked()
// {
//     QMessageBox::information(this,"title","Wifi is on");
// }
void MainWindow::on_button_music_clicked(bool checked)
{
    if (!music) {
        music = new Music(this); // Create a new Music dialog
        music->show(); // Show the Music dialog
        this->hide(); // Hide the MainWindow
        connect(music, &Music::finished, this, &MainWindow::musicClosed);
    }
}
void MainWindow::musicClosed()
{
    delete music; // Delete the Video dialog object
    music = nullptr; // Reset videoDialog pointer to nullptr
    this->show(); // Show the MainWindow
}

void MainWindow::on_button_video_clicked()
{
    if (!video) {
        video = new Video(this); // Create a new Video dialog
        video->show(); // Show the Video dialog
        this->hide(); // Hide the MainWindow
        connect(video, &Video::finished, this, &MainWindow::videoClosed);
    }
}
void MainWindow::videoClosed()
{
    delete video; // Delete the Video dialog object
    video = nullptr; // Reset videoDialog pointer to nullptr
    this->show(); // Show the MainWindow
}
void MainWindow::on_button_setting_clicked(bool checked)
{
    QString binaryPath = "/usr/local/bin/Raspi4";
    // QString binaryPath = "/home/ibrahim/projects/Demo/build/Desktop_Qt_5_15_2_GCC_64bit-Debug/Demo";
    QProcess process;
    // Set the binary to execute
    process.setProgram(binaryPath);
    // Start the process
    process.start();
    // this->hide(); // Hide the MainWindow
    // Wait for the process to finish (optional)
    if(process.waitForFinished())
    {
        this->show();
    }
    connect(setting, &Setting::finished, this, &MainWindow::settingClosed);

}
void MainWindow::settingClosed()
{
    delete setting; // Delete the Video dialog object
    setting = nullptr; // Reset Setting pointer to nullptr
    this->show(); // Show the MainWindow
}
void MainWindow::myfunction()
{
    QTime time = QTime::currentTime();
    QString time_text = time.toString("               hh : mm : ss");
    ui->label_timer->setText(time_text);
}


bool MainWindow::isWifiEnabled() {
    QProcess process;
    process.start("nmcli radio wifi");
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    return output.trimmed() == "enabled";
}

void MainWindow::setWifiEnabled(bool enabled) {
    QProcess process;
    if (enabled) {
        process.start("nmcli radio wifi on");
    } else {
        process.start("nmcli radio wifi off");
    }
    process.waitForFinished();
}

void MainWindow::toggleWifi() {
    bool enabled = isWifiEnabled();
    setWifiEnabled(!enabled);

    if (!enabled) {
        QMessageBox::information(this, "Wi-Fi", "Wi-Fi has been enabled.");
    } else {
        QMessageBox::information(this, "Wi-Fi", "Wi-Fi has been disabled.");
    }
}
