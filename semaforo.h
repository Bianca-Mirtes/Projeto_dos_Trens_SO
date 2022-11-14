#ifndef SEMAFORO_H
#define SEMAFORO_H
#include <semaphore.h>

#include <QDebug>

class Semaforo {
   private:
    sem_t semaforo_1;
    sem_t semaforo_2;
    sem_t semaforo_3;
    sem_t semaforo_4;
    sem_t semaforo_5;
    sem_t semaforo_6;
    sem_t semaforo_7;

   public:
    Semaforo();
    int teste();
    sem_t getSemaforo(int num);
};

#endif