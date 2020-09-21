#ifndef MYQIMAGE_H
#define MYQIMAGE_H

#include <QImage>

class myQImage : public QImage
{
//    Q_OBJECT
    float** flt_data;
    void initFloatData(int width, int height);
    QVector<QRgb> LUT;    //Lookup table
    void setLUT();
    void identityLUT();

public:
    explicit myQImage();
    explicit myQImage(int width, int height, Format format);
    explicit myQImage(const QString &fileName, const char *format = 0);

    void setBrightnessAndContrast(float bright, float cont);


    ~myQImage();

};

#endif // MYQIMAGE_H
