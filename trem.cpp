#include "trem.h"

#include <QtCore>
#include <semaphore.h>

#define N_TRENS = 5;
#define N_REGIOES = 7;

#define REGIAO_1 = 0;
#define REGIAO_2 = 1;
#define REGIAO_3 = 2;
#define REGIAO_4 = 3;
#define REGIAO_5 = 4;
#define REGIAO_6 = 5;
#define REGIAO_7 = 6;

#define LIVRE = 0;
#define OCUPADO = 1;

sem_t *semaforo_1;
sem_t *semaforo_2;
sem_t *semaforo_3;
sem_t *semaforo_4;
sem_t *semaforo_5;
sem_t *semaforo_6;
sem_t *semaforo_7;

// Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 50;
}

// Função a ser executada após executar trem->START
void Trem::run() {
    sem_init(semaforo_1, 0, );
    while (true) {
        switch (ID){
            case 1:  // Trem 1
                // qInfo() << "Velocidade trem 1: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 30 && x < 460)
                    x += 10;
                else if (x == 460 && y < 230)
                    y += 10;
                else if (x > 210 && y == 230)
                    x -= 10;
                else
                    y -= 10;
                if (velocidade != 100) {
                    emit updateGUI(ID, x, y);  // Emite um sinal
                }
                break;
            case 2:  // Trem 2
                // qInfo() << "Velocidade trem 2: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 30 && x < 690)
                    x += 10;
                else if (x == 690 && y < 230)
                    y += 10;
                else if (x > 460 && y == 230)
                    x -= 10;
                else
                    y -= 10;
                if (velocidade != 100) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 3:  // Trem 3
                // qInfo() << "Velocidade trem 3: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 340)
                    x += 10;
                else if (x == 340 && y < 410)
                    y += 10;
                else if (x > 90 && y == 410)
                    x -= 10;
                else
                    y -= 10;
                if (velocidade != 100) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 4:  // Trem 4
                // qInfo() << "Velocidade trem 4: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 580)
                    x += 10;
                else if (x == 580 && y < 410)
                    y += 10;
                else if (x > 340 && y == 410)
                    x -= 10;
                else
                    y -= 10;
                if (velocidade != 100) {
                    emit updateGUI(ID, x, y);  // Emite um sinal para atualizar a posição do trem na tela
                }
                break;
            case 5:  // Trem 5
                // qInfo() << "Velocidade trem 5: " << this->velocidade;
                if (velocidade == 200) {
                    break;
                }
                if (y == 230 && x < 810)
                    x += 10;
                else if (x == 810 && y < 410)
                    y += 10;
                else if (x > 580 && y == 410)
                    x -= 10;
                else
                    y -= 10;
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
