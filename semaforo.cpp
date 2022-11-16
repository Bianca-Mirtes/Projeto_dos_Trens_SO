#include "semaforo.h"

Semaforo::Semaforo() {
    sem_init(&semaforo_1, 0, 1);
    sem_init(&semaforo_2, 0, 1);
    sem_init(&semaforo_3, 0, 1);
    sem_init(&semaforo_4, 0, 1);
    sem_init(&semaforo_5, 0, 1);
    sem_init(&semaforo_6, 0, 1);
    sem_init(&semaforo_7, 0, 1);
}

sem_t* Semaforo::getSemaforo(int num) {
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

int Semaforo::getValorSemaforo(int num) {
    switch (num) {
        case 1:
            sem_getvalue(&semaforo_1, &valorSemaforo1);
            return valorSemaforo1;
            break;
        case 2:
            sem_getvalue(&semaforo_2, &valorSemaforo2);
            return valorSemaforo2;
            break;
        case 3:
            sem_getvalue(&semaforo_3, &valorSemaforo3);
            return valorSemaforo3;
            break;
        case 4:
            sem_getvalue(&semaforo_4, &valorSemaforo4);
            return valorSemaforo4;
            break;
        case 5:
            sem_getvalue(&semaforo_5, &valorSemaforo5);
            return valorSemaforo5;
            break;
        case 6:
            sem_getvalue(&semaforo_6, &valorSemaforo6);
            return valorSemaforo6;
            break;
        case 7:
            sem_getvalue(&semaforo_7, &valorSemaforo7);
            return valorSemaforo7;
            break;
        default:
            break;
    }
}