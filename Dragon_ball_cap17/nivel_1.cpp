#include "nivel_1.h"
#include "ui_nivel_1.h"

void Nivel_1::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape) {
        mostrarMenuPausa();
    }
}

void Nivel_1::closeEvent(QCloseEvent *event)
{
    MenuPausa menu;
    menu.exec();

    if (menu.opcionSeleccionada == "continuar") {
        event->ignore(); // Cancela el cierre
    } else if (menu.opcionSeleccionada == "cerrar") {
        event->accept(); // Cierra y vuelve al menú
        Niveles *niveles = new Niveles;
        niveles->show();
    } else {
        event->ignore(); // Por defecto, cancelar
    }
}

Nivel_1::Nivel_1(QWidget *parent)
    : QWidget(parent)

    , ui(new Ui::Nivel_1)

{
    ui->setupUi(this);
    setWindowTitle("Nivel 1 - Entrenamiento de Goku");
}

Nivel_1::~Nivel_1()
{
    delete ui;
}

void Nivel_1::mostrarMenuPausa()
{
    MenuPausa menu;
    menu.exec();

    if (menu.opcionSeleccionada == "continuar") {
        // No hacer nada, solo continuar
    } else if (menu.opcionSeleccionada == "cerrar") {
        this->close();
        Niveles *niveles = new Niveles;
        niveles->show();
    }
}

