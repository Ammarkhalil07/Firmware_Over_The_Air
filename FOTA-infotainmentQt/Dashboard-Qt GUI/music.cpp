#include "music.h"
#include "ui_music.h"
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
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>

Music::Music(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Music)
{
    ui->setupUi(this);

    // Connect the back button to its slot
    connect(ui->backButton, &QPushButton::clicked, this, &Music::on_backButton_clicked);

    // Populate the list of videos (assuming your list widget is named videoListWidget)
    ui->videoListWidget->addItem("El Araby Group - Ramadan.mp4");
    ui->videoListWidget->addItem("National geographic - Lions fight");
    ui->videoListWidget->addItem("Steve Jobs Talk - Apple Conf.mp4");
    ui->videoListWidget->addItem("El Da7ee7 - world war2.mp4");
    ui->videoListWidget->addItem("Mohamed Henedy - Andaleeb El dokky.mp4");
    ui->videoListWidget->addItem("Fakarouny - Oum Kalthoum Concert 1960.mp4");


    // Assuming you have a QMediaPlayer object for video playback
    player = new QMediaPlayer(this);
    // Connect the itemClicked signal of the listWidget to your custom slot
    connect(ui->videoListWidget, &QListWidget::itemClicked, this, &Music::onListItemClicked);

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

Music::~Music()
{
    delete ui;
}

void Music::on_backButton_clicked()
{
    this->close();
}
// Custom slot function to handle list item clicks
void Music::onListItemClicked(QListWidgetItem *item) {
    // Check which item was clicked
    if (item->text() == "EL Araby Group - advertisement Ramadan.mp3") {
        // Play specific video for Item 1
        QString videoFilePath = "/home/media/Araby  group.mp3";
        // QString videoFilePath = "/home/ibrahim/Downloads/Araby  group.mp3";

        playVideo(videoFilePath);
    } else if (item->text() == "Asala Sora Menak - El Araby Group Ramadan.mp3") {
        // Play specific video for Item 2
        QString videoFilePath = "/home/media/Asala.mp3";
        // QString videoFilePath = "/home/ibrahim/Downloads/Asala.mp3";

        playVideo(videoFilePath);
    }
    else if (item->text() == "Hussien El Jasmy - ser el sa3ada.mp3") {
        // Play specific video for Item 3
        QString videoFilePath = "/home/media/Ser el sa3ada.mp3";
        // QString videoFilePath = "/home/ibrahim/Downloads/Ser el sa3ada.mp3";

        playVideo(videoFilePath);
    }
    else if (item->text() == "Amr Diab - Elly Benna La7za Helwa.mp3") {
        // Play specific video for Item 4
        QString videoFilePath = "/home/media/Elly benna.mp3";
        // QString videoFilePath = "/home/ibrahim/Downloads/Elly benna.mp3";

        playVideo(videoFilePath);
    }
    else if (item->text() == "Mahmoud El Esseily - Ana Ebn Masr.mp3") {
        // Play specific video for Item 5
        QString videoFilePath = "/home/media/Ana Ebn Masr.mp3";
        // QString videoFilePath = "/home/ibrahim/Downloads/Ana Ebn Masr.mp3";

        playVideo(videoFilePath);
    }
    else if (item->text() == "Hamza Namera - Dary ya Albi.mp3") {
        // Play specific video for Item 6
        QString videoFilePath = "/home/media/Dary ya alby.mp3";
        // QString videoFilePath = "/home/ibrahim/Downloads/Dary ya alby.mp3";

        playVideo(videoFilePath);
    }
}
// Function to play video
void Music::playVideo(const QString &filePath) {
    // Set media content and start playback
    player->setMedia(QUrl::fromLocalFile(filePath));
    player->play();
}

