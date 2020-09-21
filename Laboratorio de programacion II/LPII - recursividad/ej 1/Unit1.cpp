//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------
#pragma argsused
#include <iostream>
#include <stdio.h>

using namespace std;


//---------------------------------------------------------------------------

int cantidadenteros(int entero)
{

        cout<<entero-(entero/10)<<endl;
        if(entero<10)                       //caso base
        return 1;

        entero=entero/10;                   //recursividad
        return cantidadenteros(entero)+1;


};

int invertir_recursivo(int entero)
{



}

int invertir_norecursivo(int entero)
{
        int i;
        int n=cantidadenteros(entero);
        int array[10];
        for(i=0;i<n;i++)
        {
        array[n]=entero/10;
        n--;
        }
        return array[n];

}


//---------------------------------------------------------------------------
main()
{
int numerito;
int digitos=0;
cout<<"Ingrese el numero"<<endl;
cin>>numerito;
digitos=cantidadenteros(numerito);
cout<<"Su numero tiene "<<digitos<<" enteros"<<endl;



system("pause");


        return 0;
}
//---------------------------------------------------------------------------


