/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include "Cubo.h"
#include <iostream>
#include<math.h>
#include <string.h>
using namespace std;
/*==============================================================================
Metodos
==============================================================================*/ 
/*==============================================================================
Creador del nodo 
==============================================================================*/ 
Cubo::Cubo(int dato[6],int numero){
       string Caras[6] ={"front","back","left","right","top","botton"};
       for(int i= 0;i<6;i++){
            cara[i] = dato[i];   
            nombreCara[i] = Caras[i]; 
       }
       siguienteNodo=NULL;
       top=0;
       numCubo=numero;
}
/*==============================================================================
Creador del nodo 
==============================================================================*/ 
Cubo* Cubo::getSiguienteNodo(){
      return siguienteNodo;
}
/*==============================================================================
retorna el color de arriba de un cubo 
==============================================================================*/ 
int Cubo::getTop(){
      return top;
}
/*==============================================================================
retorna el numero del cubo
==============================================================================*/ 
int Cubo::getnumCubo(){
      return numCubo;
}
/*==============================================================================
retorna el color de arriba de un cubo 
==============================================================================*/ 
int Cubo::getBotton(){
      return botton;
}
/*==============================================================================
Enviar siguiente nodo
==============================================================================*/ 
void Cubo::setSiguienteNodo(Cubo* n){
      siguienteNodo=n;
}
/*==============================================================================
Devuelve el color de una cara del cubo
==============================================================================*/ 
int Cubo::getCara(int x){
      return cara[x];
}

/*==============================================================================
Determina si un color enviado existe en el cubo
==============================================================================*/ 
bool Cubo::ExisteColor(int x){
   bool existe=false;
   for(int i=0; i<6 && existe==false; i++){
           //cout<<cara[i]<<endl;//////////////////
           
      if(cara[i]==x){
        existe=true;  
     }
   }
   return existe;                
}

/*==============================================================================
Determina el numero de existencias de un color
==============================================================================*/ 
int Cubo::numExisteColor(int x){
   int existe=0;
   for(int i=0; i<6; i++){   
      if(cara[i]==x){
        existe++;  
     }
   }
   return existe;                
}
/*==============================================================================
Determina si un color enviado existe en el cubo
==============================================================================*/ 
string Cubo::opuesto(int x,int y){
   string opuesto="";
    int z=0;
   for(int i=0; i<6; i++){
      if(cara[i]==x && z!=(y)){
        top=x;
        if(i%2==0){                    
          opuesto=nombreCara[i+1];
        }else opuesto=nombreCara[i-1];  
     }
   }
   return opuesto;                
}
/*==============================================================================
retorna el color opuesto de un color
==============================================================================*/ 
int Cubo::Coloropuesto(int x,int y){
   int opuesto=0;
   int z=0;
   for(int i=0; i<6; i++){
      if(cara[i]==x && z!=(y)){
        top=x;
        z++;
        if(i%2==0){                    
          opuesto=cara[i+1];
        }else opuesto=cara[i-1];  
     }
   }
   return opuesto;                
}

/*==============================================================================
Determina si un color enviado existe en el cubo
==============================================================================*/ 
bool Cubo::Conectado(){
   bool conectado=false;
   if(siguienteNodo!=NULL){
      conectado=true;
      }                     
   return conectado;                
}
/*==============================================================================
Retorna un color especifico de un cubo
==============================================================================*/ 
int Cubo::Color(int x){
   return cara[x];                
}

/*==============================================================================
Retorna el cubo el color de la cara inferior de un cubo
==============================================================================*/ 
string Cubo::respOriginal(int x, int y){
   string opuesto="";
   int z=0;
   for(int i=0; i<6; i++){
      if(cara[i]==x && z!=(y)){                     
          opuesto=nombreCara[i];
          if(i%2==0){                    
             top=cara[i+1];
          }else top=cara[i-1];  
      }
   }
   return opuesto;                
}

/*==============================================================================
Retorna el numero de opuestos que tiene un color en un cubo
==============================================================================*/
int Cubo::NumColoropuesto(int x){
   int opuesto=0;
   for(int i=0; i<6; i++){
      if(cara[i]==x){
       opuesto++;  
     }
   }
   return opuesto;                
}  
