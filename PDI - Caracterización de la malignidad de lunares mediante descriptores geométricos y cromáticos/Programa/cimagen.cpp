#include "cimagen.h"
#include "math.h"

int cImagen::def_ancho = 400;
int cImagen::def_alto = 400;

cImagen::cImagen()
{
    //Constructor por defecto para imágenes de 400 x 400:
    ancho = def_ancho;
    alto  = def_alto;

    max = 0;
    min = 0;

    this->data = new float* [def_ancho];
    for(int i=0; i<def_ancho; ++i)
        this->data[i] = new float[def_alto];
    this->MatrizBinarizada = new int* [def_ancho];
    for(int i=0; i<def_ancho; ++i)
        this->MatrizBinarizada[i] = new int[def_alto];
    int_data = NULL;
}

cImagen::cImagen(int ancho, int alto)
{
    //Constructor por parámetros para imágenes de ancho x alto:
    this->ancho = ancho;
    this->alto  = alto;

    max = 0;
    min = 0;

    this->data = new float* [ancho];
    for(int i=0; i<ancho; ++i)
        this->data[i] = new float[alto];
    this->MatrizBinarizada = new int* [ancho];
    for(int i=0; i<ancho; ++i)
        this->MatrizBinarizada[i] = new int[alto];

    int_data = NULL;
}

cImagen::~cImagen()
{
    if(this->data)
    {
        for(int i=0; i<ancho; ++i)
            delete [] data[i];
        delete [] data;
    }

    if(this->int_data)
    {
        for(int i=0; i<ancho; ++i)
            delete [] int_data[i];
        delete [] int_data;
    }
    if(this->MatrizBinarizada)
    {
        for(int i=0; i<ancho; ++i)
            delete [] MatrizBinarizada[i];
        delete [] MatrizBinarizada;
    }
}

//Getters ***********************************************************
const int cImagen::getAncho() { return this->ancho; }
const int cImagen::getAlto()  { return this->alto;  }
float     cImagen::getData(int X, int Y)
{
    if(!data)
        return 0.0;

    if(X < ancho && X >= 0 && Y < ancho && Y >= 0)
        return this->data[X][Y];
    else return 0.0;
}

//Setters ***********************************************************
bool     cImagen::setData(int X, int Y, float C)
{
    //Devuelve false si la imagen no fue inicialiada:
    if(!data)
        return false;

    if(X < ancho && X >= 0 && Y < ancho && Y >= 0)
    {
        //Devuelve true ante un cambio satisfactorio de color C en
        //en data[X][Y]:
        this->data[X][Y] = C;
        return true;
    } else {
        //Devuelve falso si X,Y están fuera de los límites de la
        //imagen:
        return false;
    }
}

unsigned char cImagen::getIntData(int X, int Y)
{
    if(!int_data)
        return 0;

    if(X < ancho && X >= 0 && Y < ancho && Y >= 0)
        return this->int_data[X][Y];
    else return 0;
}

//Setters ***********************************************************
bool     cImagen::setIntData(int X, int Y, unsigned char C)
{
    //Devuelve false si la imagen no fue inicialiada:
    if(!int_data)
        return false;

    if(X < ancho && X >= 0 && Y < ancho && Y >= 0)
    {
        //Devuelve true ante un cambio satisfactorio de color C en
        //en data[X][Y]:
        this->int_data[X][Y] = C;
        return true;
    } else {
        //Devuelve falso si X,Y están fuera de los límites de la
        //imagen:
        return false;
    }
}

//********************************************************************

bool    cImagen::cargarImagen(QImage* image)
{
    //Devuelve false si:
    //.las dimensiones del QImage y el cImagen no coinciden
    //.el QImage no está inicializado
    //.el cImage no está inicializado

    if(!image)
        return false;
    if(!this->data)
        return false;
    //if(image->width() != this->ancho && image->height() != this->alto)
    //    return false;

    //Devuelve true si la imagen se carga correctamente
    for (int i = 0; i < ancho; ++i)
        for (int j = 0; j < alto; ++j)
        {
            this->data[i][j] = ( qRed(image->pixel(i,j))
                               + qRed(image->pixel(i,j))
                               + qRed(image->pixel(i,j)) ) / 3.0;
        }

    this->computarIntDataFromData();

    return true;
}
//--------------------------------------------------------------------

bool    cImagen::copiarDataEnImagen(QImage* image)
{
    //Copia el contenido de this->int_data en el QImage image
    //Devuelve false si:
    //.las dimensiones del QImage y el cImagen no coinciden
    //.el QImage no está inicializado
    //.el int_data de cImage no está inicializado

    if(!image)
        return false;
    if(!this->int_data)
        return false;
    //if(image->width() != this->ancho && image->height() != this->alto)
    //    return false;

    //Devuelve true si la imagen se copia correctamente
    QColor* pixel;

    switch(image->format())
    {
        case (QImage::Format_Indexed8):
            for (int i = 0; i < ancho; ++i)
                for (int j = 0; j < alto; ++j)
                {
                    pixel = new QColor(this->int_data[i][j], this->int_data[i][j], this->int_data[i][j]);
                    image->setPixel(i,j, pixel->red());
                    delete pixel;
                }
            break;
        case (QImage::Format_RGB32):
            for (int i = 0; i < ancho; ++i)
                for (int j = 0; j < alto; ++j)
                {
                    pixel = new QColor(this->int_data[i][j], this->int_data[i][j], this->int_data[i][j]);
                    image->setPixel(i,j, pixel->rgb());
                    delete pixel;
                }
            break;

        //Formato no soportado:
        default: return false;
    }
    return true;
}
//--------------------------------------------------------------------

bool    cImagen::copiarDataEnImagen(cImagen *image)
{
    //Copia el contenido de this->data en image
    //Devuelve false si:
    //.las dimensiones del QImage y el cImagen no coinciden
    //.el QImage no está inicializado
    //.el cImage no está inicializado

    if(!image)
        return false;
    if(!image->data)
        return false;
    if(!this->data)
        return false;
    //if(image->getAncho() != this->ancho && image->getAlto() != this->alto)
    //    return false;

    //Devuelve true si la imagen se copia correctamente
    for (int i = 0; i < ancho; ++i)
        for (int j = 0; j < alto; ++j)
           image->setData(i,j, this->data[i][j]);
    return true;

    if(this->int_data)
        for (int i = 0; i < ancho; ++i)
            for (int j = 0; j < alto; ++j)
               image->setIntData(i,j, this->int_data[i][j]);

}

//--------------------------------------------------------------------

void cImagen::computarMaxMinData()
{

    min = data[0][0];
    max = data[0][0];

    for (int i = 0; i < ancho; ++i)
        for (int j = 0; j < alto; ++j)
        {
            if(data[i][j] > max)
                max = data[i][j];
            if(data[i][j] < min)
                min = data[i][j];
        }
}
//--------------------------------------------------------------------

void cImagen::computarIntDataFromData(bool escalar)
{
    if(!data)
        return;

    if(!int_data)
    {
        this->int_data = new unsigned char* [ancho];
        for(int i = 0; i < ancho; ++i)
            this->int_data[i] = new unsigned char[alto];
    }

    if(!escalar)
    {
        for (int i = 0; i < ancho; ++i)
            for (int j = 0; j < alto; ++j)
                int_data[i][j] = data[i][j];
        return;
    }

    this->computarMaxMinData();

    //Si hay una imagen monótona, dará error en el escalado:
    if(max == min)
        return;

    //Si la imagen no es monótona, escalar:
    float slope     = 255.0 / (max-min);
    float intercept = -min * slope;

    for (int i = 0; i < ancho; ++i)
        for (int j = 0; j < alto; ++j)
            int_data[i][j] = qRound( slope*data[i][j] + intercept );
}

//--------------------------------------------------------------------------------

void cImagen::aplicarLUT()
{
    for (int i = 0; i < ancho; ++i)
        for (int j = 0; j < alto; ++j)
            int_data[i][j] = LUT[int_data[i][j]];

}

/*-PROCESAMIENTO DE DATOS--------------------------------------------------------*/

unsigned int cImagen::getHistograma(int i)
{
    return Histograma[i];
}

void cImagen::cargarHistograma()
{
    for (int i = 0; i<256; i++)
        Histograma[i]=0;

    int a;
    for(int i = 0; i<this->ancho; i++)
    {
        for(int j = 0; j<this->alto; j++)
        {
            a = int_data[i][j];
            Histograma[a]++;
        }
    }
}

void cImagen::ecualizacionHistograma()
{
   float Acumulo[256];

    Acumulo[0]=Histograma[0];

    for(int i = 1; i<256; i++)
    {
       Acumulo[i]=Acumulo[i-1]+Histograma[i];
    }

    for(int i = 0; i<256; i++)
    {
       LUT[i]=Acumulo[i]/256; //256: maximo
    }
}

void cImagen::UmbralFijo(int umbral)
{
    float auxiliar[400][400];

    for (int i = 0; i < this->ancho; i++)
    {
        for (int j = 0; j < this->alto; j++)
        {
            if(data[j][i] <= umbral)
            {
                auxiliar[j][i] = 0.0;
            }
            else
            {
                auxiliar[j][i] = 255.0;
            }

        }
    }

    for (int i = 0; i < this->ancho; i++)
    {
        for (int j = 0; j < this->alto; j++)
        {
            data[j][i] = auxiliar[j][i];
        }
    }
    this->computarIntDataFromData(false);

}

void cImagen::aplicarMascara()
{
    float auxiliar[400][400];

    for (int i = 0; i < this->ancho; i++)
        for (int j = 0; j < this->alto; j++)
            auxiliar[i][j]=int_data[i][j];

    for (int i = 1; i < this->ancho-1; i++)
    {
        for (int j = 1; j < this->alto-1; j++)
        {    auxiliar[i][j] = mascara[0][0]*(float)int_data[i-1][j-1]
                             +mascara[1][0]*(float)int_data[i][j-1]
                             +mascara[2][0]*(float)int_data[i+1][j-1]
                             +mascara[0][1]*(float)int_data[i-1][j]
                             +mascara[1][1]*(float)int_data[i][j]
                             +mascara[2][1]*(float)int_data[i+1][j]
                             +mascara[0][2]*(float)int_data[i-1][j+1]
                             +mascara[1][2]*(float)int_data[i][j+1]
                             +mascara[2][2]*(float)int_data[i+1][j+1];
        }
    }
    for (int i = 0; i < this->ancho; i++)
        for (int j = 0; j < this->alto; j++)
        {
            auxiliar[i][j] = fabs(auxiliar[i][j]);
            if(auxiliar[i][j] > 255) auxiliar[i][j] = 255;
            int_data[i][j]=auxiliar[i][j];
        }

}

void cImagen::suavizarMascara()
{
   for (int i = 0; i < 3; i++)
       for (int j = 0; j < 3; j++)
           mascara[i][j] = 1.0/9.0;
}

void cImagen::suavizarFiltroMediana()
{
    float auxiliar[400][400];
    int array[9];
    int a = 0;

    for (int h = 0; h < 9; h++)
    {
    array[h]= 0;
    }

    for (int i = 0; i < this->ancho; i++)
        for (int j = 0; j < this->alto; j++)
            auxiliar[i][j] = int_data[i][j];

    for (int i = 1; i < this->ancho-1; i++)
    {
        for (int j = 1; j < this->alto-1; j++)
        {

            array[0] = int_data[i-1][j-1];
            array[1] = int_data[i][j-1];
            array[2] = int_data[i+1][j-1];
            array[3] = int_data[i-1][j];
            array[4] = int_data[i][j];
            array[5] = int_data[i+1][j];
            array[6] = int_data[i-1][j+1];
            array[7] = int_data[i][j+1];
            array[8] = int_data[i+1][j+1];

            for (int h = 0; h < 9; h++)
            for (int l = 0; l < h; l++)
            {
               if(array[h]<array[l])
               {
                   a = array[h];
                   array[h] = array[l];
                   array[l] = a;
               }
            auxiliar[i][j] = array[4];

            }
        }
    }
    for (int i = 0; i < this->ancho; i++)
        for (int j = 0; j < this->alto; j++)
            int_data[i][j] = auxiliar[i][j];
}

void cImagen::Isodata()
{

    cargarHistograma();
    ecualizacionHistograma();

    aplicarLUT();
    for (int i = 0; i < ancho; ++i)
        for (int j = 0; j < alto; ++j)
            data[i][j] = int_data[i][j];


    int umean,u0,u1,uanterior,min,max,acum1=0,acum2=0;
    uanterior = 0;
    umean = 200;
    for(int i = 0; i<256 ; i++)
    {
        if(Histograma[i]!=0)
        {
            min= i;
            break;
        }
    }
    for(int i = 255; i>=0 ; i--)
    {
        if(Histograma[i]!=0)
        {
             max= i;
             break;
        }
    }
    while(umean!=uanterior)
    {
        uanterior=umean;
        acum1=0;
        acum2=0;
        for(int i = min; i<umean ; i++)
        {
            acum1 += Histograma[i]*i;
            acum2 += Histograma[i];
        }
        u0= acum1/acum2;
        acum1=0;
        acum2=0;
        for(int i = umean; i<=max ; i++)
        {
            acum1 += Histograma[i]*i;
            acum2 += Histograma[i];
        }
        u1= acum1/acum2;
        umean = (u0+u1)/2;
    }
    UmbralFijo(umean);
}

void cImagen::Dilatacion()
{
    int auxiliar[400][400];

    // Matriz auxiliar
    for (int i = 0; i < 400; i++)
    {
     for (int j = 0; j < 400; j++)
         {
            auxiliar[i][j]=0;
         }
    }

    //Recorro matriz, toca foto=> pixel central de aux es 255
    for (int i = 2; i < this->ancho-2; i++)
    {
        for (int j = 2; j < this->alto-2; j++)
        {

             if(int_data[i][j-1]==255
             || int_data[i-1][j-1]==255
             || int_data[i+1][j-1]==255
             || int_data[i-1][j]==255
             || int_data[i][j]==255
             || int_data[i+1][j]==255
             || int_data[i-1][j+1]==255
             || int_data[i][j+1]==255
             || int_data[i+1][j+1]==255
             || int_data[i][j-2]==255
             || int_data[i-2][j]==255
             || int_data[i+2][j]==255
             || int_data[i][j+2]==255
             || int_data[i+1][j-2]==255
             || int_data[i+2][j-1]==255
             || int_data[i+2][j+1]==255
             || int_data[i+1][j+2]==255
             || int_data[i-1][j+2]==255
             || int_data[i-2][j+1]==255
             || int_data[i-2][j-1]==255
             || int_data[i-1][j-2]==255)
             {
                 auxiliar[i][j]=255;
             }
        }

}

    // Copio aux a imagen
    for (int i = 0; i < 400; i++)
    {    for (int j = 0; j < 400; j++)
         {
            data[i][j]=255;
         }
    }
    for (int i = 2; i < 398; i++)
    {
     for (int j = 2; j < 398; j++)
         {
            data[i][j]=auxiliar[i][j];
         }
    }
       this->computarIntDataFromData();
}

void cImagen::Erosion()
{
    int auxiliar[400][400];

    // Matriz auxiliar
    for (int i = 0; i < 400; i++)
    {
        for (int j = 0; j < 400; j++)
        {
            auxiliar[i][j]=255;
        }
    }

     //Recorro matriz, toca foto=> pixel central de aux es 255
    for (int i = 2; i < this->ancho-2; i++)
    {
        for (int j = 2; j < this->alto-2; j++)
        {

                 if(int_data[i][j-1]==0
                 || int_data[i-1][j-1]==0
                 || int_data[i+1][j-1]==0
                 || int_data[i-1][j]==0
                 || int_data[i][j]==0
                 || int_data[i+1][j]==0
                 || int_data[i-1][j+1]==0
                 || int_data[i][j+1]==0
                 || int_data[i+1][j+1]==0
                 || int_data[i][j-2]==0
                 || int_data[i-2][j]==0
                 || int_data[i+2][j]==0
                 || int_data[i][j+2]==0
                 || int_data[i+1][j-2]==0
                 || int_data[i+2][j-1]==0
                 || int_data[i+2][j+1]==0
                 || int_data[i+1][j+2]==0
                 || int_data[i-1][j+2]==0
                 || int_data[i-2][j+1]==0
                 || int_data[i-2][j-1]==0
                 || int_data[i-1][j-2]==0)
                 {
                     auxiliar[i][j]=0;
                 }
            }

    }

    // Copio aux a imagen
    for (int i = 0; i < 400; i++)
        for (int j = 0; j < 400; j++)
            data[i][j]=255;

    for (int i = 0; i < 400; i++)
    {
     for (int j = 0; j < 400; j++)
         {
            data[i][j]=auxiliar[i][j];
         }
    }
        this->computarIntDataFromData(false);

}


void cImagen::Binarizacion()
{

    suavizarFiltroMediana();

    suavizarMascara();
    aplicarMascara();
    suavizarMascara();
    aplicarMascara();
    suavizarMascara();
    aplicarMascara();
    suavizarMascara();
    aplicarMascara();

    Isodata();

}

void cImagen::CrecimientoDeRegion()
{
    QList<Punto*> * Lista = new QList<Punto*>;
    unsigned int ** imagenAux;
    imagenAux = new unsigned int* [ancho];
    for(int i=0; i<ancho; ++i)
        imagenAux[i] = new unsigned int[alto];
    unsigned int ** resultado;
    resultado = new unsigned int* [ancho];
    for(int i=0; i<ancho; ++i)
        resultado[i] = new unsigned int[alto];

    Punto * p;
    Punto * inicial;

    int max = 0, cont;

    for(int i=0;i<ancho;i++)
    {
        for(int j=0;j<alto;j++)
        {
            if(int_data[i][j]==0) //Es semilla
            {
                cont = 0;

                for(int i=0;i<ancho;i++){
                    for(int j=0;j<alto;j++){
                        imagenAux[i][j]=255.0;
                    }
                }
                p = new Punto;
                // En vez de elegir como semilla al centro, meter esto en un doble for, e ir usando cada semilla.
                p->x=j;
                p->y=i;
                imagenAux[p->x][p->y]=0;
                int_data[p->x][p->y]=255;
                Lista->append(p);
                cont++;

                do
                {
                    inicial = (Punto*) Lista->at(0);
                    if(inicial->x-1 >= 0 && inicial->x-1 < ancho && inicial->y >= 0 && inicial->y < alto)
                        if(int_data[inicial->x-1][inicial->y]==0)
                        {
                            p = new Punto;
                            p->x = inicial->x-1;
                            p->y = inicial->y;
                            imagenAux[p->x][p->y]=0;
                            int_data[p->x][p->y]=255;
                            Lista->append(p);
                            cont++;
                        }
                    if(inicial->x+1 >= 0 && inicial->x+1 < ancho && inicial->y >= 0 && inicial->y <alto)
                        if(int_data[inicial->x+1][inicial->y]==0)
                        {
                            p = new Punto;
                            p->x = inicial->x+1;
                            p->y = inicial->y;
                            imagenAux[p->x][p->y]=0;
                            int_data[p->x][p->y]=255;
                            Lista->append(p);
                            cont++;
                        }
                    if(inicial->x >= 0 && inicial->x < ancho && inicial->y-1 >= 0 && inicial->y-1 <alto)
                        if(int_data[inicial->x][inicial->y-1]==0)
                        {
                            p = new Punto;
                            p->x = inicial->x;
                            p->y = inicial->y-1;
                            imagenAux[p->x][p->y]=0;
                            int_data[p->x][p->y]=255;
                            Lista->append(p);
                            cont++;
                        }
                    if(inicial->x >= 0 && inicial->x < ancho && inicial->y+1 >= 0 && inicial->y+1 <alto)
                        if(int_data[inicial->x][inicial->y+1]==0)
                        {
                            p = new Punto;
                            p->x = inicial->x;
                            p->y = inicial->y+1;
                            imagenAux[p->x][p->y]=0;
                            int_data[p->x][p->y]=255;
                            Lista->append(p);
                            cont++;
                        }
                    delete inicial;
                    Lista->removeFirst();
                } while(Lista->count()>0);

                if(cont > max)
                {
                    max = cont;
                    for(int i=0;i<ancho;i++)
                        for(int j=0;j<alto;j++)
                            resultado[i][j] = imagenAux[i][j];
                }
            }
        }
    }

    // max es el área del lunar

    // Cálculo del centro del lunar
    for(int i=0;i<ancho;i++)
        for(int j=0;j<alto;j++)
        {
            MatrizBinarizada[i][j]=resultado[i][j];
            this->data[i][j]=resultado[i][j];
        }

    int x1 = 0, y1 = 0;
    for(int i=0;i<ancho;i++)
        for(int j=0;j<alto;j++)
            if(data[i][j] == 0)
            {
                x1 += j;
                y1 += i;
            }
    centroX = x1/max;
    centroY = y1/max;
    //

    this->computarIntDataFromData();

    for(int i=0; i<ancho; ++i)
        delete [] imagenAux[i];
    delete [] imagenAux;
    for(int i=0; i<ancho; ++i)
        delete [] resultado[i];
    delete [] resultado;

    area=max;
}

// Análisis de los parámetros de riesgo-------------------------------

float cImagen::Diametro()
{
    float r1=0,r2=0;
    int D=0,i;
    float alfa=0,deltaT=3.1415/50,deltaR=0.7,x1,x2,y1,y2;
    Dmayor=0;
    for(int j=0;j<50;j++)
    {
        i=0;
        alfa=j*deltaT;
        do
        {   i++;
            r1=i*deltaR;
            x1=r1*cosf(alfa)+centroX;
            y1=r1*sinf(alfa)+centroY;

        }while (MatrizBinarizada[(int)y1][(int)x1]==0);
        i=0;
        do
        {   i++;
            r2=-i*deltaR;
            x2=r2*cosf(alfa)+centroX;
            y2=r2*sinf(alfa)+centroY;

        }while (MatrizBinarizada[(int)y2][(int)x2]==0);
        D=r1-r2;
        if(D>Dmayor)
        {
            Dmayor=D;
            Ym1=y1;
            Ym2=y2;
            Xm1=x1;
            Xm2=x2;
            angulo=alfa;
        }

    }
    return Dmayor;
}

void cImagen::Simetria()
{
    float r=0;
    int i;
    float alfa=0,deltaT=(2*3.141592)/100;
    float deltaR=0.7,x,y;
    float mediar=0,desvior=0,n=0; // Referidos a los radios
    FILE * fp;
    fp = fopen("c://radios.txt", "w");
    QString str;
    for(int j=0;j<100;j++)
    {
        i=0;
        alfa=j*deltaT;
        do
        {   i++;
            r=i*deltaR;
            x=r*cosf(alfa)+centroX;
            y=r*sinf(alfa)+centroY;

        }while (MatrizBinarizada[(int)y][(int)x]==0);
       mediar+=r;
       n++;


    str = QString::number(r);
    fwrite(str.toStdString().c_str(), 5, 1, fp);
    str = "\n";
    fwrite(str.toStdString().c_str(), 1, 1, fp);


    }
    fclose(fp);
    mediar=mediar/n;
    for(int j=0;j<100;j++)
    {
        i=0;
        alfa=j*deltaT;
        do
        {
            i++;
            r=i*deltaR;
            x=r*cosf(alfa)+centroX;
            y=r*sinf(alfa)+centroY;

        }while (MatrizBinarizada[(int)y][(int)x]==0);

       desvior+=(r-mediar)*(r-mediar);
       n++;
    }
    desvior=desvior/n;
    coef_variabilidad=(desvior/mediar)*100;


}

void cImagen::Sobel()
{
    mascara[0][0] = -0.25;
    mascara[0][1] = -0.5;
    mascara[0][2] = -0.25;
    mascara[1][0] = 0.0;
    mascara[1][1] = 0.0;
    mascara[1][2] = 0.0;
    mascara[2][0] = 0.25;
    mascara[2][1] = 0.5;
    mascara[2][2] = 0.25;
}

void cImagen::Borde()
{
    //Sobel
    /*
    Sobel();
    aplicarMascara();
    */
    //Gradiente
    float Gx, Gy;
    float ** G;
    G = new float* [ancho];
    for(int i=0; i<ancho; ++i)
        G[i] = new float[alto];
    float suma=0,max=0,min=data[0][0];
    int n=0;

    for (int i = 0; i < this->ancho; i++)
        for (int j = 0; j < this->alto; j++)
            G[i][j]=0;

    for (int i = 1; i < this->ancho-1; i++)
    {
        for (int j = 1; j < this->alto-1; j++)
        {
            Gx = (data[i-1][j+1]+2*data[i][j+1]+data[i+1][j+1])-(data[i-1][j-1]+2*data[i][j-1]+data[i+1][j-1]);
            Gy = (data[i+1][j-1]+2*data[i+1][j]+data[i+1][j+1])-(data[i-1][j-1]+2*data[i-1][j]+data[i-1][j+1]);
            G[i][j]= fabs(Gx) + fabs(Gy);

            if(G[i][j]<min) min=G[i][j];
            if(G[i][j]>max) max=G[i][j];

        }
    }

    // Si pasan umbral relativo los promedio (del gradiente original)
    for (int i = 0; i < this->ancho; i++)
    {
        for (int j = 0; j < this->alto; j++)
        {
            if((((G[i][j]-min)*100)/(max-min))>=30) //xp(((x-a)*(d-c))/(b-a))+c       si supera el 30%
            {
                suma+=G[i][j];
                n++;
            }
        }
    }
    promedio=suma/(float)n;

    for(int i=0; i<ancho; ++i)
        delete [] G[i];
    delete [] G;
}

void cImagen::Color(int ** mbin)
{

    // Desvio estandar
    // De matriz binarizada sacamos pixeles que nos interesan sacar desvio

    float media=0.0;
    desvio=0.0; // Variable global
    int N = 0;

    for(int i=0;i<this->ancho;i++)
    {
        for(int j=0;j<this->alto;j++)
        {
            if(mbin[j][i]==0) // Si es lunar
            {
                media+=data[j][i]; // La matriz 'original' la definimos en cargar imagen-linea 146- y es = a 'data' inicial
                N++;
            }
        }
    }
    media=media/(float)N;

    N = 0;
    for(int i=0;i<this->ancho;i++)
    {
        for(int j=0;j<this->alto;j++)
        {
            if(mbin[j][i]==0) // Si es lunar
            {
                desvio+=(data[j][i]-media)*(data[j][i]-media);
                N++;
            }
        }
    }
    desvio=desvio/(float)N;
    computarIntDataFromData();
}

