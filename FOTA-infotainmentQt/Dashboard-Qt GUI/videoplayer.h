#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QDialog>

namespace Ui {
class Videoplayer;
}

class Videoplayer : public QDialog
{
    Q_OBJECT

public:
    explicit Videoplayer(QWidget *parent = nullptr);
    ~Videoplayer();

private:
    Ui::Videoplayer *ui;
};

#endif // VIDEOPLAYER_H
