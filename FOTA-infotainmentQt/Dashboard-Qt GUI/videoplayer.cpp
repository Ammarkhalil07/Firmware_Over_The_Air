#include "videoplayer.h"
#include "ui_videoplayer.h"

Videoplayer::Videoplayer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Videoplayer)
{
    ui->setupUi(this);
}

Videoplayer::~Videoplayer()
{
    delete ui;
}
