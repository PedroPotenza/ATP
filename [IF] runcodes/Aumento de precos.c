#include <stdio.h>

int main(void)
{
	float p, a;
	int c;
	char s;
	
	scanf("%f %d %c", &p, &c, &s);
	
	if(p<=25.00){
		if(c==1){
			a=p*0.05;
			if(a<=0.99 && s=='R'){
				a=1;
				printf("%.2f %.2f", a, p+a);
			}
			else{
				if(a<=0.99 && s=='N'){
				a=2;
				printf("%.2f %.2f", a, p+a);
				}
				else{
					printf("%.2f %.2f", a, p+a);
				}
			}
		}else{
			if(c==2){
				a=p*0.08;
				if(a<=0.99 && s=='R'){
				a=1;
				printf("%.2f %.2f", a, p+a);
			}
			else{
				if(a<=0.99 && s=='N'){
				a=2;
				printf("%.2f %.2f", a, p+a);
				}
				else{
					printf("%.2f %.2f--", a, p+a);
					}
				}
			}else{
				if(c==3){
					a=p*0.1;
					if(a<=0.99 && s=='R'){
					a=1;
					printf("%.2f %.2f", a, p+a);
					}
					else{
					if(a<=0.99 && s=='N'){
						a=2;
						printf("%.2f %.2f", a, p+a);
					}
					else{
						printf("%.2f %.2f", a, p+a);
						}
					}
				}
			}
		}
	}else{
		if(p>25.00){
			if(c==1){
				a=p*0.12;
				if(a>=100 && s=='R'){
					a=10;
					printf("%.2f %.2f", a, p+a);
				}
				else{
					if(a>=100 && s=='N'){
						a=20;
						printf("%.2f %.2f", a, p+a);
					}
					else{
						printf("%.2f %.2f", a, p+a);
					}
				}
				
			}else{
				if(c==2){
					a=p*0.15;
					if(a>=100 && s=='R'){
					a=10;
					printf("%.2f %.2f", a, p+a);
					}
					else{
						if(a>=100 && s=='N'){
							a=20;
							printf("%.2f %.2f", a, p+a);
						}
						else{
							printf("%.2f %.2f", a, p+a);
						}
					}
				}else{
					if(c==3){
						a=p*0.18;
						if(a>=100 && s=='R'){
							a=10;
							printf("%.2f %.2f", a, p+a);
						}
						else{
							if(a>=100 && s=='N'){
								a=20;
								printf("%.2f %.2f", a, p+a);
							}
							else{
								printf("%.2f %.2f", a, p+a);
							}
						}
					}
				}
			}
		}
	}
}
