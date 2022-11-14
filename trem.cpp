#include "trem.h"

#include <QtCore>

#define N_TRENS 5;
#define N_REGIOES 7;

#define REGIAO_1 0;
#define REGIAO_2 1;
#define REGIAO_3 2;
#define REGIAO_4 3;
#define REGIAO_5 4;
#define REGIAO_6 5;
#define REGIAO_7 6;

// Construtor
Trem::Trem(int ID, int x, int y, Semaforo *&semaforos) {
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 100;
    this->semaforos = semaforos;
}

// Função a ser executada após executar trem->START
void Trem::run() {
    while (true) {
        switch (ID) {
            case 1:  // Trem 1
                if (velocidade == 200){
                    break;
                }
                if (y == 30 && x < 470){
                    // semaforo 1
                    if (x == 450 && semaforos->getValorSemaforo(1) > 0) {
                        sem_wait(semaforos->getSemaforo(1));
                    } else if (x == 450 && semaforos->getValorSemaforo(1) == 0) {
                        break;
                    }
                    x += 10;
                } else if (x == 470 && y < 230){
                    y += 10;
                } else if (x > 230 && y == 230){
                    // semaforo 1
                    if (x == 470 && semaforos->getValorSemaforo(1) == 0){
                        sem_post(semaforos->getSemaforo(1));
                    }
                    // semaforo 2
                    if(x == 370 && semaforos->getValorSemaforo(2) > 0){
                        sem_wait(semaforos->getSemaforo(2));
                    } else if (x == 370 && semaforos->getValorSemaforo(2) == 0) {
                        break;
                    }
                    x -= 10;
                } else {
                    // semaforo 2
                    if(y == 220 && semaforos->getValorSemaforo(2) == 0){
                        sem_post(semaforos->getSemaforo(2));
                    }
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal
                }
                break;
            case 2:  // Trem 2
                if (velocidade == 200) {
                    break;
                }
                if (y == 30 && x < 710) {
                    if (x == 470 && semaforos->getValorSemaforo(1) == 0) {
                        sem_post(semaforos->getSemaforo(1));
                    }
                    x += 10;
                } else if (x == 710 && y < 230){
                    // semaforo 5
                    if (y == 210 && semaforos->getValorSemaforo(5) > 0) {
                        sem_wait(semaforos->getSemaforo(5));
                    } else if (y == 210 && semaforos->getValorSemaforo(5) == 0) {
                        break;
                    }
                    y += 10;
                } else if (x > 470 && y == 230){
                    // semaforo 5
                    if(x == 580 && semaforos->getValorSemaforo(5) == 0){
                        sem_post(semaforos->getSemaforo(5));
                    }
                    // semaforo 1
                    if (x == 490 && semaforos->getValorSemaforo(1) > 0) {
                        sem_wait(semaforos->getSemaforo(1));
                    } else if (x == 490 && semaforos->getValorSemaforo(1) == 0) {
                        break;
                    }
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 3:  // Trem 3
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 350){
                    if (x == 210 && semaforos->getValorSemaforo(2) > 0) {
                        sem_wait(semaforos->getSemaforo(2));
                    } else if (x == 210 && semaforos->getValorSemaforo(2) == 0) {
                        break;
                    }
                    x += 10;
                } else if (x == 350 && y < 410) {
                    if(y == 240 && semaforos->getValorSemaforo(2) == 0){
                        sem_post(semaforos->getSemaforo(2));
                    }
                    y += 10;
                } else if (x > 110 && y == 410) {
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 4:  // Trem 4
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 590) {
                    x += 10;
                } else if (x == 590 && y < 410) {
                    y += 10;
                } else if (x > 350 && y == 410) {
                    x -= 10;
                } else {
                    y -= 10;
                }

                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 5:  // Trem 5
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 830){
                    if(x == 720 && semaforos->getValorSemaforo(5) == 0){
                        sem_post(semaforos->getSemaforo(5));
                    }
                    x += 10;
                } else if (x == 830 && y < 410) {
                    y += 10;
                } else if (x > 590 && y == 410) {
                    x -= 10;
                } else {
                    if(x == 590 && y == 250 && semaforos->getValorSemaforo(5) > 0){
                        sem_wait(semaforos->getSemaforo(5));
                    } else if (x == 590 && y == 250 && semaforos->getValorSemaforo(5) == 0) {
                        break;
                    }
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            default:
                break;
        }
        msleep(velocidade);
    }
}

void Trem::setVelocidade(int valor) {
    this->velocidade = valor;
}
