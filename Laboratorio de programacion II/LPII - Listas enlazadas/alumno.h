#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream.h>
#include <string>

using namespace std;

class alumno
{
private:
        string nombre;
        string apellido;
        string mail;


public:
        alumno(string, string,string);
        ~alumno(){};

        void setNombre();
        void setApellido();
        void setMail();

        string getNombre();
        string getApellido();
        string getMail();
};



#endif
 