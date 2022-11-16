#ifndef SEMAFORO_H
#define SEMAFORO_H

#include <semaphore.h>

#include <QDebug>

class Semaforo {
   private:
    sem_t semaforo_1; // semaforo 1
    sem_t semaforo_2; // semaforo 2
    sem_t semaforo_3; // semaforo 3
    sem_t semaforo_4; // semaforo 4
    sem_t semaforo_5; // semaforo 5
    sem_t semaforo_6; // semaforo 6
    sem_t semaforo_7; // semaforo 7

    int valorSemaforo1; // Valor do semaforo 1
    int valorSemaforo2; // Valor do semaforo 2
    int valorSemaforo3; // Valor do semaforo 3
    int valorSemaforo4; // Valor do semaforo 4
    int valorSemaforo5; // Valor do semaforo 5
    int valorSemaforo6; // Valor do semaforo 6
    int valorSemaforo7; // Valor do semaforo 7

   public:
    /**
    * Construtor da classe semaforo. Responsável por inicializar os semaforo.
    */
    Semaforo();

    /**
     * Getter para os semaforos
     * @param num número que determina o semaforo desejado [1, 7].
     * @return o semaforo desejado
    */
    sem_t* getSemaforo(int num);

    /**
     * Getter para os valores dos semaforos
     * @param num número que determina o semaforo desejado [1, 7].
     * @return o valor do semaforo desejado
    */
    int getValorSemaforo(int num);
};

#endif  // SEMAFORO_H
