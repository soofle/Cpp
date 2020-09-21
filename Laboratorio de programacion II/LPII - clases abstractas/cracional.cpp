#include <iostream.h>

#include "cnumero.h"
#include "cracional.h"
#include "ccomplejo.h"

cracional::cracional(int n, int d):centero(n)
{
        D=d;
}

cnumero* cracional::operator+(cnumero *r)
{
        if (ccomplejo *b = dynamic_cast <ccomplejo *> (r))
        {
        ccomplejo *a=new ccomplejo(4,4,4,4); //no hacer
        return a;           //¬¬
        }

        if (cracional *d = dynamic_cast <cracional *> (r))
        {
        cracional *a=new cracional;
        a->N=N*d->getD()+d->getN()*D;
        a->D=D*d->getD();
        return a;
        }

        if (centero *d = dynamic_cast <centero *> (r))
        {
        cracional *a=new cracional;
        a->N=N+d->getN()*D;
        a->D=D;
        return a;
        }

         return NULL;

}
/*cnumero* cracional::operator+(const centero &e)
{
        cracional f;
        f.N=N+e.N*D;
        f.D=D;
        return &f;
}  */
ostream& operator<<(ostream& out,const cracional &r)
{
        out<<r.N<<"/"<<r.D<<endl;
        return out;
}
istream& operator>>(istream& in,cracional &r)
{
        cout<<"Ingrese el numerador:"<<endl;
        in>>r.N;
        cout<<"Ingrese el denominador:"<<endl;
        in>>r.D;
        return in;
}