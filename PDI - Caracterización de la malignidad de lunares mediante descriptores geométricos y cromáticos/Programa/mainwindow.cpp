#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    float contraste[11] = {0.15f, 0.25f, 0.50f, 0.75f, 1.0f, 1.25f, 1.5f, 1.75f, 2.0f, 2.5f, 3.0f};
    for (int i = 0; i < 11; ++i)
    {
        this->contraste_array[i] = contraste[i];
    }
    this->item = NULL;
    this->item2 = NULL;
    this->image = NULL;

    //Método de myQGraphicsViewer, creado únicamente con fines de override el evento onMouseOver
    ui->graphicsView->setMyParentWindow(this);

    //Imagen propia de 400 x 400:
    miImagen = new cImagen(400,400);
    miImagenOri = new cImagen(400,400);

    //QImage sirve interfase entre miImagen y QGraphicsViewer (o su hijo myQGraphicsViewer):
    image = new QImage(miImagen->getAncho(), miImagen->getAlto(), QImage::Format_RGB32 );
    image->fill(0);


    //Crea un nuevo Item gráfico para agregar a la escena scene:
    item = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene.addItem(item);
    ui->graphicsView->setScene(&scene);

    //Crea un nuevo Item gráfico para agregar a la escena scene:
    item2 = new QGraphicsPixmapItem(QPixmap::fromImage(*image));
    scene2.addItem(item2);
    ui->graphicsView_2->setScene(&scene2);

    this->mostrarImagen();
    this->mostrarImagen2();

    this->setWindowTitle("Análisis cuantitativo de melanoma");
}

void MainWindow::mostrarImagen()
{
    if(item)
        item->setPixmap(QPixmap::fromImage(*image));
    ui->graphicsView->show();

}

void MainWindow::mostrarImagen2()
{
    if(item2)
        item2->setPixmap(QPixmap::fromImage(*image));
    ui->graphicsView_2->show();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete item;
    delete item2;
    delete image;
    delete miImagen;
    delete miImagenOri;

}

void MainWindow::on_actionAbrir_imagen_triggered()
{
    //QString fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());
    fileName = QFileDialog::getOpenFileName(this,"Open Image File",QDir::currentPath());

    if(!fileName.isEmpty())
    {
        if(this->image)
            image->load(fileName);

        if(this->img_prueba == NULL)
            img_prueba = new myQImage(fileName);
            //img_prueba = new myQImage(image->width(), image->height(), image->format());
            //img_prueba = new myQImage(fileName,0);

    }

        if(image->isNull())
        {
            QMessageBox::information(this,"Image Viewer","Error Displaying image");
            return;
        }else {
            //cargar la nueva imagen en miImagen:
            if(miImagen->cargarImagen(image))
            {
                //cargar en contenido de miImagen a image (ya lo habrá convertido a escala de grises):
                miImagen->copiarDataEnImagen(image);
                this->mostrarImagen();
            }

            if(miImagenOri->cargarImagen(image))
            {
                //cargar en contenido de miImagen a image (ya lo habrá convertido a escala de grises):
                miImagenOri->copiarDataEnImagen(image);
                this->mostrarImagen2();
            }

        }
    }


// Métodos de análisis

void MainWindow::on_pushButton_clicked() // Binarizacion
{
    miImagen->Binarizacion();
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();
}

void MainWindow::on_pushButton_3_clicked() // Dilatación
{
    miImagen->Dilatacion();
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();
}

void MainWindow::on_pushButton_2_clicked() // Erosión
{
    miImagen->Erosion();
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();
}

void MainWindow::on_pushButton_4_clicked() // Crecimiento de región
{
    miImagen->CrecimientoDeRegion();
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();
}

void MainWindow::on_pushButton_5_clicked() // Diámetro
{
    ui->lcdNumber_4->display(miImagen->Diametro());
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();

}

void MainWindow::on_pushButton_8_clicked() // Color
{
    miImagenOri->Color(miImagen->MatrizBinarizada);
    ui->lcdNumber_3->display(miImagenOri->desvio);
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();
}

void MainWindow::on_pushButton_6_clicked() // Simetria
{
    miImagen->Simetria();
    ui->lcdNumber->display(miImagen->coef_variabilidad);
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();

}

void MainWindow::on_pushButton_7_clicked() // Borde
{
    miImagenOri->Borde();
    ui->lcdNumber_2->display(miImagenOri->promedio);
    miImagen->copiarDataEnImagen(image);
    this->mostrarImagen();
}

void MainWindow::on_pushButton_9_clicked() // Restablecer imagen
{
    if(this->image)
        image->load(fileName);

    //cargar la nueva imagen en miImagen:
    if(miImagen->cargarImagen(image))
    {
        //cargar en contenido de miImagen a image (ya lo habrá convertido a escala de grises):
        miImagen->copiarDataEnImagen(image);
        this->mostrarImagen();
    }
}




void MainWindow::on_actionExportar_datos_triggered()
{
    QString nombre,apellido,edad,str;
    QString fecha;
    float diam,a,b,c;

    a=miImagen->desvio;
    b=miImagen->coef_variabilidad;
    c=miImagen->promedio;

    nombre=ui->lineEdit->text();
    apellido=ui->lineEdit_2->text();
    edad=ui->lineEdit_4->text();
    fecha=ui->dateEdit->text();

    FILE * fp;
    fp = fopen("d://data.txt", "w");

    //fwrite(nombre.toStdString().c_str(), sizeof(nombre.toStdString().c_str()), 1, fp);
    fwrite(nombre.toStdString().c_str(), 30, 1, fp);

    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    //fwrite(apellido.toStdString().c_str(), sizeof(apellido.toStdString().c_str()), 1, fp);
    fwrite(apellido.toStdString().c_str(), 30, 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    fwrite(edad.toStdString().c_str(), sizeof(edad.toStdString().c_str()), 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    //fwrite(fecha.toStdString().c_str(), sizeof(fecha.toStdString().c_str()), 1, fp);
    fwrite(fecha.toStdString().c_str(), 10, 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    QString d = QString::number(diam); //diametro
    fwrite(d.toStdString().c_str(), sizeof(d.toStdString().c_str()), 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    QString de = QString::number(a); //color
    fwrite(de.toStdString().c_str(), sizeof(de.toStdString().c_str()), 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    QString cv = QString::number(b); //simetria
    fwrite(cv.toStdString().c_str(), sizeof(cv.toStdString().c_str()), 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    QString p = QString::number(c); //borde
    fwrite(p.toStdString().c_str(), sizeof(p.toStdString().c_str()), 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);

    fclose(fp);

    /*
    FILE * fp;
    fp = fopen("d://data.txt", "w");
    float a = 1.5;
    QString str = QString::number(a);
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);
    str = "\r\n";
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);
    a = 2.5;
    str = QString::number(a);
    fwrite(str.toStdString().c_str(), sizeof(str.toStdString().c_str()), 1, fp);
    fclose(fp);
    */

}
