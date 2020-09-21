/**********************************************************************************
 * .Ing. Mariano E. Casciaro
 * .Cátedra de Procesamiento Digital de Imágenes
 * .Facultad de Ingeniería, Ciencias Exactas y Naturales
 * .Universidad Favaloro
 * .Ciudad Autónoma de Buenos Aires
 * .Argentina
 * .29/12/2014
 * ********************************************************************************/

#ifndef CIMAGEN_H
#define CIMAGEN_H

#include <QGraphicsPixmapItem>
#include <QRgb>
#include "math.h"

class cImagen
{
    float** data;                   //Valores reales de la imagen
    unsigned char** int_data;       //Valores enteros de la imagen con fines de representación
    unsigned char LUT[256];         //Look Up Table para la Operaciones de color

    static int def_ancho;           //Ancho de las imágenes por defecto
    static int def_alto;            //Alto de las imágenes por defecto
    int ancho;                      //Ancho de las imágenes por defecto
    int alto;                       //Alto de las imágenes por defecto

    float min;                      //Máximo valor de data
    float max;                      //Mínimo valor de data

    float Histograma[256];

    float mascara[3][3];

    void computarMaxMinData();
    void computarIntDataFromData(bool escalar = true);

public:
    cImagen();
    cImagen(int ancho, int alto);

    const int getAncho();
    const int getAlto();

    float           getData(int X, int Y);
    bool            setData(int X, int Y, float C);
    unsigned char   getIntData(int X, int Y);
    bool            setIntData(int X, int Y, unsigned char C);

    unsigned int    area;
    int             centroX,centroY;
    float           Dmayor,angulo;      //Diámetro mayor derivado de propiedad 'Diámetro'
    int             Xm1,Xm2,Ym1,Ym2;

    float           coef_variabilidad;  //Variabilidad derivada de propiedad 'Simetría'
    float           desvio;             //Desvío derivado de propiedad 'Color'
    float           promedio;           //Promedio derivado de la propiedad 'Borde'

    int ** MatrizBinarizada;

    bool cargarImagen(QImage* image);

    bool copiarDataEnImagen(QImage*  image);
    bool copiarDataEnImagen(cImagen* image);

    unsigned int getHistograma(int i);
    void cargarHistograma();
    void ecualizacionHistograma();
    void aplicarMascara();
    void suavizarMascara();
    void suavizarFiltroMediana();

    //Preprocesamiento de datos:
    void UmbralFijo(int umbral);
    void Isodata();
    void Binarizacion();
    void Erosion();
    void Dilatacion();
    void CrecimientoDeRegion();

    //Análisis de parámetros de riesgo:
    void Simetria();
    void Sobel();
    void Borde();
    void Color(int ** mbin);
    float Diametro();

    //Rutinas de visualización:
    void aplicarLUT();


    struct Punto
    {
        int x, y;
    };

    ~cImagen();
};

#endif // CIMAGEN_H
