#include "cTransporte"
#include <iostream>
#include <string.h>

cColectivo::cColectivo():cTransporte()
{}

bool cColectivo::Encender()
{
        Estado=true;
        cout<<"El colectivo esta encendido"<<endl;
        return true;
}
bool cColectivo::Acelerar()
{
        Rapidez=Rapidez+4;
        cout<<"El colectivo se esta acelerando"<<endl;
        return true;
}
bool cColectivo::Parar()
{
        Rapidez=0;
        cout<<"El colectivo esta frenado"<<endl;
        return true;
}
bool cColectivo::Apagar()
{
        Estado=false;
        cout<<"El colectivo esta apagado"<<endl;
        return false;
}
