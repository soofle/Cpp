//---------------------------------------------------------------------------

#pragma hdrstop


// Este programa recibe una expresi�n algebraica compuesta de n�meros y operaciones
// de + - * / y % en notaci�n infija y la transforma en notaci�n Prefija y Postfija.
// En caso de poner n�meros de m�s de un d�gito, a la salida no se notar� la diferencia.

//---------------------------------------------------------------------------

#pragma argsused
#include "cCola.h"
#include "cPila.h"

bool Precedencia(char previo, char nuevo);
void notPostfija(cCola& infija, cCola& Postfija);
void notPrefija(cPila& infija, cPila& Prefija);

int main(int argc, char* argv[])
{char letra;
 cCola Infija, infijaAUX;
 cCola Postfija;
 cPila Prefija, infijaPila;


 while(letra!='\n')
        {letra=getchar();
         if(letra != '\n') Infija.push(letra);
        }
 infijaAUX=Infija;

 notPostfija(infijaAUX, Postfija);

 cout<<"Postfija: \t\t";
 while(!Postfija.vacia())
        {
         cout<<*Postfija.mostrar();
         Postfija.pop();
        }
 cout<<endl<<endl;

 infijaAUX=Infija;                      //infijaAUX se borro en notPostfija

 while(!infijaAUX.vacia())
 {
  infijaPila.push(*(infijaAUX.mostrar()));
  infijaAUX.pop();
 }

 notPrefija(infijaPila, Prefija);

 cout<<"Prefija: \t\t";
 while(!Prefija.vacia())
        {
         cout<<*Prefija.mostrar();
         Prefija.pop();
        }
 cout<<endl<<endl;

 cout<<"Infija Original: \t";                     //forma trucha de imprimir
 while(!Infija.vacia())                         //se elimina cola
        {
         cout<<*Infija.mostrar();
         Infija.pop();
        }
 cout<<endl<<endl;

 system("pause");
 return 0;
}
//---------------------------------------------------------------------------


bool Precedencia(char previo, char nuevo)
{
 if((previo=='*'||previo=='/'||previo=='%')&&(nuevo=='+'||nuevo=='-'))
        return true;    //previo es de mayor precedencia que nuevo

 else if((previo=='+'||previo=='-')&&(nuevo=='*'||nuevo=='/'||nuevo=='%'))
        return false;   //previo es de menor precedencia que nuevo

 else return false;     //previo es de igual o menor precedencia que nuevo

}


void notPostfija(cCola& infija, cCola& Postfija)
{
 cPila auxPila;
 char auxChar;

 while(infija.mostrar()!=NULL)
 {
   auxChar=*(infija.mostrar());

   switch(auxChar)
   {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
             Postfija.push(auxChar);
             break;

    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
             if(!auxPila.vacia())
             {while(Precedencia( *(auxPila.mostrar()) ,auxChar))
                 {
                  Postfija.push(*(auxPila.mostrar()));
                  auxPila.pop();
                  if(auxPila.vacia()) break;
                 }
             }
             auxPila.push(auxChar);
             break;

    case '(':
             auxPila.push(auxChar);
             break;

    case ')':
             if(!auxPila.vacia())
             {while(*(auxPila.mostrar())!='(')
                 {
                  Postfija.push(*(auxPila.mostrar()));
                  auxPila.pop();
                  if(auxPila.vacia()) break;
                 }
             }
             auxPila.pop();    //elimino '('
             break;
    default:
            //podr�a lanzarse una excepcion
            break;
   }   //fin de switch

  infija.pop();

 } //fin de while
 while(!auxPila.vacia())
        {
         Postfija.push(*(auxPila.mostrar()));
         auxPila.pop();
        }

}  //fin de notPostfija




void notPrefija(cPila& infija, cPila& Prefija)
{
 cPila auxPila;
 char auxChar;

 while(infija.mostrar()!=NULL)
 {
   auxChar=*(infija.mostrar());

   switch(auxChar)
   {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
             Prefija.push(auxChar);
             break;

    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
             if(!auxPila.vacia())
             {while(Precedencia( *(auxPila.mostrar()) ,auxChar))
                 {
                  Prefija.push(*(auxPila.mostrar()));
                  auxPila.pop();
                  if(auxPila.vacia()) break;
                 }
             }
             auxPila.push(auxChar);
             break;

    case ')':
             auxPila.push(auxChar);
             break;

    case '(':
             if(!auxPila.vacia())
             {while(*(auxPila.mostrar())!=')')
                 {
                  Prefija.push(*(auxPila.mostrar()));
                  auxPila.pop();
                  if(auxPila.vacia()) break;
                 }
             }
             auxPila.pop();    //elimino '('
             break;
    default:
            //podr�a lanzarse una excepcion
            break;
   }   //fin de switch

  infija.pop();

 } //fin de while
 while(!auxPila.vacia())
        {
         Prefija.push(*(auxPila.mostrar()));
         auxPila.pop();
        }


}  //fin de notPrefija
