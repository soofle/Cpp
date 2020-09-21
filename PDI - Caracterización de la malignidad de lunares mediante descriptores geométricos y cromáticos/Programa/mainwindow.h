#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "cimagen.h"
#include "myqimage.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QRgb>
#include <QInputDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QGraphicsScene  scene, scene2;
    QImage*  image;
    QGraphicsPixmapItem* item;
    QGraphicsPixmapItem* item2;
    cImagen* miImagen;
    cImagen* miImagenOri; // Imagen Original

    QString fileName;

    myQImage* img_prueba;
    float contraste_array[11];

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mostrarImagen();
    void mostrarImagen2();

private slots:
    void on_actionAbrir_imagen_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_7_clicked();

    void on_actionExportar_datos_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
