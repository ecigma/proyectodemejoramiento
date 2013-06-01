/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Definicion de clase
==============================================================================*/
#ifndef LISTACUBOS_H
#define LISTACUBOS_H
#include "Cubo.h"
#include <string.h>
class ListaCubos{
      
/*==============================================================================
Metodos
==============================================================================*/       
public:
       ListaCubos();
       Cubo* getCubo(int i);
       bool ExisteRelacion(Cubo* aux1,Cubo* aux2);
       void addCubo(Cubo* n);
       void eliminarNodo(int x);
       bool esVacia();
       int size();
       
private:
        Cubo* cubo;
        int numElementos;
};

#endif /*CUBO_H*/
