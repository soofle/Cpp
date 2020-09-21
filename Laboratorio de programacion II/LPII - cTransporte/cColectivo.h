#ifndef CCOLECTIVO_H
#define CCOLECTIVO_H
#include "cTransporte"
#include <iostream>
#include <string.h>
using namespace std;

class cColectivo:public cTransporte{

                public:
                        cColectivo();
                        ~cColectivo(){};
                        bool Encender();
                        bool Acelerar();
                        bool Parar();
                        bool Apagar();

                        //seters
                        setCantPasaj(unsigned int c){CantPasaj=c};
                        setCostoViaje(float v){CostoViaje=v};
                        setEstado(bool true){Estado=true};
                        setRapidez(float r){Rapidez=r};
                        //geters
                        unsigned int getCantPasaj(){return c};
                        float getCostoViaje(){return v};
                        bool getEstado(){return true};
                        float Rapidez(){return r};



};
#endif;
 