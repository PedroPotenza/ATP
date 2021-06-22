#include <stdio.h>

int main(void){
	
	
	int n, idade, f1=0, f2=0, f3=0, f4=0, f5=0, i=0;
	float porcentagem;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		
		scanf("%d", &idade);
		
		if(idade<= 15)
			f1++;
		
		if(idade>= 16 && idade <=30)
			f2++;
			
		if(idade>=31 && idade <=45)
			f3++;
			
		if(idade>=46 && idade <=60)
			f4++;
			
		if(idade>= 61)
			f5++;
		
	}
	
	porcentagem = (f1+f5)/(n*0.01);
	
	printf("%d %d %d %d %d \n%f%%", f1, f2, f3, f4, f5, porcentagem);
	
	
}
