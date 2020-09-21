#ifndef CESTUDIANTE_H
#define CESTUDIANTE_H
#include "cPersona.h"
#include <string.h>
#include <iostream.h>

using namespace std;

class cEstudiante: public cPersona
// tipos de herencia: publica (no corta la herencia), privada, protegida (le baja un nivel, hereda.
{
protected:
        unsigned int promedio;
public:
        cEstudiante(string n, unsigned int):cPersona(n){};
        virtual ~cEstudiante(){};

        unsigned int getpromedio(){return promedio;};

        void setpromedio(unsigned int promedio){this->promedio=promedio;};

        virtual cPersona operator+(const cPersona&)const=0;

};
#endif;
