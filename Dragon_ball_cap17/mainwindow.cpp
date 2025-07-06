#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_cerrar_clicked()
{
    close();
}


void MainWindow::on_iniciar_clicked()
{
    Niveles *nivel = new Niveles;
    close();
    nivel->show();
}

