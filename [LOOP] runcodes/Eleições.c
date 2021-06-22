#include <stdio.h>

int main(void){
	
	int voto, i=0, v1=0, v2=0, v3=0, v4=0, v5=0, v6=0;
	float p5, p6;
	
	do{
		
		scanf("%d", &voto);
		if(voto<=0){
			break;
		}
		i++;
		
		if(voto==1){
			v1++;
		}
		
		if(voto==2){
			v2++;
		}
		
		if(voto==3){
			v3++;
		}
		
		if(voto==4){
			v4++;
		}
		
		if(voto==5){
			v5++;
		}
		
		if(voto==6){
			v6++;
		}
		
	}while(1);
	
	p5 = v5/(i*0.01);
	p6 = v6/(i*0.01);
	
	printf("%d %d %d %d %d %d\n", v1, v2, v3, v4, v5, v6);
	printf("%f%% %f%%", p5, p6);
	
}
