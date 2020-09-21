// Clase cRacional
//Hija de la clase cNumeros

using namespace std;

class cRacional: public cNumeros {

public:
       cRacional(int numerador, int denominador, double resultado = 0, string tipo = " "):cNumeros(tipo)
       {             this-> numerador = numerador;
                     this-> denominador = denominador;
                     this-> resultado = resultado;};

       ~cRacional(){};
       void cociente ();
       void imprimir();

protected:

       int numerador, denominador;
       double resultado;

};

// método que realiza el cociente
// lanza un throw si el denominador = 0;
void cRacional:: cociente (){
          if(denominador == 0)
                     throw edivporcero;
          resultado = double (numerador)/denominador;
}

void cRacional::imprimir(){

     cout<<"numerador : "<<numerador<<endl;
     cout<<"denominador : "<<denominador<<endl;
     cout<<"resultado : "<<resultado<<endl;
     cout<<"tipo : "<<tipo<<endl;

}
