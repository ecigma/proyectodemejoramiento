#include <iostream>
	#include <cstdio>
	#include <algorithm>
	#include <cstring>
	#include <string>
	#include <cctype>
	#include <stack>
	#include <queue>
	#include <list>
	#include <vector>
	#include <map>
	#include <sstream>
	#include <cmath>
	#include <bitset>
	#include <utility>
	#include <set>
	#include <numeric>

	#define INF_MAX 2147483647
	#define INF_MIN -2147483647
	#define pi acos(-1.0)
	#define N 1000000
	#define LL long long

	#define For(i, a, b) for( int i = (a); i < (b); i++ )
	#define Fors(i, sz) for( size_t i = 0; i < sz.size (); i++ )
	#define Fore(it, x) for(typeof (x.begin()) it = x.begin(); it != x.end (); it++)
	#define Set(a, s) memset(a, s, sizeof (a))
	#define Read(r) freopen(r, "r", stdin)
    #define Write(w) freopen(w, "w", stdout)

	using namespace std;

	vector <int> v;
    void recurrencia(LL n);
	

	int main ()
	{  
        //doblelargo de entrada
	    LL n;

	    while ( cin >> n ) {
            
            //Caso basico
	        if ( n == 0 ){
                printf ("10\n");
                continue;
                }
                
            v.clear ();
            
            //llamado a la recurrencia
	        recurrencia(n);
            
            //ordenar de menor a mayor el vector de digitos y asi lograr el menor entero
	        sort(v.begin (), v.end ());

	        LL producto = 1;
            
            //comprobar que la respuesta existe
            for(int i=0;i<v.size();i++){
                producto*=v[i];
            }
            
            //informar la respuesta
	        if ( producto == n ) {
                for(int i=0;i<v.size();i++){
                    printf ("%d", v [i]);
                }
	            printf ("\n");
	        }
	        else printf ("-1\n");
	    }
	    return 0;
	}
	
	//-------------------------------------------------------
	//Recurrencia
	//-------------------------------------------------------
	
    void recurrencia(LL n)
    	{
    	    if ( n < 10 ){ 
                v.push_back(n); 
                return; 
                }
            
            //Encontrar divisores menores de 9 y mayores o iguales a 2del numero que seran los que conformen los digitos de productoria
    	    for ( int i = 9; i >= 2; i--){
    	        if ( n % i==0){
    	            v.push_back (i);
    	            recurrencia(n/i);
    	            break;
    	        }
    	    }
    	}
