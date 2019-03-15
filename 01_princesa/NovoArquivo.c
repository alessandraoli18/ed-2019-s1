#include <stdio.h>
#include <stdbool.h>

const int MORTO = 0;

//acha o proximo elemento vivo a partir de inicio + 1
int achar_vivo(int vet[], int tam, int inicio, int direcao){
	int pos;
    if(direcao == 1){
		pos = (inicio + direcao) % tam;
	 }
    else{
		pos = (inicio + tam -1) % tam;
	}
	while(vet[pos] == MORTO){
	if(direcao == 1)
		pos = (inicio + direcao) % tam;
	else 
		pos = (inicio + tam -1) % tam;
	}
		
    return pos;
}

void mostrar_vetor(int vet[], int tam, int e){
    printf("[");
    int i;
    for(i = 0; i < tam; i++){
        if(vet[i] != MORTO)
            printf(" %d", vet[i]);
        if(i == e)
            printf(">");
        
    }
    printf(" ]\n");
}

int main(){
    int tam = 0;
    scanf("%d", &tam);
    int vet[tam];
    
     //o escolhido
    int esc = 0;
    scanf("%d", &esc);
    esc = esc - 1;
    
	int fase = 0;
	scanf("%d", &fase);    
    
    int i;
    for(i = 0; i < tam; i++){
        vet[i] = (i + 1) * fase;
    	fase = fase * -1;	
	}
    
    int qtd = tam - 1;
    
    while(qtd--){
    	mostrar_vetor(vet, tam, esc);
        int dir = vet[esc] > 0 ? 1 : -1;
        int saltos = vet[esc] > 0 ? vet[esc] : -vet[esc];
        int morreu = achar_vivo(vet, tam, esc, dir);
        vet[morreu] = 0;
        int pos = morreu;
        int i;
        for(i = 0; i < saltos; i++){
			pos = achar_vivo(vet, tam, pos, dir);	
		}
		esc = pos;
        
    }
}