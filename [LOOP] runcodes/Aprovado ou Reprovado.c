#include <stdio.h>

int main(void){
	 
	 int numalu, RA, i=0, rep=0, repf=0, freq;
	 float n1, n2, n3, media, mediamax=0, mediamin=11, porcenrepf;
	 
	 
	 scanf("%d", &numalu);
	 
	 for (i=0; i<numalu; i++){
	 	
		scanf("%d", &RA);
		scanf("%f", &n1); 	
		scanf("%f", &n2); 
		scanf("%f", &n3); 
		scanf("%d", &freq);
	 	
	 	media = (n1+n2+n3)/3;
	 	
	 	if(media >= mediamax)
	 		mediamax = media;
			 
		if(media <= mediamin)
			mediamin = media;	  
		 
		if(freq<40 || media<6 ){
			rep++;
			
			if(freq<40)
				repf++;
				
	 		printf("%d %f %s\n", RA, media ,"Reprovado");
	 		
		 }	else 
		 printf("%d %f %s\n", RA, media ,"Aprovado");
	 		
	 }
	 
	 porcenrepf= repf/(i*0.01);
	 
	 printf("%f %f %d %f%%", mediamax, mediamin, rep, porcenrepf);	 
		 
}
