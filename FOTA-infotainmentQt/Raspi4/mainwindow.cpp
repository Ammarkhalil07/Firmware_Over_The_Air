#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QPixmap>
#include <QPushButton>
#include <QResizeEvent>
#include <QTcpSocket>
#include <QTimer>
#include <memory>
#include <QDateTime>

/***************************MY IPC Classes**********************/
#include "src/SharedMemory.hpp"
#include "src/Pipe.hpp"
/**************************************************************/

/*******************************************/
#include "LedDriver.h"
/*****************************************/




#include <QProcess>
#include <QCoreApplication>
#include <QFile>
#include <QMessageBox>
#include <QString>


/******************************************/





MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // if (signal(SIGUSR1, &MainWindow::signalHandler) == SIG_ERR) {
    //     qDebug() << "Failed to register signal handler";
    // }
    // QObject::connect(this, &MainWindow::signalReceived, this, &MainWindow::handleSignal);

    /***************coming signals handlers*****************/
    /**************notification*******************/
    signal(SIGUSR1, signal_handler);
    /**************Existance of downloaded file************/
    signal(SIGUSR2, signal_handler1);







    QTimer *timer;
    // timer = new QTimer(this);
    // timer->setInterval(1000);

    // Create a QTimer instance
    timer = new QTimer(this);

    // Connect the timeout() signal of the QTimer to a slot to check the notify_flag
    QObject::connect(timer, &QTimer::timeout, this, &MainWindow::check_notify);

    // Set the interval to 10 seconds (10,000 milliseconds)
    timer->start(10000); // Start the timer

    QTimer *timer2;
    // timer = new QTimer(this);
    // timer->setInterval(1000);

    // Create a QTimer instance
    timer2 = new QTimer(this);

    // Connect the timeout() signal of the QTimer to a slot to check the notify_flag
    QObject::connect(timer2, &QTimer::timeout, this, &MainWindow::check_download);

    // Set the interval to 10 seconds (10,000 milliseconds)
    timer2->start(10000); // Start the timer

    QTimer *timer3;
    // timer = new QTimer(this);
    // timer->setInterval(1000);

    // Create a QTimer instance
    timer3 = new QTimer(this);

    // Connect the timeout() signal of the QTimer to a slot to check the notify_flag
    QObject::connect(timer2, &QTimer::timeout, this, &MainWindow::check_download);

    // Set the interval to 10 seconds (10,000 milliseconds)
    timer3->start(10000); // Start the timer

    // Set the initial background
    this->showFullScreen();
    updateBackground();

    /***************INSTEAD OF USING PIXMAP***********************************************/
    // QPixmap tesla("/home/root/twing.png");
    // ui->tesla->setPixmap(tesla);
    // ui->tesla->setFixedSize(tesla.size());
    ui->tesla->setStyleSheet("QLabel { image: url(:/assets/twing.png); border: none; }");
    /**************************************************************************************/
    ui->info->setStyleSheet("QLabel { image: url(:/assets/tes.png); border: none; }");


    /***************Check WIFI at first***********************/
    check_wifi();


    /***********logger************************/
    ui->logger->setReadOnly(true);  // Make it read-only
    /**************Redirect logs to qDebug.txt************/
    qInstallMessageHandler(MainWindow::customMessageHandler);
    /*******************************************************/
    ui->logger->hide();
    /****************************/
    ui->Download->hide();
    ui->pushButton->hide();
    ui->waitLabel->hide();
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
    QPixmap bkgnd("/home/root/black2.jpg");

    // Scale the pixmap to cover the full window, ignoring the aspect ratio
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}

void MainWindow::on_close_clicked()
{
    this->close();
}




int MainWindow::check_download()
{
    if(download_flag==1)
    {
        // download_flag=0;

        // ui->Download->hide();

    }
    else
    {
        // download_flag=0;
        return 1;
    }
    return 0;
}


void MainWindow::on_Download_clicked(bool checked)
{
    if(1)
    {
        // /******************CREATE AN INSTANCE OF WRITE SECTION WHICH HAS CHILD PROCESS THE READER THAT SAVES THE CONENT OF SHARED MEMORY*********************/
        // if(check_wifi()==0)
        // {
        //     std::unique_ptr<SharedMemory> writer= std::make_unique<WriteSection>("/home/root/HMI_ECU.hex");

        //     if(writer->write_mem() != 0) {
        //         qDebug() << "Failed to write to shared memory.";
        //         logMessage("qtDebug.txt");
        //     } else {
        //         qDebug() << "Data successfully written to shared memory.";
        //         /**********OPEN FILE & SHOW CONETNT IN PLAINTEXT BOX******************/

        //         logMessage("log.txt");
        //     }
        // }
        // else
        // {
        //     /***nothing***/
        //     QMessageBox::information(this, "WiFi !", "WiFi: Not connected ");

        //     logMessage("qtDebug.txt");
        // }

        MyPipe pipe1("ps | awk '/[c]lient/ {print $1}'");
        int qt_pid = std::stoi(pipe1.print_output());
        kill(qt_pid, SIGUSR1);

        if(download_flag==1)
        {
            QMessageBox::information(this, "Download Success", "Downloading Update");

            // QMessageBox::information(this, "Notification", "Downlaod finished ");
            std::unique_ptr<SharedMemory> writer= std::make_unique<WriteSection>("/tmp/firmwareClient");
            // std::unique_ptr<SharedMemory> writer= std::make_unique<WriteSection>("/usr/local/bin/headlights2");

                if(writer->write_mem() != 0) {
                    qDebug() << "Failed to write to shared memory.";
                    logMessage("qtDebug.txt");
                } else {
                    qDebug() << "Data successfully written to shared memory.";
                    /**********OPEN FILE & SHOW CONETNT IN PLAINTEXT BOX******************/
                    ui->Download->hide();
                    download_flag=0;


                    QTimer *timer3;
                    timer3 = new QTimer(this);
                    timer3->start(20000); // Start the timer
                    QTimer *flash = new QTimer(this);
                    flash->setInterval(500); // Set interval in milliseconds for flashing
                    connect(flash, &QTimer::timeout, this, [=]() {
                        ui->waitLabel->setVisible(!ui->waitLabel->isVisible()); // Toggle visibility
                    });

                    // Start the timer
                    flash->start();
                    connect(timer3, &QTimer::timeout, this, [=]() {
                        // Show the QMessageBox after the delay
                        QMessageBox::information(this, "Update!", "Update is done ");
                        flash->stop();
                        ui->waitLabel->hide();
                        timer3->stop();

                    });
                    logMessage("log.txt");
                }


        }
        else
        {

        }

    }
}
/***********************FUNCTION TO OPEN LOG FILE********************************/
void MainWindow::logMessage(const QString &file_name) {
    QFile file(file_name);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        // ui->logger->setPlainText();
        ui->logger->appendPlainText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, "Error", "Could not open the file for reading.");
    }
}
/************************************************************************************/
/***********************WRITE QT MSGS to qtDebug.txt********************************/
void MainWindow::customMessageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg) {
    static QFile file("qtDebug.txt");
    if (!file.isOpen()) {
        file.open(QIODevice::WriteOnly | QIODevice::Append);
    }

    QTextStream out(&file);
    out << msg << "\n";  // Log message to file with a newline
    file.close();
}
/*************************************************************************************/











void MainWindow::on_wifi_clicked(bool checked)
{
    check_wifi();
    QMessageBox::information(this, "Network", "WiFi Connected ");

    logMessage("qtDebug.txt");
}

int MainWindow::check_wifi()
{
    // std::unique_ptr<QProcess> process = std::make_unique<QProcess>(this);
    // process->start("ifconfig",QStringList() << "wlan0");
    // process->waitForFinished();
    // QString output = process->readAllStandardOutput();
    // // ui->logger->appendPlainText(output);

    /********************TEST MY PIPE**************************/

    MyPipe new_pipe("ifconfig wlan0");
    new_pipe.pipe_command();
    // new_pipe.print_output();
    new_pipe.search_pipe("inet");


    if (new_pipe.search_pipe("inet")) {

        ui->wifi->setStyleSheet("QPushButton { image: url(:/assets/wifi1.png); border: none; background-position: center; }");
        qDebug() << "wifi";



    }
        else
    {
        ui->wifi->setStyleSheet("QPushButton { image: url(:/assets/wifi0.png); border: none; background-position: center; }");
        qDebug() << "no wifi";


        return 1;
    }



    return 0;
}





/*******************************************NOTIFICATIONS AREA******************************/

unsigned char MainWindow::notify_flag=0;
unsigned char MainWindow::download_flag=0;

// void MainWindow::signalHandler(int signum) {
//     emit MainWindow::instance()->signalReceived(signum);
// }
// MainWindow* MainWindow::instance() {
//     static MainWindow mainWindowInstance;
//     return &mainWindowInstance;
// }
// void MainWindow::handleSignal(int signum)
// {
//     qDebug() << "Signal received: " << signum;
//     // Handle the signal here
//     // For example, show a message box
//     QMessageBox::information(this, "Signal Received", "Received signal: " + QString::number(signum));
// }



void MainWindow::signal_handler(int signum) {

    MainWindow::notify_flag=1;
    // check_notify();
    qDebug() << "hello";

}
void MainWindow::signal_handler1(int signum) {

    MainWindow::download_flag=1;

}
/**********************Simulate call back function******************************/
void MainWindow::on_pushButton_clicked(bool checked)
{
    check_notify();

}
/***********************************************************************************/

int MainWindow::check_notify()
{
    if(notify_flag==1)
    {
        ui->noti->setStyleSheet("QPushButton { image: url(:/assets/not1.png); border: none; background-position: center;}");
        QMessageBox::information(this, "Notification", "New Update avaliable ");
        ui->Download->show();
        notify_flag=0;
        noti=1;
    }
    else
    {
        ui->noti->setStyleSheet("QPushButton { image: url(:/assets/not0.png); border: none; background-position: center; }");
        noti=0;
        return 1;
    }
    return 0;
}

void MainWindow::on_noti_clicked(bool checked)
{
    if(noti==1)
    {
        QMessageBox::information(this, "Update!", "1 notification");
        check_notify();

    }
    else
    {
        QMessageBox::information(this, "Notifications", "No notifications");
    }
}


void MainWindow::on_back_clicked()
{
    QString binaryPath = "/usr/local/bin/headlights";
    QProcess process;

    // Set the binary to execute
    process.setProgram(binaryPath);

    // Start the process
    process.start();

    // Wait for the process to finish (optional)
    if(process.waitForFinished())
    {
        this->show();
    }


}





