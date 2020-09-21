#include <iostream.h>
#include "ccomplejo.h"


ostream& operator<<(ostream& out, cnumero& n)
{
        try{
        ccomplejo &d = dynamic_cast <ccomplejo &> (n);
        out<<d;
        } catch(...)
        {        try{
        cracional &d = dynamic_cast <cracional &> (n);
        out<<d;
        } catch(...)
        {try{
        centero &d = dynamic_cast <centero &> (n);
        out<<d;
        } catch(...){}}
        }


        return out;
}
istream& operator>>(istream& in,cnumero& n)
{

        return in;
}
 