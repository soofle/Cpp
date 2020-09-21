//---------------------------------------------------------------------------

#pragma hdrstop
#include "cPersona.h"

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
/*

1ro

tipo de variables
clases
punteros
const - static
sobrecarga
tipos de constructores
friend


2do

herencia (tipos de herencia)
polimorfismo
excepciones
clases abstractas

*/
cout<<cPersona::getcant_personas()<<endl;
cPersona p("pepee");
cout<<cPersona::getcant_personas()<<endl;
cin>>p;
cout<<p<<endl;
cPersona h("hernan");
cout<<h*p<<endl;
cout<<h-p<<endl;
cout<<h+p<<endl;

        system("pause");
        return 0;
}
//---------------------------------------------------------------------------
 