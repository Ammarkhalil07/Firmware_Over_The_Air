#ifndef VIDEO_H
#define VIDEO_H

#include "qmediaplayer.h"
#include <QDialog>
#include <QListWidgetItem>
#include <QListWidget>
#include </home/ibrahim/Qt/5.15.2/gcc_64/include/QtMultimediaWidgets/QVideoWidget>


namespace Ui {
class Video;
}

class Video : public QDialog
{
    Q_OBJECT

public:
    explicit Video(QWidget *parent = nullptr);
    ~Video();

private slots:
    void on_backButton_clicked();
    void onListItemClicked(QListWidgetItem *item);
    void playVideo(const QString &filePath);

private:
    Ui::Video *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget ;
};

#endif // VIDEO_H
