#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MORTO = 0;

void imprimir_vetor( int vet[], int qtd){
	int i;
	printf("[");
	bool eh_o_primeiro = true;
	for(i = 0; i < qtd; i++){
		if(vet[i] != MORTO){
			if(eh_o_primeiro){
				eh_o_primeiro = false;
			}
				   
			else
				printf(" ");
		
		   	printf("%d", vet[i]);
		}
		
	}
	
	printf("]\n");
}
//achar o prox vivo a partir de matador
int achar_vivo(int vet[],int total,int matador){
	int pos = (matador + 1) % total;

	while(vet[pos] == 0){
		pos = (pos + 1) % total;
	}
	
	return pos;
}

int main(){
	int qtd = 0;
	int esc = 0;
	int fase = 0;
	
	scanf("%d", &qtd);
	scanf("%d", &esc);
	esc = esc - 1;
	
	int vet[qtd];
	int i;
	for(i = 0; i < qtd; i++){
		vet[i] = i+1;
	}
	imprimir_vetor(vet, qtd);
	
	
	int j;
	for(j = 0; j < qtd - 1; j++){
		int vai_morrer = achar_vivo(vet, qtd, esc);
		vet[vai_morrer] = MORTO;
		esc = achar_vivo(vet, qtd, vai_morrer);
		imprimir_vetor(vet, qtd);
	}
	return 0;
}