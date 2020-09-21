#include <string.h>
#include <iostream>
#ifndef CALUMNO_H
#define CALUMNO_H

using namespace std;

class cAlumno
{
        private:
        string nombre;
        string apellido;
        unsigned int numerolibreta;


        public:
        cAlumno(string nombre, string apellido, unsigned int numerolibreta)
                {
                this->nombre=nombre;
                this->apellido=apellido;
                this->numerolibreta=numerolibreta;
                };
        ~cAlumno(){};

        //*Setters*//
        void setnombre(string nombre)
                {this->nombre=nombre;};
        void setapellido(string apellido)
                {this->apellido=apellido;};
        void setnumerolibreta(unsigned int numerolibreta)
                {this->numerolibreta=numerolibreta;};

        //*Getters*//
        string getnombre(void)
                {return nombre;};
        string getapellido(void)
                {return apellido;};
        unsigned int getnumerolibreta(void)
                {return numerolibreta;};


};

#endif