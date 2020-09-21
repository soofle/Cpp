//---------------------------------------------------------------------------
#include "cBatidora.h"
#include "cMultiBatidora.h"
#include <iostream>
#include <string>
#pragma hdrstop

//---------------------------------------------------------------------------
using namespace std;

#pragma argsused
int main(int argc, char* argv[])
{
  cBatidora PILIPS(3425, 300, 500);
  //cin>>PILIPS;
  cout<<PILIPS<<endl;

  cout<<PILIPS++<<endl;

  cout<<++PILIPS<<endl;


  cMultibatidora Canziani(12234,6);

  cin>>Canziani;

  cout<<Canziani;


system("pause");
        return 0;
}
//---------------------------------------------------------------------------
