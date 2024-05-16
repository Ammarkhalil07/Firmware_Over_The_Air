#ifndef HEADLIGTHS_H
#define HEADLIGTHS_H

#include <QDialog>

namespace Ui {
class Headligths;
}

class Headligths : public QDialog
{
    Q_OBJECT

public:
    explicit Headligths(QWidget *parent = nullptr);
    /*******RESIZING WINDOW*****/
    void updateBackground();
    // void resizeEvent(QResizeEvent *event);
    void resizeEvent(QResizeEvent *event);


    ~Headligths();


private slots:


    void on_back_clicked();

    void on_right_clicked();

    void on_left_clicked();

    void on_pushButton_clicked();

private:
    Ui::Headligths *ui;
};

#endif // HEADLIGTHS_H
