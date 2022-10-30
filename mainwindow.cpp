#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y)
    trem1 = new Trem(1,180,30);
    trem2 = new Trem(2,430,30);
    trem3 = new Trem(3, 60, 230);
    trem4 = new Trem(4, 310, 230);
    trem5 = new Trem(5, 550, 230);

    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->trem_1->setGeometry(x, y, 21, 17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->trem_2->setGeometry(x, y, 21, 17);
        break;
    case 3:
        ui->trem_3->setGeometry(x, y, 21, 17);
        break;
    case 4:
        ui->trem_4->setGeometry(x, y, 21, 17);
        break;
    case 5:
        ui->trem_5->setGeometry(x, y, 21, 17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Ao clicar, trens começam execução
 */
void MainWindow::on_iniciar_clicked()
{
    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

/*
 * Ao clicar, trens param execução
 */
void MainWindow::on_terminar_clicked()
{
    trem1->terminate();
    trem2->terminate();
    trem3->terminate();
    trem4->terminate();
    trem5->terminate();
}

/*Altera a velocidade do trem 1*/
void MainWindow::on_slider_trem1_valueChanged(int value)
{
    trem1->setVelocidade(value);
}

/*Altera a velocidade do trem 2*/
void MainWindow::on_slider_trem2_valueChanged(int value)
{
    trem2->setVelocidade(value);
}

/*Altera a velocidade do trem 3*/
void MainWindow::on_slider_trem3_valueChanged(int value)
{
    trem3->setVelocidade(value);
}

/*Altera a velocidade do trem 4*/
void MainWindow::on_slider_trem4_valueChanged(int value)
{
    trem4->setVelocidade(value);
}

/*Altera a velocidade do trem 5*/
void MainWindow::on_slider_trem5_valueChanged(int value)
{
    trem5->setVelocidade(value);
}

