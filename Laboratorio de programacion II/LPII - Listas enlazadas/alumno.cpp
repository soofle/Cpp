#include "alumno.h"
#include <string>

using namespace std;

alumno::alumno(string n, string a, string m)
{
        nombre=n;
        apellido=a;
        mail=m;
}


void alumno::setNombre(string n)
{
        nombre=n;
}

void alumno::setApellido(string a)
{
        apellido=a;
}

void alumno::setMail(string m)
{
        mail=m;
}


string alumno::getNombre()
{
        return nombre;
}


string alumno::getApellido()
{
        return apellido;
}


int alumno::getMail()
{
        return mail;
}
