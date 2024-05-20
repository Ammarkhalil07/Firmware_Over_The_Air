#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "music.h"
#include "video.h"
#include "setting.h"
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /*******RESIZING WINDOW*****/
    void updateBackground();
    void resizeEvent(QResizeEvent *event);
    /****************************/

public slots:
    void videoClosed();
    void musicClosed();
    void settingClosed();
    void myfunction();



private slots:
    // void on_button_bluetooth_clicked();
    void on_button_music_clicked(bool checked);
    void on_button_video_clicked();
    void on_button_setting_clicked(bool checked);
    /**********************/
    void toggleWifi();
    /*********************/

private:
    Ui::MainWindow *ui;
    QPixmap background; // Declare background variable
    /*music Ptr*/
    Music *music;
    /*Video ptr*/
    Video *video;
    /*Setting Ptr*/
    Setting *setting;

    QTimer *timer;
    /************************/
    bool isWifiEnabled();
    void setWifiEnabled(bool enabled);
    /****************************/
};
#endif // MAINWINDOW_H
