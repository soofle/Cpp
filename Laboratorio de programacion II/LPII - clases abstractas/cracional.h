#ifndef CRACIONAL_H
#define CRACIONAL_H
#include <iostream.h>

#include "centero.h"


class cracional:public centero
{
        protected:
                int D;
        public:
                cracional(int n=0, int d=1);
                virtual ~cracional(){};
                void setD(int D){this->D=D;};
                virtual void imprimir(){cout<<*this;};
                int getD(){return D;};
                virtual cnumero* operator+(cnumero*);
                friend ostream& operator<<(ostream&,const cracional&);
                friend istream& operator>>(istream&,cracional&);

};




#endif