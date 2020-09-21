//---------------------------------------------------------------------------

#include <string>
#include <iostream>
#include "cPersona.h"
#include "cAlumno.h"
using namespace std;
//---------------------------------------------------------------------------

int main(int argc, char* argv[])
{

cPersona Manuel(31289257, "manuel", "Alfonso");
cPersona *JONA;
JONA=new cPersona(31289257, "JONA");

cAlumno JuanCarlos(1114, 3256, "Nombre", "Apellido");

JONA->setAltura(1.83);
JONA->setPeso(75);

cout<<JONA->getPeso();
JONA->verinfo();
delete JONA;
Manuel.verinfo();

cout<<"\n\n\n";
JuanCarlos.setUniversidad("FVA");
cout<<JuanCarlos<<endl;

        cout<<"JUAN"<<endl;
//Manuel=(cPersona)JuanCarlos;
//cout<<Manuel;


system("Pause");
        return 0;
}
//---------------------------------------------------------------------------
 