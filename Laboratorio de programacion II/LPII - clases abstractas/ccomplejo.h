#ifndef CCOMPLEJO_H
#define CCOMPLEJO_H
#include <iostream.h>

#include "cracional.h"


class ccomplejo:public cracional
{
        protected:
                int IN;
                int ID;
        public:
                ccomplejo(int n=0, int d=1, int in=0, int id=1);
                virtual ~ccomplejo(){};
                void setIN(int IN){this->IN=IN;};
                int getIN(){return IN;};
                void setID(int ID){this->ID=ID;};
                int getID(){return ID;};
                virtual void imprimir(){cout<<*this;};
                virtual cnumero* operator+(cnumero*);
                friend ostream& operator<<(ostream&,const ccomplejo&);
                friend istream& operator>>(istream&,ccomplejo&);


};
#endif
 