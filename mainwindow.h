#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <semaphore.h>

#include <QMainWindow>

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
    void updateInterface(int, int, int);

   private slots:
    void on_iniciar_clicked();

    void on_terminar_clicked();

    void on_slider_trem1_valueChanged(int value);

    void on_slider_trem2_valueChanged(int value);

    void on_slider_trem3_valueChanged(int value);

    void on_slider_trem4_valueChanged(int value);

    void on_slider_trem5_valueChanged(int value);

   private:
    Ui::MainWindow *ui;

    // Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;

    Semaforo *semaforos;
    // Criando objetos de semaforo
    // static sem_t semaforo_1;
    // static sem_t semaforo_2;
    // static sem_t semaforo_3;
    // static sem_t semaforo_4;
    // static sem_t semaforo_5;
    // static sem_t semaforo_6;
    // static sem_t semaforo_7;
};
#endif  // MAINWINDOW_H
