#include <iostream.h>
#include <string>
#include "cPila.h"


/*-----   cPila   -----*/
cPila::cPila()
{
 Inicio=Auxiliar=NULL;
}

cPila::~cPila()
{}

bool cPila::vacia()const
{if(Inicio==NULL) return true;
 return false;
}


void cPila::push(ElementoPila dato)
{
 Auxiliar = new NodoPila(dato, NULL);

 Auxiliar->setSiguiente(Inicio);

 Inicio=Auxiliar;
}

bool cPila::pop()
{
 if(vacia()) return false;          //no hay elementos para borrar
 Auxiliar=Inicio->getSiguiente();
 delete Inicio;
 Inicio=Auxiliar;
 return true;
}



ElementoPila* cPila::mostrar()
{
 if(Inicio!=NULL) return Inicio->getDato();
 else return NULL;
}







