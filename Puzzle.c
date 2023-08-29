//Feito por Jeremias Fenias Jorge e Laudo de Sousa David
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Tamanho do puzzle
#define N 3
// Função para verificar se um estado é o objetivo
int teste_objeto(int estado[][N], int objetivo[][N]) {
	int i,j;
    for (i = 0; i < N; i++) {
        for ( j = 0; j < N; j++) {
            if (estado[i][j] != objetivo[i][j]) {
                return 0; // Não é o objetivo
            }
        }
    }
    return 1; // É o objetivo
}
// Função para encontrar a posição do espaço vazio
int localizarZeroLinha(int estado[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(estado[i][j]==0){
				printf("%d\n",i);
				break; 
			}
		}
		return i;
	}
}
int localizarZeroColuna(int estado[N][N]){
	int i,j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(estado[i][j]==0){
				printf("%d\n",j);
				break;
			}
		}
	}
	return j;
}
// Função para troca
void trocacima(){
	
}
void trocabaixo(){
	
}
void trocaesquerda(){
	
}
void trocadireita(){
	
}
// Função para gerar os estados subsequentes com base no estado atual
void modelo_transicao(int estado[N][N], int linha, int coluna) {
	if (linha>=0 && coluna>=0 && linha<N && coluna<N){
		if(linha >= 0 && linha<N){
			trocabaixo();
			if(coluna >= 0 && coluna < N){
				trocadireita();
			}else if(coluna > 0 && coluna <= N){
				trocaesquerda();
			}
		}else if(linha > 0 && linha<=N){
			trocacima();
			if(coluna >= 0 && coluna < N){
				trocadireita();
			}else if(coluna > 0 && coluna <= N){
				trocaesquerda();
		}
	}else{
		system("cls");
		printf("algo de errado nao esta certo");
	}
}
}
/*
void modelo_transicaoo(int estado[][N], int novos_estados[][N][N], int *num_estados) {
    // Implemente a lógica para gerar os novos estados
    // Atualize o valor de num_estados
}
*/
// Função para imprimir um estado do puzzle
void imprimir(int estado[][N]) {
	int i,j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%2d ", estado[i][j]);
        }
        printf("\n");
	}
    printf("\n");
}

int main() {
    int estado_inicial[N][N] = {
        {1, 2, 3},
        {6, 5, 4},
        {0, 7, 8}  // Usamos 0 para representar o espaço vazio
    };

    int objetivo[N][N] = {
        {1, 2, 3},
        {6, 5, 4},
        {7, 8, 0}
    };

//    int num_estados = 0;
	printf("Estado Inicial\n");
//    imprimir(estado_inicial);
	int linha = localizarZeroLinha(estado_inicial);
	int coluna = localizarZeroColuna(estado_inicial);
    while (!teste_objeto(estado_inicial, objetivo)) {
//        int novos_estados[N*N][N][N];
        modelo_transicao(estado_inicial,linha,coluna);
        
        // Selecionar um novo estado e atualizar estado_inicial
        // (lógica para escolher o próximo estado)

        imprimir(estado_inicial);
    usleep(5000);
    }

    printf("Puzzle resolvido!\n");

    return 0;
}
