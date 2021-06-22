#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int idade, somaidades=0;
	int i=0, IdadeSuperiorPesoInferior=0, AlturaSuperior=0, OlhosAzuis=0, RuivasSemAzul=0; //contadores
	float altura, peso, mediaidades=0, MediaOlhosAzul;
	char olhos, cabelo;
	
	for(i=0; i<20; i++){
		
		scanf("%d %f %f %c %c", &idade, &peso, &altura, &olhos, &cabelo);
		
		if((idade>50) && (peso<60))
			IdadeSuperiorPesoInferior++;
			
		if(altura>1.5){
			AlturaSuperior++;
			somaidades += idade;
		}
		
		if(olhos =='A')
			OlhosAzuis++;
			
		if((cabelo =='R') && (olhos!='A'))
			RuivasSemAzul++;
			
	}
	
	mediaidades = (float)somaidades/AlturaSuperior;
	MediaOlhosAzul = OlhosAzuis/(20 * 0.01);
	
	printf("%d %f %f%% %d", IdadeSuperiorPesoInferior, mediaidades, MediaOlhosAzul, RuivasSemAzul);
	return 0;
}


