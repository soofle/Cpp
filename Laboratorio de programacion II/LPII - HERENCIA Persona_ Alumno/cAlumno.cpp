


#include "cAlumno.h"
#include <iostream>
#include <string>

using namespace std;


cAlumno::cAlumno( unsigned long int DNI, unsigned long LU, string N, string A):cPersona(DNI,N,A), LU(LU)
{
Universidad="";
Facultad="";
Carrera="";
materias_aprobadas=0;

//for para notas[i]=0;
//   cPersona::
}
cAlumno::cAlumno( unsigned long int DNI, unsigned long LU, cAlumno& AL):cPersona(DNI, AL.Nombre, AL.Apellido), LU(LU)
{
Universidad=AL.getUniversidad();
Facultad=AL.getFacultad();
Carrera=AL.getCarrera();
materias_aprobadas=AL.getMaterias();

//for para notas[i]=0;
}
cAlumno::cAlumno( unsigned long int DNI, unsigned long LU, cPersona& P):cPersona(DNI,P),LU(LU)
{
Universidad="";
Facultad="";
Carrera="";
materias_aprobadas=0;
//for para notas[i]=0;

}
cAlumno::~cAlumno()
{
//Deberiamos borrar la lista de materias que estamos cursando
}

//getters y setters
void cAlumno::setUniversidad(string U){Universidad=U;}
void cAlumno::setFacultad(string F){Facultad=F;}
void cAlumno::setCarrera(string C){Carrera=C;}

void cAlumno::setMaterias(unsigned int M){materias_aprobadas=M;}
void cAlumno::setNotas(unsigned int *notas)
{
//for i=0<cantidad notas
//        this->Notas[i]=notas[i]
}


string cAlumno::getUniversidad()const{return Universidad;}
string cAlumno::getFacultad()const{return Facultad;}
string cAlumno::getCarrera()const{return Carrera;}

unsigned int cAlumno::getMaterias(){return materias_aprobadas;}
unsigned int* cAlumno::getNotaS(){return Notas;}


istream& operator>>(istream& in, cAlumno& A)
{

in>>A.Nombre;
in>>A.Apellido;
in>>A.materias_aprobadas;
return in;

}
ostream& operator<<(ostream& out, const cAlumno&A)
{

        out<<cPersona(A);

        out<<A.Universidad<<" "<<A.Facultad<<" "<<A.Carrera;
        return out;

}

 