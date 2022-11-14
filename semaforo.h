#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <QDebug>
#include <QThread>
#include <semaphore.h>

class semaforo {
    Q_OBJECT
    private:
        sem_t semaforo_1;
        sem_t semaforo_2;
        sem_t semaforo_3;
        sem_t semaforo_4;
        sem_t semaforo_5;
        sem_t semaforo_6;
        sem_t semaforo_7;

   public:
        void intanciaSemaforo();
        sem_t& getSemaforo(int verif);
};

#endif  // SEMAFORO_H
