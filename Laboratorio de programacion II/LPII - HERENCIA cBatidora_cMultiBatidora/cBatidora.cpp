

#include "cBatidora.h"
#include <iostream>
#include <string>
using namespace std;
/*
static unsigned int botones;
const unsigned int serialnumber;
unsigned int potencia,rpm;
string *elementosabatir;
unsigned int cantactual;
*/

cBatidora::cBatidora(unsigned int serialnumber, unsigned int potencia, unsigned int rpm):serialnumber(serialnumber),elementosabatir(NULL)
{
    this->potencia=potencia;
    this->rpm=rpm;
    cantactual=0;
}

//constructor por copia
cBatidora::cBatidora(unsigned int serial,const cBatidora& otro):serialnumber(serial)   //lo paso por refer y no quiero modificarlo
{
    this->potencia=otro.potencia;
    this->rpm=otro.rpm;
        if(otro.elementosabatir!=NULL){
        cantactual=otro.cantactual;

        elementosabatir=new string[cantactual];

        for(int i=0;i<cantactual;i++)
        {
        elementosabatir[i] =otro.elementosabatir[i];
        }
        }
        else // no tenia elementos a batir
        {
        elementosabatir=NULL;
        cantactual=0;
        }
}
cBatidora::~cBatidora()
{
if(elementosabatir!=NULL)
delete elementosabatir;
cantactual=0;
elementosabatir=NULL;

}


unsigned int cBatidora::botones=5;

// METODOS FUNCIONALES
cBatidora cBatidora::operator++()   //preincremento
{
 rpm+=10;
 return *this;
}

cBatidora cBatidora::operator++(int) //post
{
 cBatidora aux(serialnumber, *this);
 rpm+=10;
 return aux;
}

cBatidora cBatidora::operator+(unsigned int valor) const
{
 cBatidora aux(serialnumber, *this);
 aux.rpm+=valor;
 return aux;
}

string cBatidora::operator[](unsigned int indice) const
{
 if(elementosabatir!=NULL && indice<cantactual)
 return elementosabatir[indice];
 else
 return "";
}

bool cBatidora::operator==(const cBatidora& otro) const
{
 return serialnumber==otro.serialnumber;
}


/*
cBatidora operator++(cBatidora& bati,int v) //post
{
 cBatidora aux(serialnumber, bati);
 ++bati;    //si no es friend
 bati.rpm+=10; //si fuera friend
 return aux;
}
*/

ostream& operator<<(ostream& out,const cBatidora& bati)
{
 cout<<bati.getpotencia()<<endl;
 cout<<bati.getrpm()<<endl;
 return out;
}

istream& operator>>(istream& in,cBatidora& bati)
{
 unsigned int aux;
 cout<<"ingrese rpm";
 cin>>aux;
 bati.setrpm(aux);
 return in;
}
