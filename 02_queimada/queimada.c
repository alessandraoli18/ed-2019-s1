#include <stdio.h>

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.'; 
const char VOLTA = 'x';

void imprimir_matriz(int nl, int nc, char mat[nl][nc]){
	int l, c;
    for(l = 0; l < nl; l++){
        for(c = 0; c < nc; c++)
            printf("%c", mat[l][c]);
        puts("");
    }
}

int tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    
	if((l < 0) || (l >= nl) || (c < 0) || (c >= nc))
        return 0;
    if(mat[l][c] != TREE)
        return 0;
    mat[l][c] = FIRE;
    int cont = 1;
    imprimir_matriz(nl, nc, mat);
    getchar();
    
    cont = cont + tocar_fogo(nl, nc, mat, l, c + 1);
	cont = cont + tocar_fogo(nl, nc, mat, l, c - 1);
    cont = cont + tocar_fogo(nl, nc, mat, l - 1, c);
	cont = cont + tocar_fogo(nl, nc, mat, l + 1, c);
  		
    mat[l][c] = VOLTA;  
    imprimir_matriz(nl, nc, mat);
    getchar();
    
    return cont;
}

int main(){
    int nl = 0, nc = 0, l = 0, c = 0;
    
    scanf("%d %d %d %d\n", &nl, &nc, &l, &c);
    char mat[nl][nc];
    
    int j, k;
    for(j = 0; j < nl; j++)
        for(k = 0; k < nc; k++)
            scanf(" %c", &mat[j][k]);
        
    int qtd = tocar_fogo(nl, nc, mat, l, c);
    imprimir_matriz(nl, nc, mat);
    printf("Arvores queimadas: %d", qtd);

}