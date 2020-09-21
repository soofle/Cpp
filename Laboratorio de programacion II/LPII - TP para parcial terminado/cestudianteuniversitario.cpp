#include "cEstudianteUniversitario.h"
#include <string.h>
#include <iostream.h>

using namespace std;



cEstudianteUniversitario::cEstudianteUniversitario(string n, unsigned int p, unsigned int a, int cant_materias):cEstudiante(n, p),nro_libreta(a)
{
        this->cant_materias=cant_materias;
};

cPersona cEstudianteUniversitario::operator+(const cPersona *a)const
{
        if(cEstudianteUniversitario *b = dynamic_cast <cEstudianteUniversitario *> (a))
        {
                cEstudianteUniversitario *s = new cEstudianteUniversitario;
                 
        }
};
 