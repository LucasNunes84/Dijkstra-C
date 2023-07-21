#include <stdio.h>
#include <stdlib.h>
#include "grafoDijkstra.h"

int main() {
    int numNo;
    int origem, destino, peso;
    printf("Digite o número de nós no grafo: ");
    scanf("%d", &numNo);

    Grafo* grafo = criaGrafo(numNo);

    int esc = 1;
    while (esc != 0) {
        printf("\nMenu:\n");
        printf("1. Inserir aresta\n");
        printf("2. Imprimir grafo\n");
        printf("3. Gerar caminho mínimo\n");
        printf("4. Imprimir caminhos mínimos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &esc);

        switch (esc) {
            case 1:    
                printf("\nInserir aresta:\n");
                printf("Digite o nó de origem: ");
                scanf("%d", &origem);
                printf("Digite o nó de destino: ");
                scanf("%d", &destino);
                printf("Digite o peso da aresta: ");
                scanf("%d", &peso);
                criaAresta(grafo, origem, destino, peso);
                break;
            case 2:
                printf("\nImprimir grafo:\n");
                printGrafo(grafo);
                break;
            case 3:
                printf("\nGerar caminho mínimo:\n");
                printf("Digite o nó de origem: ");
                scanf("%d", &origem);
                dijkstra(grafo, origem);
                break;
            case 4:
                printf("\nImprimir caminhos mínimos:\n");
                printf("Digite o nó de origem: ");
                scanf("%d", &origem);
                printCaminhoMinimo(grafo, origem);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    }

    return 0;
}