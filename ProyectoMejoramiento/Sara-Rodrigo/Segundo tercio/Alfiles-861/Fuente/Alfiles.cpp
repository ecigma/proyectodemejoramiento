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
using namespace std;
/*==============================================================================
Variables
==============================================================================*/
int n,m,num;
/*==============================================================================
Definición de Metodos
==============================================================================*/

void candidates(int a[],int k,int c[],int *ncandidates);
bool is_a_solution(int a[],int k,int count);
void backtrack( int a[], int k, int count); 

/*==============================================================================
Metodo principal
==============================================================================*/
int main()
{
	int a[1000];
	while(cin>>n>>m)
	{
		if(n==0&&m==0) break;
		num=0;
		backtrack(a,0,0);
		cout<<num<<endl;
	}
	return 0;
}

/*
Encuentra todos los posibles condidatos a solución
*/
void candidates(int a[],int k,int c[],int *ncandidates)
{
	*ncandidates=0;
	int i,j,ans,bns,t,temp;
	ans=k;
	bns=0;
	if(k>n) ans=2*n-k;
  	for(i=0; i<=ans; i++)
	{
		temp=1;
		for(j=1; j<k && i!=0; j++)
		{
			if(k%2!=j%2) continue;
			if(a[j]==0) continue;
			if(j>n) bns=2*n-j;
			else bns=j;
			if(k>n&&j>n)
			{
				t=(abs(j-k)/2);
				if(t+i==a[j])
				temp=0;
			}
			else if(k>n && j<=n)
			{
				t=(abs(2*n-k-j)/2);
				if(2*n-k<j)
				{
					if(i+t==a[j])
					temp=0;
				}
				else
				{
					if(i==t+a[j])
						temp=0;
				}
			}
			else if(k<=n&&j<=n)
			{
					t=(abs(k-j)/2);
					if(t+a[j]==i)
						temp=0;
			}
		}
		if(temp!=0)
		{
			c[*ncandidates]=i;
			*ncandidates=*ncandidates+1;
		}
	}
}

/*
Decide si un candidato a solición es una solucion
*/
bool is_a_solution(int a[],int k,int count)
{
    bool resultado=false;
	if(count==m)
	{
		num++;
	    resultado=true;
	}
	else if(k==2*n-1){
		resultado=true;
    }
	return resultado; 
}

/*
Cuenta todas las posibilidades de solución
*/
void backtrack( int a[], int k, int count)
{
	int c[500],temp;
	int ncandidates;
	int i;
	if(!is_a_solution(a,k,count))
	{
		k++;
		candidates(a,k,c,&ncandidates);
		temp=1;
		for(i=0; i<ncandidates; i++)
		{
			a[k]=c[i];
			if(c[i]!=0&&temp)
			{
				count++;
				temp=0;
			}
			if(count+2*n-1-k>=m)
			backtrack(a,k,count);
		}
	}
}
