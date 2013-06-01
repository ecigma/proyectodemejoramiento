/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <iostream>    
#include <list>
#include "Cubo.h"
#include "ListaCubos.h"
#include <string.h>
#include <sstream>
using namespace std;

/*==============================================================================
Variables
==============================================================================*/
ListaCubos* lista=new ListaCubos(); 
int pos=-1;
int colores[101][501];
string resultado[501];
/*==============================================================================
Metodos
==============================================================================*/ 
void llenarLista(int i);
void reiniciarLista();
void reducirLista();
int crearTorre();
void matrizColores();
int ejecucion1(Cubo* primerCubo,Cubo* segundoCubo,Cubo* tercerCubo);
int ejecucion2(int torre,Cubo* primerCubo,Cubo* segundoCubo,Cubo* tercerCubo);
int demeColores(int cuboA, int cuboB, int numColor);
int numeroColores(int cuboA, int cuboB);
/*==============================================================================
Metodo principal
==============================================================================*/ 
int main(){
    int numCubos;
    int t=0;
    int numtorre=0;
    memset(colores, 0, sizeof(colores)); 
    while((cin>>numCubos,numCubos)){
       t++;                            
       for(int i=0; i<numCubos; i++){                             
          llenarLista(i+1);                         
       }
       reducirLista();
       matrizColores();
       cout<<"Case #"<<t<<endl;
       numtorre=crearTorre();
       cout<<numtorre<<endl;
       for(int i=0; i<=numtorre; i++){
           cout<<resultado[i]<<endl;
       }
       reiniciarLista();
    }
    
  return 0;
}
/*==============================================================================
Crea y adiciona los cubos en una lista
==============================================================================*/ 
void llenarLista(int i){
   int c[6];  
   cin>>c[0]>>c[1]>>c[2]>>c[3]>>c[4]>>c[5];
   Cubo* nodo=new Cubo(c,i);
   lista->addCubo(nodo);  
}
/*==============================================================================
Elimina todos los nodos de la lista
==============================================================================*/ 
void reiniciarLista(){ 
   lista = 0;
   lista=new ListaCubos(); 
   memset(colores, 0, sizeof(colores));       
}
/*==============================================================================
Crea la torre mas larca posible
==============================================================================*/ 
int crearTorre(){
    int torre;
    Cubo* primerCubo;
    Cubo* segundoCubo;
    Cubo* tercerCubo;    
    torre=ejecucion1(primerCubo,segundoCubo,tercerCubo);
    if(torre<lista->size()){
       torre=ejecucion2(torre,primerCubo,segundoCubo,tercerCubo);
    }                     
}
/*==============================================================================
Crea la torre mas larca posible
==============================================================================*/  
int ejecucion1(Cubo* primerCubo,Cubo* segundoCubo,Cubo* tercerCubo){
    int bandera1=0,bandera2=0;
    int impresion=0;
    stringstream out;
    string s;
    stringstream out1;
    string m;
    stringstream out2;
    string n;
          primerCubo=lista->getCubo(1);
          if(2<=lista->size()){                     
             bandera1++;                                    
             segundoCubo=lista->getCubo(2);
          }
          if(3<=lista->size()){
             bandera2++;                                    
             tercerCubo=lista->getCubo(3);
          }
          if(bandera1>0 && bandera2>0){   
             int cont=0;           
             for(int k=1; k<=numeroColores(1,2) && cont==0;k++){           
                 int color=demeColores(1, 2, k);
                 for(int j=1; j<=segundoCubo->NumColoropuesto(color) && cont==0; j++){
                     if(tercerCubo->ExisteColor(segundoCubo->Coloropuesto(color,j))){
                        out << primerCubo->getnumCubo();
                        s = out.str();                                                             
                        cont++;                                                           
                        resultado[impresion]=s+" "+primerCubo->opuesto(color,1); 
                        impresion++;
                        out1 << segundoCubo->getnumCubo();
                        m = out1.str();
                        resultado[impresion]=m+" "+segundoCubo->respOriginal(color,j); 
                        impresion++;
                        out2 << tercerCubo->getnumCubo();
                        n = out2.str();
                        resultado[impresion]=n+" "+tercerCubo->respOriginal(segundoCubo->Coloropuesto(color,1),1); 
                        impresion++;
                     }
                 }
             }
          }
          if(bandera1>0 && bandera2==0){
             int color=demeColores(1, 2, 1); 
             out <<primerCubo->getnumCubo();
             s = out.str();
             resultado[impresion]=s+" "+primerCubo->opuesto(color,1);
             impresion++;
             out1 <<segundoCubo->getnumCubo();
             m = out1.str();
             resultado[impresion]=m+" "+segundoCubo->respOriginal(color,1);
             impresion++;
          }          
    return impresion;
}                                            


/*==============================================================================
Elimina los cubos que no seran indispensables en la torre mas larga
==============================================================================*/  
void reducirLista(){
    int ejecucion=0; 
    for(int i=1 ; i<=lista->size();i++){ 
        ejecucion++;
        if(i!=lista->size()){
           if(lista->ExisteRelacion(lista->getCubo(i),lista->getCubo(i+1))==false && ejecucion==1){
              lista->eliminarNodo(i);
              i--;
              ejecucion=0;   
           }
        }
        if(i!=lista->size()){
           if(lista->ExisteRelacion(lista->getCubo(i),lista->getCubo(i+1))==false && ejecucion!=1 ){
              lista->eliminarNodo(i+1); 
              i--;
              }
        }
    }                                                                                                                    
}
/*==============================================================================
Llena la matriz de conexiones entre los colorees y los cubos
==============================================================================*/  
void matrizColores(){
     Cubo* auxCubo;
    for(int i=1 ; i<=lista->size(); i++){
        auxCubo=lista->getCubo(i);  
        for(int j=0 ;j<6; j++){
            colores[auxCubo->Color(j)][i]=1;
        }
    }                                                                                                                 
}
/*==============================================================================
Retorna un color especifico que existe entre el cubo A y B 
==============================================================================*/  
int demeColores(int cuboA, int cuboB, int numColor){
    int cont=0;
    int color=0;
    for(int i=1 ; i<=101 && cont!=numColor; i++){    
       if(colores[i][cuboA]==1 && colores[i][cuboB]==1){
         color=i;
         cont++;                       
       }   
    }
    return color;                                                                                                              
}

/*==============================================================================
Retorna el numero de colores entre el cubo A y B 
==============================================================================*/  
int numeroColores(int cuboA, int cuboB){
   int cont=0;
    int color=0;
    for(int i=1 ; i<=101; i++){    
       if(colores[i][cuboA]==1 && colores[i][cuboB]==1){
         cont++;                       
       }   
    }
    return cont;                                                                                                           
} 
/*==============================================================================
Crea la torre mas larca posible
==============================================================================*/      
int ejecucion2(int torre,Cubo* primerCubo,Cubo* segundoCubo,Cubo* tercerCubo){
   int cont=0;
   while(torre!=lista->size()){
        primerCubo=lista->getCubo(torre);
        int color=primerCubo->getTop();
           segundoCubo=lista->getCubo(torre+1);
           if(segundoCubo->ExisteColor(color)){
              stringstream out;
              string s;
              out << segundoCubo->getnumCubo();
              s = out.str();                                 
              resultado[torre]=s+" "+segundoCubo->respOriginal(color,1); 
              torre++;
           }
           else{
             lista->eliminarNodo(torre+1);
           }                                
   } 
   return torre;                        
}
 
