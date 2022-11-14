#include "semaforo.h"

Semaforo::Semaforo() {
    sem_init(&semaforo_1, 0, 0);
    sem_init(&semaforo_2, 0, 0);
    sem_init(&semaforo_3, 0, 0);
    sem_init(&semaforo_4, 0, 0);
    sem_init(&semaforo_5, 0, 0);
    sem_init(&semaforo_6, 0, 0);
    sem_init(&semaforo_7, 0, 0);
}

int Semaforo::teste() {
    qInfo() << "teste semaforo";
}