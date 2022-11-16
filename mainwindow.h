#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPixmap>
#include <iostream>

#include "semaforo.h"
#include "trem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

   public slots:
    void updateInterface(int, int, int); // atualiza a interface visual com a nova posição dos trens
    void startTrens(); // inicia o andamento dos trens na malha ferroviaria

   private slots:
    void on_slider_trem1_valueChanged(int value); // altera a velocidade do trem 1

    void on_slider_trem2_valueChanged(int value); // altera a velocidade do trem 2

    void on_slider_trem3_valueChanged(int value); // altera a velocidade do trem 3

    void on_slider_trem4_valueChanged(int value); // altera a velocidade do trem 4

    void on_slider_trem5_valueChanged(int value); // altera a velocidade do trem 5

   private:
    Ui::MainWindow *ui;

    // Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;

    // Cria o objeto semaforos
    Semaforo *semaforos;
};
#endif  // MAINWINDOW_H
