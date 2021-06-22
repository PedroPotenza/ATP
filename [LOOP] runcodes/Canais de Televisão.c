#include <stdio.h>

int main(void){
	
	int canal, pessoas, i=0;
	int c4=0, c5=0, c7=0, c12=0;
	float p4, p5, p7, p12;
	
	
	
	do
	{
		scanf("%d", &canal);
			if(canal==0)
			break;
		scanf("%d", &pessoas);
		
		i++;
		
		switch(canal)
		{
			case 4:
				c4++;
				break;
				
			case 5:
				c5++;
				break;
			
			case 7:
				c7++;
				break;
				
			case 12:
				c12++;
				break;	
		}
		
	}while(1);
	
	p4 = c4/(i*0.01);
	p5 = c5/(i*0.01);
	p7 = c7/(i*0.01);
	p12 = c12/(i*0.01);
	
	printf("%f%% %f%% %f%% %f%%", p4, p5, p7, p12);	
}
