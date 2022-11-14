#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void controlaSemaforos(int, int, int);

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

    sem_t semaforo_1;
    sem_t semaforo_2;
    sem_t semaforo_3;
    sem_t semaforo_4;
    sem_t semaforo_5;
    sem_t semaforo_6;
    sem_t semaforo_7;
};
#endif  // MAINWINDOW_H
