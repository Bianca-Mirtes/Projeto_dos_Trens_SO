#include "trem.h"
#include <QtCore>

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

//Construtor
Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = 50;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 30 && x < 430)
                x+=10;
            else if (x == 430 && y < 230)
                y+=10;
            else if (x > 180 && y == 230)
                x-=10;
            else
                y-=10;
            if(velocidade != 100){
                emit updateGUI(ID, x,y);    //Emite um sinal
            }
            break;
        case 2: //Trem 2
            if (y == 30 && x < 660)
                x+=10;
            else if (x == 660 && y < 230)
                y+=10;
            else if (x > 430 && y == 230)
                x-=10;
            else
                y-=10;
            if(velocidade != 100){
                emit updateGUI(ID, x,y);    //Emite um sinal
            }
            break;
        case 3: //Trem 3
            if (y == 230 && x < 310)
                x += 10;
            else if (x == 310 && y < 410)
                y += 10;
            else if (x > 60 && y == 410)
                x -= 10;
            else
                y -= 10;
            if(velocidade != 100){
                emit updateGUI(ID, x,y);    //Emite um sinal
            }
            break;
        case 4: //Trem 4
            if(y == 230 && x < 550)
                x += 10;
            else if (x == 550 && y < 410)
                y += 10;
            else if (x > 310 && y == 410)
                x -= 10;
            else
                y -= 10;
            if(velocidade != 100){
                emit updateGUI(ID, x,y);    //Emite um sinal
            }
            break;
        case 5: //Trem 5
            if(y == 230 && x < 780)
                x += 10;
            else if (x == 780 && y < 410)
                y += 10;
            else if (x > 550 && y == 410)
                x -= 10;
            else
                y -= 10;
            if(velocidade != 100){
                emit updateGUI(ID, x,y);    //Emite um sinal
            }
            break;
        default:
            break;
        }
        msleep(velocidade);
    }
}

void Trem::setVelocidade(int valor){
    this->velocidade = valor;
}
