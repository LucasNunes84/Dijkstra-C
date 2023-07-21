// Estrutura para representar uma aresta
typedef struct Aresta {
    int destino; // Nó de destino
    int peso; // Peso da aresta
    struct Aresta* prox; // Próxima aresta na lista de adjacência
} Aresta;

// Estrutura para representar um grafo
typedef struct {
    Aresta** arestas; // Matriz de arestas
    int numNo; // Número de nós no grafo
    int* distancia; // Vetor de distancias mínimas
    int* visitado; // Vetor de nós visitados
} Grafo;

// Função para criar um novo grafo com o número de nós especificado
Grafo* criaGrafo(int numNo);

// Função para adicionar uma aresta ao grafo
void criaAresta(Grafo* grafo, int origem, int destino, int peso);

// Função para imprimir o grafo
void printGrafo(Grafo* grafo);

// Função utilizada em void dijkstra para encontrar o nó visitado com a menor distancia minima
int minDistancia(Grafo* grafo);

// Função utilizada em void dijkstra para definir distancia mínima caso seja o menor caminho
void relaxar(int noAtual, int noProx, int peso, Grafo* grafo);

// Algoritmo Dijkstra para encontrar caminhos mínimos
void dijkstra(Grafo* grafo, int origem);

// Imprime caminho
void printCaminhoMinimo(Grafo* grafo, int origem);
