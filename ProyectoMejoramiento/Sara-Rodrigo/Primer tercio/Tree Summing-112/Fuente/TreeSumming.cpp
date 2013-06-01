/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include<iostream>  
#include<cstdlib>  
#include<stack>  
using namespace std;  

/*==============================================================================
Variables
==============================================================================*/  
struct Node  
{  
    int value;  
    Node *left,*right;  
};  
  
int I;  

/*==============================================================================
Definición de Metodos
==============================================================================*/
bool suma(Node *n,int sum);

/*==============================================================================
Metodo principal
==============================================================================*/
int main(){   
  int num;  
  char c;  
  stack<Node *> s_Node;  
  while(cin>>I){  
     while(!s_Node.empty()) s_Node.pop();  
     int left_num=0,right_num=0;
     do{  
        cin>>c;  
        if(c=='('){  
            if(!(cin>>num)){  
                  cin.clear();  
                  cin>>c;  
                  Node *tmp=NULL;  
                  s_Node.push(tmp);  
            }
            else{  
                  left_num++;  
                  Node *tmp=(Node *)malloc(sizeof(Node));  
                  tmp->value=num;  
                  tmp->left=tmp->right=NULL;  
                  s_Node.push(tmp);  
            }  
        }  
        else{  
            right_num++;  
            Node *tmp,*left,*right;  
            right=s_Node.top();  
            s_Node.pop();  
            left=s_Node.top();  
            s_Node.pop();  
            tmp=s_Node.top();  
            tmp->left=left;  
            tmp->right=right;  
       }  
    }
    while(left_num>right_num);  
      Node *cabeza=s_Node.top();  
      s_Node.pop();  
      if(cabeza){  
          if(suma(cabeza,0))  
              cout<<"yes"<<endl;  
          else  
              cout<<"no"<<endl;  
      }  
      else  
          cout<<"no"<<endl;  
  }  
  return 0;  
} 

/*==============================================================================
Suma
Determina si el numero correspondiente a la suma de las ramas del arbol es el 
ingresado por el usuario
==============================================================================*/
bool suma(Node *n,int sum)  
{  
    bool rta=false;
    sum+=n->value;  
    if(!n->left&&!n->right&&sum==I || n->left&&suma(n->left,sum) || n->right&&suma(n->right,sum)) rta=true;
    return rta;  
}         
 
