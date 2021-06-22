#include <stdio.h>

int main(void){
	
	int i=0, j=0, k=0;
	float matriz[2][5][2], mediaAlunoT1[5], mediaAlunoT2[5];
	float somanotaT1=0, somanotaT2=0, somanotaaluno, mediaT1, mediaT2;
	
	for(i=0; i<2; i++){
		for(j=0; j<5; j++){
			for(k=0; k<2; k++){
				scanf("%f",&matriz[i][j][k]);
			}
		}
	}
	
	for(i=0; i<2; i++){
		for(j=0; j<5; j++){
			for(k=0; k<2; k++){
				if(i == 0){
					somanotaaluno = matriz[0][j][0] + matriz[0][j][1];
					mediaAlunoT1[j] = somanotaaluno/2;
					somanotaaluno = 0;
				}
				if(i == 1){
					somanotaaluno = matriz[1][j][0] + matriz[1][j][1];
					mediaAlunoT2[j] = somanotaaluno/2;
					somanotaaluno = 0;
				}
			}
		}
	}
	
	for(i=0;i<5;i++){
		somanotaT1 += mediaAlunoT1[i]; 
		somanotaT2 += mediaAlunoT2[i];
	}
	
	mediaT1 = somanotaT1/5;
	mediaT2 = somanotaT2/5;
	
	printf("Turma 1\n");
	for(i=0;i<5;i++){
		printf("%.2f\n", mediaAlunoT1[i]);
	}
	printf("Turma 2\n");
	for(i=0;i<5;i++){
		printf("%.2f\n", mediaAlunoT2[i]);
	}
	printf("Media das turmas\n%.2f\n%.2f", mediaT1, mediaT2);
}











