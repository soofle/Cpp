#include "myqimage.h"

myQImage::myQImage() :
    QImage()
{
    this->initFloatData(0,0);
    this->fill(0);
    this->identityLUT();
}


myQImage::myQImage(int width, int height, Format format) : QImage(width, height, format)
{
    this->initFloatData(width, height);
    this->fill(0);
}

myQImage::myQImage(const QString &fileName, const char* format) : QImage(fileName, 0)
{
    this->initFloatData(this->width(), this->height());
    this->fill(0);
}

void myQImage::initFloatData(int width, int height)
{
    this->flt_data = new float* [width];
    for(int i = 0; i < width; ++i)
        this->flt_data[i] = new float[height];
}

myQImage::~myQImage()
{
    if(this->flt_data)
    {
        for(int i=0; i<this->width(); ++i)
            delete [] flt_data[i];
        delete [] flt_data;
    }
    flt_data = NULL;
}

void myQImage::setLUT()
{
    this->setColorTable(LUT);
}

void myQImage::identityLUT()
{
    QRgb color;

    for (int i = 0; i < 256; ++i)
    {
        color = i;
        LUT.append(color);
    }
}

void myQImage::setBrightnessAndContrast(float bright, float cont)
{
    int out_color;

    for (int i = 0; i < LUT.count(); ++i)
    {
        out_color = cont*i + bright;

        if (out_color > 255)
            out_color = 255;
        if(out_color < 0)
            out_color = 0;
        LUT[i] = out_color;
    }

    this->setLUT();
}








