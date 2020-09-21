#ifndef CPERSONA_H
#define CPERSONA_H
#include <iostream.h>
#include <string.h>

using namespace std;

class cPersona
{
protected:
        const string nombre;
        unsigned int edad;
        static unsigned int cant_personas;

public:
        cPersona(string, unsigned int edad=10);
        cPersona(const cPersona&);
        virtual ~cPersona(){};

        string getnombre()const; //metodos constantes porque no modifican los atributos de la clase
        unsigned int getedad()const;
        static unsigned int getcant_personas();

        void setedad(unsigned int);

        virtual cPersona operator+(const cPersona&)const;
        friend cPersona operator*(const cPersona&, const cPersona&);
        friend ostream& operator<<(ostream&, const cPersona&);

};
istream& operator>>(istream&, cPersona&);
cPersona operator-(const cPersona&, const cPersona&);
#endif
