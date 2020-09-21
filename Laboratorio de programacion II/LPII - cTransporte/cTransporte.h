#ifndef CTRANSPORTE_H
#define CTRANSPORTE_H
#include <iostream>
#include <string.h>
using namespace std;

class cTransporte{
        protected:
                unsigned int CantPasaj;
                float CostoViaje;
                bool Estado;
                float Rapidez;

        public:
                cTransporte();
                virtual ~cTransporte(){};
                virtual bool Encender()=0;
                virtual bool Acelerar()=0;
                virtual bool Parar()=0;
                virtual bool Apagar()=0;


};
#endif
