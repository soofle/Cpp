//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#include "cnumero.h"
#include "centero.h"
#include "cracional.h"
#include "ccomplejo.h"

#include<iostream.h>
#pragma argsused

int main(int argc, char* argv[])
{
        cnumero *array[6];
        cout<<cnumero::getcant()<<endl;

        array[0]=new centero(1);
        array[1]=new centero(2);
        array[2]=new cracional(1,2);
        array[3]=new cracional(1,4);
        array[4]=new ccomplejo(1,1,1,1);
        array[5]=new ccomplejo(2,4,2,4);
                cout<<cnumero::getcant()<<endl;


(*array[0]+array[1])->imprimir();
(*array[2]+array[3])->imprimir();
(*array[4]+array[5])->imprimir();

(*array[2]+array[0])->imprimir();
(*array[4]+array[2])->imprimir();
(*array[4]+array[0])->imprimir();

(*array[0]+array[2])->imprimir();
(*array[0]+array[4])->imprimir();
(*array[2]+array[4])->imprimir();

cout<<"--------------------"<<endl;
cout<<"--------------------"<<endl;
cout<<"--------------------"<<endl;


        cout<<*(*array[0]+array[1])<<endl;
        cout<<*(*array[2]+array[3])<<endl;
        cout<<*(*array[4]+array[5])<<endl;

        cout<<*(*array[2]+array[0])<<endl;
        cout<<*(*array[4]+array[2])<<endl;
        cout<<*(*array[4]+array[0])<<endl;

        cout<<*(*array[0]+array[2])<<endl;
        cout<<*(*array[0]+array[4])<<endl;
        cout<<*(*array[2]+array[4])<<endl;

        

        system("pause");

        return 0;
}
//---------------------------------------------------------------------------
