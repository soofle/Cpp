#ifndef CESTUDIANTEUNIVERSITARIO_H
#define CESTUDIANTEUNIVERSITARIO_H
#include "cEstudiante.h"
#include <string.h>
#include <iostream.h>

using namespace std;

class cEstudianteUniversitario: public cEstudiante
{
private:
        const unsigned int nro_libreta;
        unsigned int cant_materias;
public:
        cEstudianteUniversitario(string n, unsigned int p, unsigned int, int cant_materias=5);
        virtual ~cEstudianteUniversitario(){};

        unsigned int getnro_libreta() const{return nro_libreta;};
        unsigned int getcant_materias(){return cant_materias;};

        void setcant_materias(unsigned int cant_materias){this->cant_materias=cant_materias;};

        virtual cPersona operator+(const cPersona*)const;
};
#endif;
