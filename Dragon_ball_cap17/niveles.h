#ifndef NIVELES_H
#define NIVELES_H

#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Niveles;
}

class Niveles : public QWidget
{
    Q_OBJECT

public:
    explicit Niveles(QWidget *parent = nullptr);
    ~Niveles();

private slots:
    void on_nivel1_clicked();

    void on_nivel2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::Niveles *ui;
};

#endif // NIVELES_H
