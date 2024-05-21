#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <signal.h>
#include <csignal>
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
        static MainWindow* instance(); // Declare a static function to get the instance of MainWindow
    /*******RESIZING WINDOW*****/
    void updateBackground();
    void resizeEvent(QResizeEvent *event);
    /****************************/
    void logMessage(const QString &message);
    static void customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

    /*************Check wifi*****************/
    int check_wifi();
    /*************CHECK NOTIFICATIONS****************/
    int check_notify();



    /************Check Download ******************/
    int check_download();
    /**************MQTT******************************/
    /*******************NOtify handler********************/
    static void signal_handler(int signum);
    /*******************Download handler********************/
    static void signal_handler1(int signum);


    // static void signalHandler(int signum);
    //     void handleSignal(int signum);

    static unsigned char notify_flag;
    static unsigned char download_flag;
    unsigned char noti=0;
    ~MainWindow();

private slots:
    void on_close_clicked();

    void on_Download_clicked(bool checked);

    void on_wifi_clicked(bool checked);

    void on_pushButton_clicked(bool checked);
    void on_noti_clicked(bool checked);


    void on_back_clicked();


private:
    Ui::MainWindow *ui;
    // Headligths *headlight;
signals:
    void signalReceived(int signum); // Declare the signal here
};
#endif // MAINWINDOW_H
