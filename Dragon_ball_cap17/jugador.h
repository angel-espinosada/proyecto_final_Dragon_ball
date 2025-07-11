#ifndef JUGADOR_H
#define JUGADOR_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QPixmap>


class Jugador : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT


signals:
public:
    Jugador();Jugador(QObject *parent = nullptr);
    void moverIzquierda();
    void moverDerecha();
    void saltar();      // Opcional
    void setVidas(int v);
    int getVidas() const;

private:
    int vidas;
    QPixmap spriteSheet;
    int currentFrame;
    int frameWidth;
    int frameHeight;
    QTimer *animationTimer;
    QTimer *animTimer;
private slots:
    void actualizarAnimacion();
    void actualizarFrame();
};

#endif // JUGADOR_H
