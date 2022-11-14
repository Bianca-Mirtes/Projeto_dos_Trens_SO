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

    int valorSemaforo1;
    int valorSemaforo2;
    int valorSemaforo3;
    int valorSemaforo4;
    int valorSemaforo5;
    int valorSemaforo6;
    int valorSemaforo7;

   public:
    Semaforo();
    sem_t* getSemaforo(int num);
    int getValorSemaforo(int num);
};

#endif