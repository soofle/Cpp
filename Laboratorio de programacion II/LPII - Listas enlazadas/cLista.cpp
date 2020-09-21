#include <iostream.h>
#include <string>
#include "cLista.h"

using namespace std;


cLista::cLista(int maximo):tactual(0)
{
        tmax=maximo;
}


cLista::~cLista()
{
        if(primero!=NULL)
        {
                delete primero;
        }

        if(actual!=NULL)
        {
                delete actual;
        }
}


void cLista::insertar(alumno nuevo, int entradas)
{
        cNodo(nuevo,entradas);
        
}


void cLista::eliminar(int pos)
{
}


void cLista::buscar(alumno buscado)
{
}


void cLista::listar()
{
}


 