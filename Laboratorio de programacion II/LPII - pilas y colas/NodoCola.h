#ifndef NODOCOLA_H
#define NODOCOLA_H

#include <string>
#include <iostream>

using namespace std;

typedef char ElementoCola;

class NodoCola{

public:
        NodoCola(ElementoCola nuevo, NodoCola* sig = NULL);
        ~NodoCola();

        ElementoCola* getDato()const;
        void setDato(ElementoCola& dat);
        NodoCola* getSiguiente()const;
        void setSiguiente(NodoCola* sig);


private:
        ElementoCola* dato;
        NodoCola* siguiente;

};
#endif

