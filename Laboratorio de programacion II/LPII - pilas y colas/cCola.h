#ifndef CCOLA_H
#define CCOLA_H
#include <iostream.h>
#include <string>
#include "NodoCola.h"




class cCola{

public:
        cCola();
        ~cCola();

        bool vacia()const;       //devuelve true si est� vac�a
        void push(ElementoCola dato);
        ElementoCola* mostrar();
        bool pop();

        void operator=(cCola& rabito);
       

private:
        NodoCola *Frente,*Final,*Auxiliar;


};
#endif
 
