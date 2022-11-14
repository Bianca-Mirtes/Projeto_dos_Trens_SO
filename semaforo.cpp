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
sem_t Semaforo::getSemaforo(int num) {
    switch (num) {
        case 1:
            return &semaforo_1;
            break;
        case 2:
            return &semaforo_2;
            break;
        case 3:
            return &semaforo_3;
            break;
        case 4:
            return &semaforo_4;
            break;
        case 5:
            return &semaforo_5;
            break;
        case 6:
            return &semaforo_6;
            break;
        case 7:
            return &semaforo_7;
            break;

        default:
            break;
    }
}
