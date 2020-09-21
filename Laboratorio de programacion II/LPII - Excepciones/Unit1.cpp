//---------------------------------------------------------------------------
#include <iostream>
#include <string.h>
#include "Eerrores.h"
#include "cNumeros.h"
#include "cRacional.h"

using namespace std;


int main () {


int numerador, denominador;
double resultado;
string tipo;

cout<< "introduzca tipo de numero: ";
cin>>tipo;
cout<< "introduzca numerador: ";
cin>>numerador;
cout<<endl<<"introduzca denomiandor: ";
cin>>denominador;
cout<<endl;

cRacional racional(numerador, denominador);

          try{

          racional.cociente();

          }
          catch (exception& error){
                cout<< "ocurrio una excepcion : "<<error.what() << '\n';
          }

          try{

          racional.setTipo(tipo);

          }
          catch (exception& error){
                cout<< "ocurrio una excepcion : "<<error.what() << '\n';
          }

          racional.imprimir();
          system("pause");
          return 0;
}
//---------------------------------------------------------------------------
