#ifndef CNUMERO_H
#define CNUMERO_H
#include <iostream.h>

/*
class cnumero;
class centero;
class cracional;
class ccomplejo;
*/


class cnumero{
protected:
        static unsigned int cant;
public:
        cnumero(){cant++;};
        //cnumero(){};
        virtual ~cnumero(){};
        virtual void imprimir()=0;
        virtual cnumero* operator+ (cnumero*)=0;
        static unsigned int getcant(){return cant;};
        static void setcant(unsigned int c){cant=c;};
        friend ostream& operator<<(ostream&,cnumero&);
        friend istream& operator>>(istream&,cnumero&);
};
unsigned int cnumero::cant=0;



#endif;
