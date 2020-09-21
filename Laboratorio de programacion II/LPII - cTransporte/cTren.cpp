#include "cTransporte"
#include <iostream>
#include <string.h>

cTren::cTren():cTransporte()
{}

bool cTren::Encender()
{
        Estado=true;
        cout<<"El tren esta encendido"<<endl;
        return true;
}
bool cTren::Acelerar()
{
        Rapidez=Rapidez+4;
        cout<<"El tren se esta acelerando"<<endl;
        return true;
}
bool cTren::Parar()
{
        Rapidez=0;
        cout<<"El tren esta frenado"<<endl;
        return true;
}
bool cTren::Apagar()
{
        Estado=false;
        cout<<"El tren esta apagado"<<endl;
        return false;
}
