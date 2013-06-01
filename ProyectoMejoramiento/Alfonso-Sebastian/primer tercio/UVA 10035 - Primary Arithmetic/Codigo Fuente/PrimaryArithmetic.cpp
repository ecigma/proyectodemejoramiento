


#include <stdio.h>
#include <stdlib.h>

 
int main(){
    
    unsigned long long n1; 
    unsigned long long n2;
    
    int carry = 0; 
    int sum = 0; 
    int count = 0; 
     
    while(scanf("%llu %llu",&n1,&n2) && ((n1 > 0) || (n2 > 0))) {
        carry = 0;
        count = 0;
        sum = 0;
     
        while ((n1 > 0) || (n2 > 0)){
            
            sum = carry + (n1 % 10) + (n2 % 10);         
            if (sum >= 10) {
                count++;
                }
            carry = sum / 10;
            n1 /= 10;
            n2 /= 10;
        }
     
        if (count == 0) {
            printf("No carry operation.\n");
        } else if (count == 1) {
            printf("1 carry operation.\n");
        } else {
            printf("%u carry operations.\n",count);
        }
    } 
    return 0;
} 
