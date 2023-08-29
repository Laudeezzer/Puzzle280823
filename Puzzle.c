//Feito por Jeremias Fenias Jorge e Laudo de Sousa David
#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>

// Tamanho do puzzle
#define N 3
int i,j;
// Função para verificar se um estado é o objetivo
int teste_objeto(int estado[][N], int objetivo[][N]) {
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
struct posicao{
	int linha,coluna;
}Posicao;
void localizar_zero(int estado[][N],posicao *local){
	int i,j;
	tam=N;
	for(i=0;i<tam;i++){
		for(j=0;j<tam;j++){
			if(estado[i][j]==0){
				local->linha = i;
				local->coluna = j;
				return local; 
			}
		}
	}
}
// Função para gerar os estados subsequentes com base no estado atual
void modelo_transicao(int estado[][N]) {
	if(N=3){
		printf("Yes")
	}
	
}/*
void modelo_transicaoo(int estado[][N], int novos_estados[][N][N], int *num_estados) {
    // Implemente a lógica para gerar os novos estados
    // Atualize o valor de num_estados
}
*/
// Função para imprimir um estado do puzzle
void imprimir(int estado[][N]) {
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
	printf("Estado Inicial");
    imprimir(estado_inicial);

    while (!teste_objeto(estado_inicial, objetivo)) {
//        int novos_estados[N*N][N][N];
        modelo_transicao(estado_inicial);
        
        // Selecionar um novo estado e atualizar estado_inicial
        // (lógica para escolher o próximo estado)

        imprimir(estado_inicial);
    usleep(2000);
    }

    printf("Puzzle resolvido!\n");

    return 0;
}
