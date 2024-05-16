#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "LedDriver.h"

#define LOW  "0"
#define HIGH "1"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->showFullScreen();
    updateBackground();
    ui->tesla->setStyleSheet("QLabel { image: url(:/assets/teslaCar.png); border: none; }");

    Basic_Character_Devices LED_0("/dev/LED_0"); //RDWR
    Basic_Character_Devices LED_1("/dev/LED_1"); //RDWR
    Basic_Character_Devices LED_2("/dev/LED_2"); //RDWR
    LED_0.WriteFile(LOW);
    LED_1.WriteFile(LOW);
    LED_2.WriteFile(LOW);
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

void MainWindow::on_back_clicked()
{
    this->close();

}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{




        // 1- make an object for each LED
        Basic_Character_Devices LED_0("/dev/LED_0"); //RDWR
        Basic_Character_Devices LED_1("/dev/LED_1"); //RDWR
        Basic_Character_Devices LED_2("/dev/LED_2"); //RDWR
        int maxValue = 100;

        // Calculate the range for each LED
        int range = maxValue / 3;

        // Turn off all LEDs initially
        LED_0.WriteFile(LOW);
        LED_1.WriteFile(LOW);
        LED_2.WriteFile(LOW);
        QPixmap blueflashUp("/home/root/pressed-bg-up.png");

        // Determine which LED(s) should be on based on the slider value
        if (value >= 0 && value < range) {
            // Turn on LED 0
            LED_0.WriteFile(HIGH);

            ui->label_4->setPixmap(blueflashUp);
            ui->label_5->setPixmap(blueflashUp);
            ui->label_4->show();
            ui->label_5->show();
        } else if (value >= range && value < 2 * range) {
            // Turn on LED 1
            LED_0.WriteFile(HIGH);
            LED_1.WriteFile(HIGH);

            ui->label_3->setPixmap(blueflashUp);
            ui->label_6->setPixmap(blueflashUp);
            ui->label_3->show();
            ui->label_6->show();
        } else {
            // Turn on LED 2
            LED_0.WriteFile(HIGH);
            LED_1.WriteFile(HIGH);
            LED_2.WriteFile(HIGH);
            ui->label_4->setPixmap(blueflashUp);
            ui->label_5->setPixmap(blueflashUp);
            ui->label_4->show();
            ui->label_5->show();
            ui->label_3->setPixmap(blueflashUp);
            ui->label_6->setPixmap(blueflashUp);
            ui->label_3->show();
            ui->label_6->show();
        }
        if(value==0)
        {
            LED_0.WriteFile(LOW);
            LED_1.WriteFile(LOW);
            LED_2.WriteFile(LOW);
            ui->label_4->clear();
            ui->label_5->clear();
            ui->label_3->clear();
            ui->label_6->clear();
        }
}


void MainWindow::on_pushButton_clicked()
{
    Basic_Character_Devices LED_0("/dev/LED_0"); //RDWR
    Basic_Character_Devices LED_1("/dev/LED_1"); //RDWR
    Basic_Character_Devices LED_2("/dev/LED_2"); //RDWR
    LED_0.WriteFile(LOW);
    LED_1.WriteFile(LOW);
    LED_2.WriteFile(LOW);
    ui->label_4->hide();
    ui->label_5->hide();

    ui->label_3->hide();
    ui->label_6->hide();
}

