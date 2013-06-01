/*==============================================================================
================================================================================
Autores: Sara Chica--Rodrigo Gualtero      
================================================================================
================================================================================
Bibliotecas
==============================================================================*/
#include <cstdio>
#include <iostream>
#include <map>
#include <sstream>
using namespace std;


/*==============================================================================
Metodo principal
==============================================================================*/
int main(){
string a,b,c,d;
map <string,string>diccionario;
while(getline(cin,c),c.size()){ 
      stringstream palabras;
      palabras<<c;
      palabras>>a>>b;
      diccionario[b]=a;
}
while(cin>>d){
    cout<<(diccionario.count(d) ? diccionario[d] : "eh")<<endl;
}

return 0;
}
