#include "trem.h"

#include <QtCore>


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
                if (velocidade == 200){ // condição de parada do trem
                    break;
                }
                if (y == 30 && x < 470){
                    // semaforo 1
                    if (x == 450 && semaforos->getValorSemaforo(1) > 0){
                        if(semaforos->getValorSemaforo(3) == 0 && semaforos->getValorSemaforo(5) == 0 && semaforos->getValorSemaforo(7) == 0){
                            break;  // T2, T4 e T5 nas regiões criticas 3, 5 e 7
                        }
                        if(semaforos->getValorSemaforo(2) == 0 && semaforos->getValorSemaforo(4) == 0 && semaforos->getValorSemaforo(6) == 0){
                            break; // T2, T3 e T4 nas regiões criticas 2, 4 e 6
                        }
                        if(semaforos->getValorSemaforo(3) == 0 && semaforos->getValorSemaforo(4) == 0){
                            break; // T4 e T2 nas regiões criticas 3 e 4
                        }
                        sem_wait(semaforos->getSemaforo(1));
                    } else if (x == 450 && semaforos->getValorSemaforo(1) == 0) {
                        break;
                    }
                    x += 10;
                } else if (x == 470 && y < 230){
                    // semaforo 3
                    if (y == 210 && semaforos->getValorSemaforo(3) > 0){
                        if(semaforos->getValorSemaforo(2) == 0 && semaforos->getValorSemaforo(6) == 0){
                            break; // T3 e T4 dentro das regiões criticas 2 e 6
                        }
                        sem_wait(semaforos->getSemaforo(3));
                    } else if (y == 210 && semaforos->getValorSemaforo(3) == 0) {
                        break;
                    }
                    y += 10;
                } else if (x > 230 && y == 230){
                    // semaforo 1
                    if (x == 470 && semaforos->getValorSemaforo(1) == 0){
                        sem_post(semaforos->getSemaforo(1));
                    }
                    // semaforo 3
                    if (x == 340 && semaforos->getValorSemaforo(3) == 0){
                        sem_post(semaforos->getSemaforo(3));
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
                if (velocidade == 200){ // condição de parada do trem
                    break;
                }
                if (y == 30 && x < 710){
                    // semaforo 1
                    if (x == 470 && semaforos->getValorSemaforo(1) == 0) {
                        sem_post(semaforos->getSemaforo(1));
                    }
                    x += 10;
                } else if (x == 710 && y < 230){
                    // semaforo 5
                    if (y == 210 && semaforos->getValorSemaforo(5) > 0){
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(3) == 0 && semaforos->getValorSemaforo(7) == 0){
                            break; // T1, T4 e T5 nas regiões criticas 1, 3 e 7
                        }
                        if(semaforos->getValorSemaforo(4) == 0 && semaforos->getValorSemaforo(7) == 0){
                            break; // T4 e T5 nas regiões criticas 4 e 7
                        }
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
                    // semaforo 4
                    if (x == 610 && semaforos->getValorSemaforo(4) > 0){
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(2) == 0 && semaforos->getValorSemaforo(6) == 0){
                            break; // T1, T3 e T4 nas regiões criticas 1, 2 e 6
                        }
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(3) == 0){
                            break; // T1 e T4 nas regiões criticas 1 e 3
                        }
                        sem_wait(semaforos->getSemaforo(4));
                    } else if (x == 610 && semaforos->getValorSemaforo(4) == 0) {
                        break;
                    }
                    x -= 10;
                } else {
                    // semaforo 4
                    if(x == 470 && y == 220 && semaforos->getValorSemaforo(4) == 0){
                        sem_post(semaforos->getSemaforo(4));
                    }
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 3:  // Trem 3
                if (velocidade == 200){
                    break;
                }
                if (y == 230 && x < 350){
                    // semaforo 2
                    if (x == 210 && semaforos->getValorSemaforo(2) > 0){
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(4) == 0 && semaforos->getValorSemaforo(6) == 0){
                            break; // T1, T2 e T4 dentro das regiões criticas 1, 4 e 6
                        }
                        if(semaforos->getValorSemaforo(3) == 0 && semaforos->getValorSemaforo(6) == 0){
                            break; // T1 e T4 dentro das regiões criticas 3 e 6
                        }
                        sem_wait(semaforos->getSemaforo(2));
                    } else if (x == 210 && semaforos->getValorSemaforo(2) == 0) {
                        break;
                    }
                    // semaforo 6
                    if (x == 330 && semaforos->getValorSemaforo(6) > 0) {
                        sem_wait(semaforos->getSemaforo(6));
                    } else if (x == 330 && semaforos->getValorSemaforo(6) == 0) {
                        break;
                    }
                    x += 10;
                } else if (x == 350 && y < 410){
                    // semaforo 2
                    if(y == 240 && semaforos->getValorSemaforo(2) == 0){
                        sem_post(semaforos->getSemaforo(2));
                    }
                    y += 10;
                } else if (x > 110 && y == 410){
                    // semaforo 6
                    if(x == 350 && semaforos->getValorSemaforo(6) == 0){
                        sem_post(semaforos->getSemaforo(6));
                    }
                    x -= 10;
                } else {
                    y -= 10;
                }
                if (velocidade) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 4:  // Trem 4
                if(velocidade == 200){
                    break;
                }
                if (y == 230 && x < 590){
                    // semaforo 6
                    if(x == 360 && semaforos->getValorSemaforo(6) == 0){
                        sem_post(semaforos->getSemaforo(6));
                    }
                    // semaforo 3
                    if(x == 480 && semaforos->getValorSemaforo(3) == 0){
                        sem_post(semaforos->getSemaforo(3));
                    }
                    // semaforo 4
                    if(x == 450 && semaforos->getValorSemaforo(4) > 0){
                        if(semaforos->getValorSemaforo(5) == 0 && semaforos->getValorSemaforo(7) == 0){
                            break; // T2 e T5 nas regiões criticas 5 e 7
                        }
                        sem_wait(semaforos->getSemaforo(4));
                    }else if (x == 450 && semaforos->getValorSemaforo(4) == 0){
                        break;
                    }
                    // semaforo 7
                    if(x == 570 && semaforos->getValorSemaforo(7) > 0){
                        sem_wait(semaforos->getSemaforo(7));
                    }else if (x == 570 && semaforos->getValorSemaforo(7) == 0){
                        break;
                    }
                    x += 10;
                } else if (x == 590 && y < 410){
                    // semaforo 4
                    if(y == 240 && semaforos->getValorSemaforo(4) == 0){
                        sem_post(semaforos->getSemaforo(4));
                    }
                    y += 10;
                } else if (x > 350 && y == 410){
                    // semaforo 7
                    if(x == 580 && semaforos->getValorSemaforo(7) == 0){
                        sem_post(semaforos->getSemaforo(7));
                    }
                    // semaforo 6
                    if(x == 370 && semaforos->getValorSemaforo(6) > 0){
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(2) == 0 && semaforos->getValorSemaforo(4) == 0){
                            break;  // T1, T2 e T3 dentro das regiões criticas 1, 2 e 4
                        }
                        if(semaforos->getValorSemaforo(2) == 0 && semaforos->getValorSemaforo(3) == 0){
                            break; // T3 e T1 dentro das regiões criticas 2 e 3
                        }
                        sem_wait(semaforos->getSemaforo(6));
                    }else if (x == 370 && semaforos->getValorSemaforo(6) == 0){
                        break;
                    }
                    x -= 10;
                } else {
                    // semaforo 3
                    if(x == 350 && y == 250 && semaforos->getValorSemaforo(3) > 0){
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(5) == 0 && semaforos->getValorSemaforo(7) == 0){
                            break; // T1, T2 e T5 nas regiões criticas 1, 5 e 7
                        }
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(4) == 0){
                            break; // T1 e T2 nas regiões criticas 1 e 4
                        }
                        sem_wait(semaforos->getSemaforo(3));
                    }else if (x == 350 && y == 250 && semaforos->getValorSemaforo(3) == 0){
                        break;
                    }
                    y -= 10;
                }
                if (velocidade){
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 5:  // Trem 5
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 830){
                    // semaforo 5
                    if(x == 720 && semaforos->getValorSemaforo(5) == 0){
                        sem_post(semaforos->getSemaforo(5));
                    }
                    // semaforo 7
                    if(x == 600 && semaforos->getValorSemaforo(7) == 0){
                        sem_post(semaforos->getSemaforo(7));
                    }
                    x += 10;
                } else if (x == 830 && y < 410) {
                    y += 10;
                } else if (x > 590 && y == 410){
                    // semaforo 7
                    if(x == 610 && semaforos->getValorSemaforo(7) > 0){
                        if(semaforos->getValorSemaforo(1) == 0 && semaforos->getValorSemaforo(3) == 0 && semaforos->getValorSemaforo(5) == 0){
                            break; // T1, T2 e T4 nas regiões criticas 1, 3 e 5
                        }
                        if(semaforos->getValorSemaforo(4) == 0 && semaforos->getValorSemaforo(5) == 0){
                            break; // T4 e T2 nas regiões criticas 4 e 5
                        }
                        sem_wait(semaforos->getSemaforo(7));
                    }else if (x == 610 && semaforos->getValorSemaforo(7) == 0) {
                        break;
                    }
                    x -= 10;
                } else {
                    // semaforo 5
                    if(x == 590 && y == 250 && semaforos->getValorSemaforo(5) > 0){
                        sem_wait(semaforos->getSemaforo(5));
                    }else if (x == 590 && y == 250 && semaforos->getValorSemaforo(5) == 0) {
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
