/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include "ListaCubos.h"
#include "Cubo.h"
#include <iostream>
#include<math.h>
#include <string.h>
using namespace std;
/*==============================================================================
Metodos
==============================================================================*/ 

/*==============================================================================
Creador de la lista de cubos
==============================================================================*/ 
ListaCubos::ListaCubos(){
       cubo=0;
       numElementos=0;     
}
/*==============================================================================
Retorna un cubo especifico de la lista
==============================================================================*/ 
Cubo* ListaCubos::getCubo(int i){       
    Cubo* aux=cubo;
	Cubo* val;
    int ref=0;
    if (cubo==NULL)ref = 1;
    if (ref != 1) {
        for(int x=1;x<i;x++)
            aux=aux->getSiguienteNodo();
        val=aux;
    }
    return val;
}
/*==============================================================================
Enviar siguiente nodo
==============================================================================*/ 
void ListaCubos::addCubo(Cubo* n){
    //cout<<numElementos<<endl;  
    Cubo* nodoaux=NULL;
    nodoaux=cubo;
    if(cubo==NULL){
       cubo=n;
    }else{            
      while(nodoaux->getSiguienteNodo() !=NULL){
         nodoaux=nodoaux->getSiguienteNodo();
      }
      nodoaux->setSiguienteNodo(n);    
    }    
    numElementos++;                 
}
/*==============================================================================
Determina si la lista de cubos esta vacia o no
==============================================================================*/ 
bool ListaCubos::esVacia(){
  bool vacia=false;   
  if(numElementos==0){
     vacia=true;                    
  }
  return vacia;
}
/*==============================================================================
Determina el tamaño de la lista de cubos
==============================================================================*/ 
int ListaCubos::size(){
  return numElementos; 
}
/*==============================================================================
Elimina un nodo de la lista
==============================================================================*/ 
void ListaCubos::eliminarNodo(int x){
    Cubo* siguiente=NULL;
    Cubo* anterior=NULL;
    anterior=cubo;
    if(x==1){
       cubo=getCubo(x+1);       
    }else{          
      anterior=getCubo(x-1);
      siguiente=getCubo(x+1);
      if(siguiente!= NULL) anterior->setSiguienteNodo(siguiente);
      else anterior->setSiguienteNodo(NULL);
    }
    numElementos--;                 
}
/*==============================================================================
Determina si existe una relacion entre dos nodos
==============================================================================*/ 
bool ListaCubos::ExisteRelacion(Cubo* aux1,Cubo* aux2){
    bool relacion=false;
    for(int i= 0; i<6 && relacion==false; i++){
        if(aux2->ExisteColor(aux1->Color(i))){
           relacion=true;
        }  
    }
    return relacion;                  
}
