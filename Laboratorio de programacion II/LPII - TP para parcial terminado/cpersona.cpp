#include "cPersona.h"
#include <string.h>
#include <iostream.h>

using namespace std;

cPersona::cPersona(string a, unsigned int edad):nombre(a)
{
        this->edad=edad;
        cant_personas++;
};

cPersona::cPersona(const cPersona &a):nombre(a.nombre)
{
        edad=a.edad;
        cant_personas++;
};


unsigned int cPersona::cant_personas=0;

string cPersona::getnombre()const{return nombre;}
unsigned int cPersona::getedad()const{return edad;}
unsigned int cPersona::getcant_personas(){return cant_personas;}

void cPersona::setedad(unsigned int edad){this->edad=edad;}

cPersona cPersona::operator+(const cPersona &a)const
{
cPersona c(a.nombre+nombre);
c.edad=a.edad+edad;
return c;
};

cPersona operator*(const cPersona &a, const cPersona &b)
{
cPersona c(a.nombre+b.nombre);
c.edad=a.edad*b.edad;
return c;
};

ostream& operator<<(ostream &out, const cPersona &a)
{
out<<a.nombre<<a.edad<<endl;
return out;
};

cPersona operator-(const cPersona &a, const cPersona &b)
{
cPersona c("pepe");
c.setedad(a.getedad()-b.getedad());
return c;
};


istream& operator>>(istream &in, cPersona &a)
{
unsigned int aux;
in>>aux;
a.setedad(aux);
return in;
};




