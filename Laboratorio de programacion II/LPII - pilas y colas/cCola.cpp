#include <iostream.h>
#include <string>
#include "cCola.h"


/*-----   cCola   -----*/
cCola::cCola()
{
 Frente=Final=Auxiliar=NULL;
}

cCola::~cCola()
{}

bool cCola::vacia()const
{if(Frente==NULL) return true;
 return false;
}


void cCola::push(ElementoCola dato)
{
 Auxiliar = new NodoCola(dato, NULL);
 if(Frente==NULL) Frente=Auxiliar;
 else Final->setSiguiente(Auxiliar);
 Final=Auxiliar;
}


bool cCola::pop()
{
 if(vacia()) return false;          //no hay elementos para borrar
 Auxiliar=Frente->getSiguiente();
 delete (Frente);
 Frente=Auxiliar;
 if(Auxiliar==NULL)Final=NULL;
 return true;
}



ElementoCola* cCola::mostrar()
{
 if(Frente!=NULL) return Frente->getDato();
 else return NULL;
}


void cCola::operator=(cCola& rabito)
{
 rabito.Auxiliar=rabito.Frente;
 while(rabito.Auxiliar!=NULL)
        {this->push(*(rabito.Auxiliar->getDato()));
         rabito.Auxiliar=rabito.Auxiliar->getSiguiente();
        }
}





