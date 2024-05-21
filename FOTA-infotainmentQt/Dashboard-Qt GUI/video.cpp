// video.cpp
#include "video.h"
#include "ui_video.h"
#include "mainwindow.h"
#include <QMediaPlayer>
#include <QLabel>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtGui>
#include <QVideoWidget>
#include <QUrl>
#include <QPalette>
#include <qpalette.h>
#include <QResizeEvent>

Video::Video(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Video)
{
    ui->setupUi(this);
    // Connect the back button to its slot
    connect(ui->backButton, &QPushButton::clicked, this, &Video::on_backButton_clicked);
    // Populate the list of videos (assuming your list widget is named videoListWidget)
    ui->videoListWidget->addItem("EL Araby Group - advertisement Ramadan.mp3");
    ui->videoListWidget->addItem("Asala Sora Menak - El Araby Group Ramadan.mp3");
    ui->videoListWidget->addItem("Hussien El Jasmy - ser el sa3ada.mp3");
    ui->videoListWidget->addItem("Amr Diab - Elly Benna La7za Helwa.mp3");
    ui->videoListWidget->addItem("Mahmoud El Esseily - Ana Ebn Masr.mp3");
    ui->videoListWidget->addItem("Hamza Namera - Dary ya Albi.mp3");


    // Assuming you have a QMediaPlayer object for video playback
    player = new QMediaPlayer(this);
    // Connect the itemClicked signal of the listWidget to your custom slot
    connect(ui->videoListWidget, &QListWidget::itemClicked, this, &Video::onListItemClicked);
    QPixmap backIcon(":/media/media/back_icon.png");
    // QPixmap backIcon(":/media/media/back_icon.png");
    // Scale icons to fit button size
    backIcon = backIcon.scaled(ui->backButton->size(), Qt::KeepAspectRatio);
    // Set icons to buttons
    ui->backButton->setIcon(QIcon(backIcon));
    // Set button icon size policy to ignore to prevent distortion
    ui->backButton->setIconSize(ui->backButton->size());
    /****************************************/
    QPixmap backwordIcon(":/media/media/backward_icon.png");
    // QPixmap backwordIcon("/home/media/backward_icon.png");
    backwordIcon = backwordIcon.scaled(ui->backwordButton->size(), Qt::KeepAspectRatio);
    ui->backwordButton->setIcon(QIcon(backwordIcon));
    ui->backwordButton->setIconSize(ui->backwordButton->size());
    /******************************************/
    QPixmap stopIcon(":/media/media/stop_icon.png");
    // QPixmap stopIcon("/home/media/stop_icon.png");
    stopIcon = stopIcon.scaled(ui->stopButton->size(), Qt::KeepAspectRatio);
    ui->stopButton->setIcon(QIcon(stopIcon));
    ui->stopButton->setIconSize(ui->stopButton->size());
    /***********************************************/
    QPixmap playIcon(":/media/media/play_icon.png");
    // QPixmap playIcon("/home/media/play_icon.png");
    playIcon = playIcon.scaled(ui->playButton->size(), Qt::KeepAspectRatio);
    ui->playButton->setIcon(QIcon(playIcon));
    ui->playButton->setIconSize(ui->playButton->size());
    /****************************************************/
    QPixmap repeatIcon(":/media/media/repeat_icon.png");
    // QPixmap repeatIcon("/home/media/repeat_icon.png");
    repeatIcon = repeatIcon.scaled(ui->repeatButton->size(), Qt::KeepAspectRatio);
    ui->repeatButton->setIcon(QIcon(repeatIcon));
    ui->repeatButton->setIconSize(ui->repeatButton->size());
    /***************************************************/
    QPixmap forwardIcon(":/media/media/forward_icon.png");
    // QPixmap forwardIcon("/home/media/forward_icon.png");
    forwardIcon = forwardIcon.scaled(ui->forwardButton->size(), Qt::KeepAspectRatio);
    ui->forwardButton->setIcon(QIcon(forwardIcon));
    ui->forwardButton->setIconSize(ui->forwardButton->size());
    /******************************************************/
    this->showFullScreen();
}
Video::~Video()
{
    delete ui;
}

void Video::on_backButton_clicked()
{
    this->close();
}
// Custom slot function to handle list item clicks
void Video::onListItemClicked(QListWidgetItem *item) {
    // Check which item was clicked
    if (item->text() == "EL Araby Group - advertisement Ramadan.mp3") {
        // Play specific video for Item 1
        QString videoFilePath = "/home/ibrahim/Downloads/media/Araby  group.mp3";
        playVideo(videoFilePath);
    } else if (item->text() == "Asala Sora Menak - El Araby Group Ramadan.mp3") {
        // Play specific video for Item 2
        QString videoFilePath = "/home/ibrahim/Downloads/media/Asala.mp3";
        playVideo(videoFilePath);
    }
    else if (item->text() == "Hussien El Jasmy - ser el sa3ada.mp3") {
        // Play specific video for Item 3
        QString videoFilePath = "/home/ibrahim/Downloads/media/Ser el sa3ada.mp3";
        playVideo(videoFilePath);
    }
    else if (item->text() == "Amr Diab - Elly Benna La7za Helwa.mp3") {
        // Play specific video for Item 4
        QString videoFilePath = "/home/ibrahim/Downloads/media/Elly benna.mp3";
        playVideo(videoFilePath);
    }
    else if (item->text() == "Mahmoud El Esseily - Ana Ebn Masr.mp3") {
        // Play specific video for Item 5
        QString videoFilePath = "/home/ibrahim/Downloads/media/Ana Ebn Masr.mp3";
        playVideo(videoFilePath);
    }
    else if (item->text() == "Hamza Namera - Dary ya Albi.mp3") {
        // Play specific video for Item 6
        QString videoFilePath = "/home/ibrahim/Downloads/media/Dary ya alby.mp3";
        playVideo(videoFilePath);
    }
}
// Function to play video
void Video::playVideo(const QString &filePath) {
    // Set media content and start playback
    player->setMedia(QUrl::fromLocalFile(filePath));
    player->play();
}
