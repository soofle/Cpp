#include "NodoCola.h"

/*-----   NodoCola   -----*/
NodoCola::NodoCola(ElementoCola nuevo, NodoCola* sig)
                        {dato = new ElementoCola(nuevo);
                         siguiente = sig;}
NodoCola::~NodoCola(){delete (dato);}

ElementoCola* NodoCola::getDato()const {return dato;}
void NodoCola::setDato(ElementoCola& dat) {*dato = dat;}
NodoCola* NodoCola::getSiguiente()const {return siguiente;}
void NodoCola::setSiguiente(NodoCola* sig) {siguiente=sig;}
 