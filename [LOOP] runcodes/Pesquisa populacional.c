#include <stdio.h>

int main(void){
	
	float sal, fi, somasal=0, somafi=0, maxsal=0, porcen;
	int p=0, i=0;
	
	do
	{
		
		scanf("%f", &sal);
		fflush(stdin);
		
		if(sal <0)
		{
			break;
		}	else
		
		i++;
		
		scanf("%f", &fi);
		fflush(stdin);
		
		if(sal >= maxsal)
		{
			maxsal = sal;
		}
		
		if(sal <= 150){
			p++;
		}
		
		somasal = somasal + sal;
		somafi = somafi + fi;
				
	}while(sal > 0);
	
	porcen = p/(i*0.01);
	
	printf("%f %f %f %f%%", somasal/i , somafi/i, maxsal, porcen);
}

