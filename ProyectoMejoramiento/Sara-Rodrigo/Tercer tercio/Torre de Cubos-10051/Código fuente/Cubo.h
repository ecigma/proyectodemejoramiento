/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Definicion de clase
==============================================================================*/
#ifndef CUBO_H
#define CUBO_H
#include "Cubo.h"
#include <iostream>
#include <string.h>
using namespace std;

class Cubo{
      
/*==============================================================================
Metodos
==============================================================================*/       
public:
       Cubo(int dato[6],int numero);
       Cubo* getSiguienteNodo();
       void setSiguienteNodo(Cubo* n);
       int getCara(int x);
       int getnumCubo();
       int Color(int x);
       int getTop();
       int getBotton();
       int numExisteColor(int x);
       int Coloropuesto(int x,int y);
       int NumColoropuesto(int x);
       string respOriginal(int x,int y);
       string opuesto(int x, int y);
       bool ExisteColor(int x);
       bool Conectado();      
private:
        Cubo* siguienteNodo;
        int cara[6];
        string nombreCara[6];
        int top;
        int botton;
        int numCubo;
};

#endif /*CUBO_H*/
