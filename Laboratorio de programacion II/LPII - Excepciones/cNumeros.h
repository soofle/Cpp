// Clase cNumeros

using namespace std;

class cNumeros {

public:
       cNumeros(string tipo = ""){ this->tipo = tipo;};
       ~cNumeros(){};
       void setTipo(string tipo);
       void imprimir();

protected:
       string tipo;
};

// m�todo set tipo
// lanza una excepci�n si el string ingresado no corresponde al tipo.
void cNumeros:: setTipo (string tipo){
          if(tipo != "Racional" && tipo != "racional")
                     throw ecaract;
          this->tipo = tipo;
}

void cNumeros::imprimir(){

     cout<<"tipo : "<<tipo<<endl;

}
 