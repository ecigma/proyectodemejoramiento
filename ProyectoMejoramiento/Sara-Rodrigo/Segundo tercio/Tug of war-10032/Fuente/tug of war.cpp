/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#define max 150
using namespace std;
/*==============================================================================
Variables
==============================================================================*/
int queremos,n,v[max],sum,sum2;
/*==============================================================================
Definición de Metodos
==============================================================================*/

void backtrack(int indice,int llevamos,int p[]);

/*==============================================================================
Metodo principal
==============================================================================*/
int main()
{
   int casos,flag=0;  
   cin >>casos;
      while(casos--){ 
          if(flag>0){
          puts("");
          }
          int num,id=0,aux[max]; cin >>num; sum=0;
           while(num--){
            cin >>v[id]; 
            sum+=v[id];
             id++;
           } 
           n=id; 
           queremos=id/2; 
           sum2=0;
           backtrack(0,0,aux); 
          int var=sum-sum2;  
          flag++;
            if(var<sum2){
              cout <<var<<" "<<sum2<<endl;
            }
            else  cout <<sum2<<" "<<var<<endl;
                         
      }
return 0;
}

/*
Encuentra todas las posibilidades
*/
void backtrack(int indice,int llevamos,int p[])
{
      if(llevamos==queremos){
         int suma=0; //Queremos=ElementosDeseado
         for(int i=0;i<queremos;i++){ //P es el resultado
             suma+=p[i];
         } 
         if((sum-suma)<(sum-sum2)){
            sum2=suma;
         }    
         return;
      }
      for(int i=indice;i<n;i++){ //n=ElementosTotal
          p[llevamos]=v[i];
          backtrack(i+1,llevamos+1,p);
      }
}
