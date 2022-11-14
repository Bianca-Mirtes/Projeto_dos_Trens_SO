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
}

// Função a ser executada após executar trem->START
void Trem::run() {
    while (true) {
        switch (ID) {
            case 1:  // Trem 1
                qInfo() << "Velocidade Trem 1: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 30 && x < 470) {
                    if (x == 450 && semaforos->getValorSemaforo(1) == 0) {
                        sem_wait(semaforos->getSemaforo(1));
                    }

                    x += 10;
                } else if (x == 470 && y < 230) {
                    y += 10;
                } else if (x > 230 && y == 230) {
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal
                }
                break;
            case 2:  // Trem 2
                // qInfo() << "Teste do getValue: " << valorSemaforo;
                // qInfo() << "Velocidade trem 2: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 30 && x < 710) {
                    x += 10;
                } else if (x == 710 && y < 230) {
                    y += 10;
                } else if (x > 470 && y == 230) {
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 3:  // Trem 3
                // qInfo() << "Velocidade trem 3: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 350) {
                    x += 10;
                } else if (x == 350 && y < 410) {
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
                // qInfo() << "Velocidade trem 4: " << this->velocidade;
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
                // qInfo() << "Velocidade trem 5: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 830) {
                    x += 10;
                } else if (x == 830 && y < 410) {
                    y += 10;
                } else if (x > 590 && y == 410) {
                    x -= 10;
                } else {
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
