#ifndef CALUMNO_H#define CALUMNO_H


#include "cPersona.h"
#include <iostream>
#include <string>
using namespace std;


class cAlumno :public cPersona
{
protected:
const unsigned long LU;
string Universidad, Facultad, Carrera;
//cMateria *Materias[MATERIASMAX];
unsigned int materias_aprobadas;
unsigned int Notas[100];

public:
cAlumno( unsigned long int DNI, unsigned long LU, string N="", string A="");
cAlumno( unsigned long int DNI, unsigned long LU, cAlumno&);
cAlumno( unsigned long int DNI, unsigned long LU, cPersona&);
~cAlumno();

//getters y setters
void setUniversidad(string);
void setFacultad(string);
void setCarrera(string);

void setMaterias(unsigned int);
void setNotas(unsigned int *);


string getUniversidad()const;
string getFacultad()const;
string getCarrera()const;

unsigned int getMaterias();
unsigned int* getNotaS();


friend istream& operator>>(istream&, cAlumno&);
friend ostream& operator<<(ostream&, const cAlumno&);

};
#endif








 