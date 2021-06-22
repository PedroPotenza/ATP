#include <stdio.h>

int main(void)
{
	int cod, quant;
	float v, r, d;
	
	scanf("%d %d", &cod, &quant);
	
	if(cod>= 1 && cod <=10)
	{
		v=10.00;
	}
	else{
	
	if(cod>= 11 && cod <=20)
	{
		v=15.00;
	}
	else {
	
	if(cod>=21 && cod <=30)
	{
		v=20.00;
	}
	else{
	
	if(cod>=31 && cod <=40)
	{
		v=30.00;
	}}}}
	
	r = v*quant;
	
	if(r<=249.99){
		d=r*0.05;
	}
	else{
	
	if(r>=250.00 && r<=499.99){
		d=r*0.1;
	}
	else{
	
	if(r>=500){
		d=r*0.15;
	}
  }
}
	printf("%.2f %.2f %.2f %.2f", v, r,  d, r-d);
	
}
