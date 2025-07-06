#ifndef NIVEL_1_H
#define NIVEL_1_H

#include <QWidget>
#include <QMessageBox>
#include <QCloseEvent>
#include "niveles.h"
#include "menupausa.h"
#include<QGraphicsScene>
#include<QTimer>
#include <QGraphicsPixmapItem>
#include<QDebug>
#include <QPixmap>
namespace Ui {
class Nivel_1;
}

class Nivel_1 : public QWidget
{
    Q_OBJECT
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void closeEvent(QCloseEvent *event) override;

public:
    explicit Nivel_1(QWidget *parent = nullptr);
    ~Nivel_1();

private:
    Ui::Nivel_1 *ui;
    void mostrarMenuPausa();
    QGraphicsScene *scene;
    QGraphicsPixmapItem *bgImage1,*bgImage2;
    QTimer *bgTimer, *timer,*asTimer;

private slots:
    void bgmov();
};

#endif // NIVEL_1_H
