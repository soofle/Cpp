#ifndef CENTERO_H
#define CENTERO_H
#include <iostream.h>
#include "cnumero.h"


class centero:public cnumero{

protected:
        int N;
public:
        centero(int n=0);
        virtual ~centero(){};
        void setN(int N){this->N=N;};
        virtual void imprimir(){cout<<*this;};
        int getN(){return N;};
        virtual cnumero* operator+(cnumero*);
        friend ostream& operator<<(ostream&,const centero&);
        friend istream& operator>>(istream&,centero&);

};
#endif
