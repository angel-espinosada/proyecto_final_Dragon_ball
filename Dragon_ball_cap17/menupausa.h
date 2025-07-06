#ifndef MENUPAUSA_H
#define MENUPAUSA_H

#include <QWidget>
#include <QMessageBox>
#include <QDialog>
#include "niveles.h"


namespace Ui {
class MenuPausa;
}

class MenuPausa : public  QDialog
{
    Q_OBJECT

public:
    explicit MenuPausa(QWidget *parent = nullptr);
    ~MenuPausa();
    QString opcionSeleccionada;

private slots:


    void on_pausar_clicked();

    void on_cerrar_clicked();

    void on_guardar_clicked();


    void on_menuanterior_clicked();



    void on_continuar_clicked();

private:
    Ui::MenuPausa *ui;
};

#endif // MENUPAUSA_H
