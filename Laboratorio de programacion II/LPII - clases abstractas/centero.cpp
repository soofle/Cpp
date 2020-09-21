#include <iostream.h>
#include "centero.h"
#include "cracional.h"
#include "ccomplejo.h"

centero::centero(int n):cnumero()
{
        N=n;
}

/*cnumero* centero::operator+(cnumero *e)
{
        centero a;
        a.N=N+e.N;
        return &a;
} */
ostream& operator<<(ostream& out,const centero& e)
{
        out<<"El numero entero es:"<<e.N<<endl;
        return out;
}
istream& operator>>(istream& in,centero& e)
{
        int a;
        cout<<"Ingrese el numero entero:"<<endl;
        in>>a;
        e.setN(a);
        return in;
}

cnumero* centero::operator+ (cnumero *n)
{
        if (ccomplejo *b = dynamic_cast <ccomplejo *> (n))
        {
        ccomplejo *a=new ccomplejo(N*(b->getD())+(b->getN()),b->getD(),b->getIN(),b->getID());
        return a;           //¬¬
        }

        if (cracional *d = dynamic_cast <cracional *> (n))
        {
        cracional *a=new cracional(N*d->getD()+d->getN(),d->getD());
        return a;
        }

        if (centero *r = dynamic_cast <centero *> (n))
        {
        centero *a=new centero;
        a->N=N+r->getN();
        return a;
        }
        
        return NULL;
}
 