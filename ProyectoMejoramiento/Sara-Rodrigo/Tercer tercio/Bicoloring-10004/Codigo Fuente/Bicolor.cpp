/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <iostream>    
using namespace std;
/*==============================================================================
Variables
==============================================================================*/
 int matriz[205][205]; 
 
 struct nodo {
    string Color;
    int nodoOriginal;
} vec[205];
/*==============================================================================
Metodos
==============================================================================*/ 
bool bicoloreable(int existe,int numNodos);
int findNodo(int numNodos);
void reiniciar();
/*==============================================================================
Metodo principal
==============================================================================*/ 

int main(){
  int numNodos,NumConexiones,nodo1,nodo2; 
  while((cin>>numNodos,numNodos)){ 
       bool Bicoloreable=true;                                                                                                              
       reiniciar();
       cin>>NumConexiones;             
       while(NumConexiones--){
          cin>>nodo1>>nodo2;
          matriz[nodo1][nodo2]=1;
       }
          vec [0].nodoOriginal = 1;
          vec [0].Color= "black";
          int existe=findNodo(numNodos);
          Bicoloreable=bicoloreable(existe,numNodos);
          if(Bicoloreable){                                             
             cout << "BICOLORABLE." << endl;
          }else{
              cout << "NOT BICOLORABLE." << endl;
          }
  }  
  return 0;
}


/*
Retorna la posicion de un nodo si ya ha sido creado
*/
int findNodo(int numNodos){
   int encontro=-1;
   for(int i=0; i< numNodos && encontro==-1; i++){
       if(vec[i].Color=="black"){
          encontro=i;
       }                                 
   }
   return encontro;
}



/*
reinicia el arreglo del los nodos y la matriz a su valor por defecto
*/
void reiniciar(){
   for(int i=0; i<205; i++){
       vec[i].nodoOriginal=0;
       vec[i].Color="red";
   }
   for(int j=0; j<205; j++){
      for(int k=0; k<205; k++){
         matriz[j][k]=0;
      }
   }          
}

/*
determina si el grafo ingresado  es bicoloreable
*/
bool bicoloreable(int existe,int numNodos){
   bool bicoloreable=true;  
   while ( existe != -1 ) {
         if ( vec[existe].nodoOriginal == 1 ) {
            for ( int i = 0; i < numNodos && bicoloreable ==true ; i++ ) {
                if ( matriz[existe] [i] == 1 ) {
                    if ( vec[i].nodoOriginal == 1 )
                       bicoloreable = false;
                    else
                        vec[i].nodoOriginal = 2; 
                        if (vec[i].Color == "red" )
                        vec[i].Color = "black";
                    }
                }
            }
            else {
                for ( int i = 0; i < numNodos && bicoloreable ==true; i++ ) {
                    if ( matriz[existe] [i] == 1 ) {
                        if (vec[i].nodoOriginal == 2 )
                            bicoloreable = false;
                        else
                            vec[i].nodoOriginal = 1;
                           if (vec[i].Color == "red" )
                              vec[i].Color = "black";
                    }
                }
            }
            vec[existe].Color = "blue";
            existe = findNodo(numNodos);
   } 
   return bicoloreable;  
}
