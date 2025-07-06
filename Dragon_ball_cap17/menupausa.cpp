#include "menupausa.h"
#include "ui_menupausa.h"

MenuPausa::MenuPausa(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MenuPausa)
{
    ui->setupUi(this);
    setWindowModality(Qt::ApplicationModal); // Pausa el juego hasta que se cierre este diálogo
    setWindowTitle("Menú de Pausa");
    ui->pausar->setEnabled(true);
}

void MenuPausa::setTimer(QTimer *timer)
{
    fondoTimer = timer;
    qDebug() << "[MenuPausa] Recibido bgTimer:" << fondoTimer;
}

MenuPausa::~MenuPausa()
{
    delete ui;
}

void MenuPausa::on_pausar_clicked()
{
    if (fondoTimer && fondoTimer->isActive()) {
        fondoTimer->stop();
        qDebug() << "Temporizador detenido desde menú.";
    } else {
        qDebug() << "Timer no recibido o ya detenido.";
    }

    QMessageBox::information(this, "Pausa", "El juego está en pausa.");
    ui->pausar->setEnabled(false);
}



void MenuPausa::on_cerrar_clicked()
{
    this->opcionSeleccionada = "cerrar";
    close(); // Cerramos el diálogo
}


void MenuPausa::on_guardar_clicked()
{

}



void MenuPausa::on_menuanterior_clicked()
{
    Niveles *w =new Niveles;
    close();
    w->show();
}




void MenuPausa::on_continuar_clicked()
{
    this->opcionSeleccionada = "continuar";
    close();
}

