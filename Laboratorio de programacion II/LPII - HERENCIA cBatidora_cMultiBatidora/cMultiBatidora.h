
#ifndef CMULTIBATIDORA_H
#define CMULTIBATIDORA_H


#include "cBatidora.h"
#include <iostream>
#include <string>
using namespace std;


class cMultibatidora:public cBatidora
{
protected:
string wifi;
const unsigned int cant_helices;
string tipobowl;

public:
cMultibatidora( const unsigned int SN, const unsigned int cant_Helices);
~cMultibatidora();


//Getter  y setters

void setWIFI(string ="G");
void setTipoBowl(string ="acero");


string getWIFI();
string getTipobowl();


//sobrecargas y demas

friend ostream& operator<<(ostream&,const cMultibatidora&);
friend istream& operator>>(istream&,cMultibatidora&);
};





#endif
