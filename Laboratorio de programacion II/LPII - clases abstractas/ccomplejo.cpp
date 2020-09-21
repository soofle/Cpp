#include <iostream.h>

#include "cnumero.h"
#include "ccomplejo.h"
using namespace std;


ccomplejo::ccomplejo(int n, int d, int in, int id):cracional(n,d)
{
        IN=in;
        ID=id;
}

cnumero* ccomplejo::operator+(cnumero *c)
{
        if (ccomplejo *b = dynamic_cast <ccomplejo *> (c))
        {
        ccomplejo *a=new ccomplejo;
        a->N=N*(b->D)+(b->N)*D;
        a->D=b->D*D;
        a->IN=IN*b->ID+b->IN*ID;
        a->ID=b->ID*ID;

        return a;           //¬¬
        }

        if (cracional *r = dynamic_cast <cracional *> (c))
        {
        ccomplejo *a=new ccomplejo;
        a->N=N*r->getD()+r->getN()*D;
        a->D=D*r->getD();
        a->IN=IN;
        a->ID=ID;
        return a;
        }

        if (centero *d = dynamic_cast <centero *> (c))
        {
        ccomplejo *a=new ccomplejo;
        a->N=N+d->getN()*D;
        a->D=D;
        a->IN=IN;
        a->ID=ID;

        return a;
        }

        return NULL;
}

ostream& operator<<(ostream &out,const ccomplejo &c)
{
        out<<c.N<<"/"<<c.D<<"+("<<c.IN<<"/"<<c.ID<<"i)"<<endl;
        return out;
}

istream& operator>>(istream &in, ccomplejo &c)
{
        cout<<"Ingrese el numerador de la parte real:"<<endl;
        c.N;
        in>>c.N;
        cout<<"Ingrese el numerador de la parte imaginaria:"<<endl;
        in>>c.IN;
        cout<<"Ingrese el denominador de la parte real:"<<endl;
        in>>c.D;

        cout<<"Ingrese el denominador de la parte imaginaria:"<<endl;
        in>>c.ID;
        return in;
}
 