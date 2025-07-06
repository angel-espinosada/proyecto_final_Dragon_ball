#include "niveles.h"
#include "ui_niveles.h"

Niveles::Niveles(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Niveles)
{
    ui->setupUi(this);
}

Niveles::~Niveles()
{
    delete ui;
}

void Niveles::on_nivel1_clicked()
{
    Nivel_1 *nivel_1 = new Nivel_1;
    close();
    nivel_1->show();
}


void Niveles::on_nivel2_clicked()
{

}


void Niveles::on_pushButton_3_clicked()
{

}


void Niveles::on_pushButton_clicked()
{
    MainWindow *w = new MainWindow;
    close();
    w->show();
}

