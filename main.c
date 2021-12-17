#include "kruskal.h"

int main(void) {
  int mcostos[VERTICES][VERTICES];
  Branch *graph = (Branch *)malloc(sizeof(Branch));
  Edge *a = (Edge *)malloc(sizeof(Edge)); 
  graph->a = a;

  printf("\tAlgoritmo de Kruskal\n");
  
  printf("\nIngrese los datos requeridos del grafo en cuestion\n");
  for (int i = 0; i <= VERTICES-1; i++) {
    for (int j = i+1; j <= VERTICES-1; j++) {
      printf("\t- costo de la arista entre vertices %d y %d: ", 
        i, j);
      scanf(" %d", &mcostos[i][j]);
    }
  }

  for (int i = 0; i <= VERTICES-1; i++) {
    //mitad de la matriz de adyacencia
    for (int j = i+1; j <= VERTICES-1; j++) {
     /* Aca lo que se logra es tener una lista enlazada
      * tipo priority queue, donde cada nodo representa 
      * una rama minima del grafo 
      */
      if (mcostos[i][j] != 0) {
        Edge *a = initEdge(i, j, mcostos[i][j]);
        push(&graph, a);
      }
    }
  }

  kruskal(graph);

  return EXIT_SUCCESS;
}
