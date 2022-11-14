#include "trem.h"

#include <QtCore>

#include "mainwindow.h"

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
    this->velocidade = 50;
}

int Trem::getRegião(int x, int y) {
    if (x == 470 && (y > 30 && y < 230)) {
        return REGIAO_1;
    }
    if (y == 230 && (x > 210 && x < 350)) {
        return REGIAO_2;
    }
    if (y == 230 && (x > 350 && x < 470)) {
        return REGIAO_3;
    }
    if (y == 230 && (x > 470 && x < 590)) {
        return REGIAO_4;
    }
    if (y == 230 && (x > 590 && x < 710)) {
        return REGIAO_5;
    }
    if (x == 350 && (y > 230 && y < 410)) {
        return REGIAO_6;
    }
    if (x == 590 && (y > 230 && y < 410)) {
        return REGIAO_7;
    }
}

// Função a ser executada após executar trem->START
void Trem::run() {
    while (true) {
        switch (ID) {
            case 1:  // Trem 1
                // qInfo() << getRegião(470, 90);
                if (velocidade == 200) {
                    break;
                }
                if (y == 30 && x < 470) {
                    // if (x == 450) {
                    //     if (getValorSemaforo(&semaforo_1) > 0) {
                    //         qInfo() << "GetValorSemaforo: " << getValorSemaforo(&semaforo_1);
                    //         break;
                    //     }
                    // }
                    x += 10;
                } else if (x == 470 && y < 230) {
                    y += 10;
                } else if (x > 230 && y == 230) {
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade != 100) {
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
                    // if (x == 490 && valorSemaforo > 0) {
                    //     qInfo() << "Saiu do Ponto Crítico T2";
                    //     sem_wait(&semaforo_1);
                    // }
                    x += 10;
                } else if (x == 710 && y < 230) {
                    y += 10;
                } else if (x > 470 && y == 230) {
                    // if (x == 490) {
                    //     qInfo() << "Entrou no Ponto Crítico T2";
                    //     sem_post(&semaforo_1);
                    // }
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade != 100) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 3:  // Trem 3
                // qInfo() << "Velocidade trem 3: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 350) {
                    if (x == 210) {
                        // break;
                    }
                    if (x == 330) {
                        // break;
                    }
                    x += 10;
                } else if (x == 350 && y < 410) {
                    y += 10;
                } else if (x > 110 && y == 410) {
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade != 100) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 4:  // Trem 4
                // qInfo() << "Velocidade trem 4: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 590) {
                    if (x == 450) {
                        // break;
                    }
                    if (x == 570) {
                        // break;
                    }
                    x += 10;
                } else if (x == 590 && y < 410) {
                    y += 10;
                } else if (x > 350 && y == 410) {
                    if (x == 370) {
                        // break;
                    }
                    x -= 10;
                } else {
                    y -= 10;
                }

                if (velocidade != 100) {
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
                    if (x == 610) {
                        // break;
                    }
                    x -= 10;
                } else {
                    if (y == 250) {
                        // break;
                    }
                    y -= 10;
                }
                if (velocidade != 100) {
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