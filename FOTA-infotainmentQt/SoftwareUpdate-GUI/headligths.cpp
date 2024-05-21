#include "headligths.h"
#include "ui_headligths.h"
#include "LedDriver.h"
#include "mainwindow.h"
#include <QDebug>
Headligths::Headligths(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Headligths)
{
    ui->setupUi(this);
    this->showFullScreen();
    updateBackground();

    ui->tesla->setStyleSheet("QLabel { image: url(:/assets/teslaCar.png); border: none; }");
    // ui->left->setCheckable(true);
    // ui->right->setCheckable(true);


}

Headligths::~Headligths()
{
    delete ui;
}

void Headligths::resizeEvent(QResizeEvent *event) {
    QDialog::resizeEvent(event);
    // Update the background whenever the window is resized
    updateBackground();
}

void Headligths::updateBackground() {
    QPixmap bkgnd("/home/root/black2.jpg");

    // Scale the pixmap to cover the full window, ignoring the aspect ratio
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}


void Headligths::on_back_clicked()
{

    this->hide();

}

void Headligths::on_right_clicked()

{   Basic_Character_Devices dev0("/dev/LED_0");

    dev0.WriteFile("1");
    QPixmap blueflashUp("/home/root/pressed-bg-up.png");
    ui->label_3->setPixmap(blueflashUp);
    ui->label_3->show();
}


void Headligths::on_left_clicked()
{
    Basic_Character_Devices dev1("/dev/LED_1");
    QPixmap blueflashUp("/home/root/pressed-bg-up.png");
    ui->label_4->setPixmap(blueflashUp);
    dev1.WriteFile("1");
    ui->label_3->show();
}


void Headligths::on_pushButton_clicked()
{
    Basic_Character_Devices dev1("/dev/LED_1");
    dev1.WriteFile("0");
    ui->label_3->clear();
    Basic_Character_Devices dev0("/dev/LED_0");

    dev0.WriteFile("0");

    ui->label_4->clear();
}

