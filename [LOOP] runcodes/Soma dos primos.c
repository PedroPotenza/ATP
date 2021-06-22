#include <stdio.h>

int main(void){
	
	int m, n, soma=0;
	int i=0, j=0, div=0; //contador
	
	scanf("%d %d", &m, &n);
	
	for(i=m; i<=n; i++){ //crio o intervalo de m até n 
		
		div=0;
		
		for(j=1; j<=i; j++){
			if(i%j == 0)
				div++;
		}
		
		
		if(div == 2) 
			soma = soma + i;
	}
	
	printf("%d",soma);
}
