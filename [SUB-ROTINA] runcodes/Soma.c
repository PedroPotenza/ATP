#include <stdio.h>

/////////PROT�TIPOS//////////
int soma(int n);

////////MAIN/////////////////
int main(void)
{
	int x;
	
	scanf("%d",&x);
	printf("%d", soma(x));
	
	return 0;
}

///////FUN��ES//////////////
int soma(int n){
	
	int i, result=0;
	
	for(i=1; i<=n; i++)
		result +=  i;
		
	return result;
	
	
}
