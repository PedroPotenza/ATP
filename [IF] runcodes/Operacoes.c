#include <stdio.h>

int main(void)
{
	int n1, n2, op, r;
	
	scanf("%d %d %d", &n1, &n2, &op);
	
	if(op==1){
		r = (n1 + n2)/2;
		printf("%d", r);
	}
	
	else{
		if(op==2){
			
			if(n1 > n2){
				r = n1-n2;
	    		printf("%d", r);
				}
				
			else{
				r = n2-n1;
				printf("%d", r);
				}
		}
										
		else{
		
		if(op==3){
			r = n1*n2;
			printf("%d", r);
			}
			
			else{
			printf("Entrada incorreta");
			}
		}
	}
}
