#include <stdio.h>
#include <stdlib.h>


int main(int argc, char* argv[]){
    long m,n;
    long i,j;
    long field=0;
    
    while(scanf("%ld %ld", &m, &n)!=EOF )
    {
      if (!n && !m) {
			return 0;
      }else{
        	if (field > 0) {
				printf("\n");
			}
       }
       field++;
       
      int output[m+2][n+2];
     
      char input [m+2][n+2];
      
      char entrada[n];
     
     for(i=0;i<m+2;i++){
                      for(j=0;j<n+2;j++){
                                     output[i][j]=0;
                                     }   
                         }                  
                    
      for(i=0;i<m ; i++){
                      scanf("%s\n",entrada);
                      for(j=1;j<n+1;j++){
                                    input[i + 1][j] = entrada[j -1];
                                     }
                      }
                     
              for(i=1;i<m+1;i++){
                                 for(j=1;j<n+1;j++){
                                     if(input[i][j]=='*'){
                                                    output[i-1][j-1]++;
				                                   	output[i-1][j]++;
					                                output[i-1][j+1]++;
					                                output[i][j-1]++;
					                                output[i][j+1]++;
					                                output[i+1][j-1]++;
					                                output[i+1][j]++;
                                                    output[i+1][j+1]++;
                                                      }
                                       }
                                     }   
                                           
        printf("Field #%ld:\n",field);
		for (i =1; i < m + 1; i++) {
			for (j = 1; j < n + 1; j++) {
				if (input[i][j] == '*')
                {
					printf("%c",'*');
                }
				else{	
					printf("%d",output[i][j]);
                }
			}
			printf("\n");
		}
                    
    }
    system("pause");
    return 0;
    
    }
