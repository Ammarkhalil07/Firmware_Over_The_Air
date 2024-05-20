#ifndef MUSIC_H
#define MUSIC_H
#include <QDialog>
#include <QListWidgetItem>
#include <QListWidget>
#include <QMediaPlayer>
#include </home/ibrahim/Qt/5.15.2/gcc_64/include/QtMultimediaWidgets/QVideoWidget>
#include <QCoreApplication>
#include <QProcess>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QtMultimediaWidgets>
#include <QtCore>
#include <QtGui>
#include <QVideoWidget>
#include <QUrl>
#include <QDialog>

namespace Ui {
class Music;
}

class Music : public QDialog
{
    Q_OBJECT

public:
    explicit Music(QWidget *parent = nullptr);
    ~Music();

private slots:
    void on_backButton_clicked();
    void onListItemClicked(QListWidgetItem *item);
    void playVideo(const QString &filePath);


private:
    Ui::Music *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget ;

};

#endif // MUSIC_H
