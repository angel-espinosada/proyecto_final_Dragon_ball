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
   QPixmap vida(":/Momento 2/Sprites/vidas.png");
    ui->vida1->setPixmap(vida);
    ui->vida2->setPixmap(vida);
    ui->vida3->setPixmap(vida);
    qDebug() << "Imagen GGGG";
    //Fondp
    scene = new QGraphicsScene(this);                   // 1. Crear la escena
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    QPixmap originalImage(":/Momento 2/Sprites/fondonivel1.PNG");
    if (originalImage.isNull()) {
        qDebug() << "Imagen no cargada";
        return; // Evita crash
    }
    QPixmap mirroredImage = originalImage.transformed(QTransform().scale(-1,1));
    bgImage1=new QGraphicsPixmapItem(originalImage);
    bgImage2=new QGraphicsPixmapItem(mirroredImage);
    bgImage1->setPos(0,0);
    bgImage2->setPos(originalImage.width(),0);
    scene->addItem(bgImage1);
    scene->addItem(bgImage2);

    //movimiento

    fondoTimer = new QTimer(this);
    connect(fondoTimer, SIGNAL(timeout()), this,SLOT(bgmov()));
    fondoTimer->start(20);

}

Nivel_1::~Nivel_1()
{
    delete ui;
}

void Nivel_1::mostrarMenuPausa()
{

    qDebug() << "Antes de pausar, activo:" << bgTimer->isActive(); // Debe dar true
    fondoTimer->stop();
    MenuPausa menu;
    menu.setTimer(fondoTimer);
    menu.exec();

    qDebug() << "Antes de pausar, activo:" << fondoTimer->isActive();
     fondoTimer->stop();
    if (menu.opcionSeleccionada == "continuar") {
        fondoTimer->start(20);
        // No hacer nada, solo continuar
    } else if (menu.opcionSeleccionada == "cerrar") {
        this->close();
        Niveles *niveles = new Niveles;
        niveles->show();
    }
}

void Nivel_1::bgmov()
{
    bgImage1->setX(bgImage1->x()-5.0);
    bgImage2->setX(bgImage2->x()-5.0);

    //if (bgImage1->x()<=800-bgImage1->pixmap().width())
    //bgImage1->setX(0);
    if (bgImage1->x()<=-bgImage1->pixmap().width())
        bgImage1->setX(bgImage2->x()+bgImage2->pixmap().width());

    if (bgImage2->x()<=-bgImage2->pixmap().width())
        bgImage2->setX(bgImage1->x()+bgImage2->pixmap().width());

}

