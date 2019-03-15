#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int MORTO = 0;

void imprimir_vetor( int vet[], int qtd, int esc){
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
		   	if(i == esc)printf("E");
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

int achar_vivo_esq(int vet[],int total,int matador){
	int pos = 0;
	
	if((matador - 1) < 0){
			pos = total - 1;
		} else{
			pos = total - 1;
		}

	while(vet[pos] == 0){
		if((pos - 1)== -1){
			pos = total - 1;
		} else{
			pos--;
		}
	}
	
	return pos;
}


int main(){
	int qtd = 0;
	int esc = 0;
	int fase = 0;
	
	scanf("%d", &qtd);
	scanf("%d", &esc);
	scanf("%d", &fase);
	
	esc = esc - 1;
	
	int vet[qtd];
	int i;
	int aux = fase;
	for(i = 0; i < qtd; i++){
		if(aux == 1){
			vet[i] = i+1;
			aux = -1;
		}
		else
		{
			vet[i] = (i + 1) * -1;
			aux = 1;
		}
		
	}
	
	
	
	int vivos = qtd;
	int atual = esc;
	
	/*for(j = 0; j < qtd - 1; j++){
		int vai_morrer = achar_vivo(vet, qtd, esc);
		vet[vai_morrer] = MORTO;
		esc = achar_vivo(vet, qtd, vai_morrer);
		imprimir_vetor(vet, qtd, esc);
	}*/
		
		while(vivos > 1){
			imprimir_vetor(vet, qtd, esc);
			if(vet[atual] > 0){
				vet[achar_vivo(vet, qtd, atual)] = 0;
				int prox = atual, i;
				for(i = 0; i < abs(vet[atual]); i++){
					prox = achar_vivo(vet, qtd, prox);
				}
				atual = prox;
				vivos--;
			} else{
				vet[achar_vivo_esq(vet, qtd, atual)] = 0;
				int prox = atual, i;
				for(i = 0; i < abs(vet[atual]); i++){
					prox = achar_vivo_esq(vet, qtd, prox);
				}
				atual = prox;
				vivos--;
				
			}
		}
	return 0;
}