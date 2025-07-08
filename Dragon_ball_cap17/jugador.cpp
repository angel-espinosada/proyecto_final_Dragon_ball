#include "jugador.h"

Jugador::Jugador(QObject *parent)
    : QObject(parent), QGraphicsPixmapItem()
{

    // Cargar imagen del jugador (usa tu sprite real)
    spriteSheet = QPixmap(":/Momento 2/Sprites/Sprite_ejemplo.png");

    // Tamaño de cada frame individual (ajusta según tu sprite)
    frameWidth = spriteSheet.width() / 2;
    frameHeight = spriteSheet.height() / 2;
    currentFrame = 0;

    // Timer para animar
    animationTimer = new QTimer(this);
    connect(animationTimer, &QTimer::timeout, this, &Jugador::actualizarAnimacion);
    animationTimer->start(200); // Cambia de frame cada 200ms

    actualizarAnimacion(); // Mostrar el primer frame
    QPixmap frame = spriteSheet.copy(0, 0, frameWidth, frameHeight);
    setPos(100, 300);

    setPixmap(frame);

    // Posición inicial
    setPos(100, 300);

    // Inicializar atributos
    vidas = 3;

}

void Jugador::actualizarAnimacion()
{
    int column = currentFrame % 2;
    int row = currentFrame / 2;
    QPixmap frame = spriteSheet.copy(column * frameWidth, row * frameHeight, frameWidth, frameHeight);
    setPixmap(frame);  // ESTA es la línea correcta
    currentFrame = (currentFrame + 1) % 4;
}
