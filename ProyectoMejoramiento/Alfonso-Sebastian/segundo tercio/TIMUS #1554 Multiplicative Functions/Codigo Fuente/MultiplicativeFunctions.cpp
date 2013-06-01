#include <stdio.h>
#include <stdlib.h>
#define largo long long
#define MAX 10000
/* Objetivo: Trasladar un elemento que pertenece al conjunto de los numeros
             enteros al conjunto Z/nZ n:=2007
*/
largo toZ2007(largo x){
       largo zx=x;
      if(x>=0){
                zx= x%2007;
      }else{
                if(x%2007!=0){
                               zx= 2007+ x%2007;
                }else{
                      zx= x%2007;
                      }
      }
      return zx;
      }
/* Objetivo: Evaluar la funcion G bajo la especificacion del documento Multiplicative Functions
             Referencia: Seccion 3.2 estrategia de solucion funcion G(n)
*/
largo evaluateG(largo n, largo* g,bool* rango,largo* f ){
     n--;
     if(!rango[n]){
          if(n+1==1){
                   g[n]=toZ2007(1/f[n]);
                   rango[n]=true;

          }else if((n+1)>1){
                    g[n]=0;
                    for(largo i=2;i<=(n+1);i++){
                              if((n+1)%i==0){
                                         g[n]+=f[i-1]*evaluateG(((n+1)/i),g,rango,f);
                                         }
                              }
                  g[n]=toZ2007(((-1*g[n])/f[0]));
                  rango[n]=true;
                }
     }

     return g[n];
     }

int main(){
    long n;
/*  Nota: Remover estas dos instrucciones para realizar pruebas en el juez virtual,
          estas dos instrucciones permiten realizar pruebas con entradas de tamaño
          considerable alojadas en un archivo de texto.
*/
 // Formato de lectura
    while(scanf("%d",&n)!=EOF){
       largo f[MAX];
       largo g[MAX];
       bool rango[MAX];
       for(int i=0;i<n;i++){
               scanf("%lld",&f[i]);
               rango[i]=false;
               }
//  Formato de Escritura
            for(int i=0;i<n;i++){
               evaluateG((i+1),g,rango,f);
               printf("%lld ",g[i]);
               }
      printf("\n");
    }
 }
