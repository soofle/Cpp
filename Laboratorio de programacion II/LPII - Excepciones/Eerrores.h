
using namespace std;
// Clase derivada de la clase exception
// Excepcion de Divisi�n por cero
class EDivisionPorCero : public exception{

public:
       virtual const char* what() const throw()
       {
       return "Division por cero";
       }
} edivporcero;



// Clase derivada de la clase exception
// Excepcion de error de string ingresado
class ECarctVacio : public exception{

public:
       virtual const char* what() const throw()
       {
       return "Tipo de numero mal ingresado";
       }
} ecaract;



