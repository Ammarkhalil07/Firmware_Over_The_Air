#include "headlights.h"
#include "./ui_headlights.h"
#include "LedDriver.h"
#include <QPixmap>
#include <QPushButton>
#include <QResizeEvent>

Headlights::Headlights(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Headlights)
{
    ui->setupUi(this);
    this->showFullScreen();
    updateBackground();
    ui->tesla->setStyleSheet("QLabel { image: url(:/assets/teslaCar.png); border: none; }");

}

Headlights::~Headlights()
{
    delete ui;
}

void Headlights::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    // Update the background whenever the window is resized
    updateBackground();
}

void Headlights::updateBackground() {
    QPixmap bkgnd("/home/root/black2.jpg");

    // Scale the pixmap to cover the full window, ignoring the aspect ratio
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}




void Headlights::on_pushButton_clicked()
{
    Basic_Character_Devices dev1("/dev/LED_1");
    dev1.WriteFile("0");
    Basic_Character_Devices dev0("/dev/LED_0");

    dev0.WriteFile("0");
    ui->label_3->clear();

    ui->label_4->clear();
    ui->label_5->clear();
    ui->label_6->clear();


}


void Headlights::on_left_clicked()
{
    Basic_Character_Devices dev1("/dev/LED_1");
    dev1.WriteFile("1");
    QPixmap blueflashUp("/home/root/pressed-bg-up.png");
    ui->label_4->setPixmap(blueflashUp);
    ui->label_5->setPixmap(blueflashUp);
    ui->label_4->show();
    ui->label_5->show();
}


void Headlights::on_right_clicked()
{
    Basic_Character_Devices dev0("/dev/LED_0");

    dev0.WriteFile("1");
    QPixmap blueflashUp("/home/root/pressed-bg-up.png");
    ui->label_3->setPixmap(blueflashUp);
    ui->label_3->show();
    ui->label_6->setPixmap(blueflashUp);
    ui->label_6->show();
}


void Headlights::on_back_clicked()
{
    this->close();

}

