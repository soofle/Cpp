#ifndef CPILA_H
#define CPILA_H
#include <iostream.h>
#include <string>
#include "NodoPila.h"




class cPila{

public:
        cPila();
        ~cPila();

        bool vacia()const;       //devuelve true si está vacía
        void push(ElementoPila dato);
        ElementoPila* mostrar();
        bool pop();




private:
        NodoPila *Inicio,*Auxiliar; //agregar puntero a base


};
#endif
 
