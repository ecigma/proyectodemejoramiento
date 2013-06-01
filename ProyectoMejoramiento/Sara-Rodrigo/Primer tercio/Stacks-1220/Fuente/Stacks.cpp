/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stack>
#include <map>
#include <string>
 
using namespace std;
/*==============================================================================
Variables
==============================================================================*/
struct pila{
       stack <int> stack;
       int num;
};
map<int, pila> stacks;

/*==============================================================================
Metodo principal
==============================================================================*/
int main (){
    int n;
    string accion;
    int npila;
    int valor;
    cin>>n;
    while(n){
         cin>>accion>>npila;
         pila p;
         if(accion=="PUSH"){
               cin>>valor;
               if(stacks.find(npila)==stacks.end()){
                     p.stack.push(valor);
                     p.num=npila;
               }
               else
                    p=stacks[npila];
               p.stack.push(valor);
         }
         else if(accion=="POP"){
              p= stacks[npila];
              cout<<p.stack.top()<<endl;
              p.stack.pop();
         }
         stacks[npila]= p;
         n--;
    }
    getchar();
    getchar();
    return 0;
}
