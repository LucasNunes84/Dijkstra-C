#include <stdio.h>
#include <stdlib.h>
#include "grafoDijkstra.h"


// Função para criar um novo grafo com o número de nós especificado
Grafo* criaGrafo(int numNo) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->arestas = (Aresta**)malloc(numNo * sizeof(Aresta*));
    grafo->distancia = (int*)malloc(numNo * sizeof(int));
    grafo->visitado = (int*)malloc(numNo * sizeof(int));
    grafo->numNo = numNo;

    // Inicializar as arestas
    for (int i = 0; i < numNo; i++) {
        grafo->arestas[i] = NULL;
        grafo->distancia[i] = 100000; // Representação do infinito, considerando um grafo ponderado que não pode ser negativo
        grafo->visitado[i] = 0; // NÃO VISITADO
    }

    return grafo;
}

// Função para adicionar uma aresta ao grafo
void criaAresta(Grafo* grafo, int origem, int destino, int peso) {
    Aresta* aresta = (Aresta*)malloc(sizeof(Aresta));
    aresta->destino = destino;
    aresta->peso = peso;
    aresta->prox = grafo->arestas[origem];
    grafo->arestas[origem] = aresta;
}

// Função para imprimir o grafo
void printGrafo(Grafo* grafo) {
    for (int i = 0; i < grafo->numNo; i++) {
        Aresta* aresta = grafo->arestas[i];
        printf("Arestas do nó %d:\n", i);
        while (aresta != NULL) {
            printf("-> %d (peso: %d)\n", aresta->destino, aresta->peso);
            aresta = aresta->prox;
        }
        printf("\n");
    }
}

// Função utilizada em void dijkstra para encontrar o nó visitado com a menor distancia minima
int minDistancia(Grafo* grafo){
    int minDist = 100000;
    int minNo = -1;

    for(int i=0; i<grafo->numNo; i++){
        if(grafo->visitado[i] == 0 && grafo->distancia[i]<minDist){
            minDist = grafo->distancia[i];
            minNo = i;
            printf("%d", i);
        }
    }
    return minNo;
}

// Função utilizada em void dijkstra para definir distancia mínima caso seja o menor caminho
void relaxar(int noAtual, int noProx, int peso, Grafo* grafo){
    if(grafo->distancia[noAtual] + peso < grafo->distancia[noProx])
        grafo->distancia[noProx] = grafo->distancia[noAtual] + peso;
}

// Algoritmo Dijkstra para encontrar caminhos mínimos
void dijkstra(Grafo* grafo, int origem){
    // Int para representar nó atual
    int noAtual;
    int noProx;
    int peso;

    // Zera a distância da origem
    grafo->distancia[origem] = 0;

    for(int i=0; i<grafo->numNo-1; i++){
        // chama função para encontrar vértice de menor distância
        noAtual = minDistancia(grafo);

        // Marca o nó atual como visitado
        grafo->visitado[noAtual] = 1;

        // Cria um vetor de arestas com a distância mínima dos nós adjacentes ao atual
        Aresta* aresta = grafo->arestas[noAtual];

        while(aresta != NULL){
            noProx = aresta->destino;
            peso = aresta->peso;

            if(grafo->visitado[noProx] == 0 && grafo->distancia[noAtual] != -1){
                relaxar(noAtual, noProx, peso, grafo);
            }

            aresta = aresta->prox;
        }
    }
}

// Imprime caminho mínimo
void printCaminhoMinimo(Grafo* grafo, int origem){
    printf("Caminhos mínimos a partir do nó %d: \n", origem);
    for(int i=0; i<grafo->numNo; i++){
        printf("Para o nó %d: ", i);
        if(grafo->distancia[i] != -1) {
            printf("Distância mínima = %d\n", grafo->distancia[i]);
        } else {
            printf("Não há caminho! \n");
        }
    }
}



