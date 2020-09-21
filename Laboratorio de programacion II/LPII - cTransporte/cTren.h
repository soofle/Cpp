#ifndef CTREN_H
#define CTREN_H
#include "cTransporte"
#include <iostream>
#include <string.h>
using namespace std;

class cTren:public cTransporte{
{
        public:
                        cTren();
                        ~cTren(){};
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