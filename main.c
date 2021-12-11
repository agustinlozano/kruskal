#include "kruskal.h"

int main(void) {
  int mcostos[VERTICES][VERTICES];
  Branch *graph = (Branch *)malloc(sizeof(Branch));
  Edge *a = (Edge *)malloc(sizeof(Edge)); 
  graph->a = a;

  for (int i = 0; i <= VERTICES-1; i++) {
    for (int j = i+1; j <= VERTICES-1; j++) {
      printf("Ingrese el costo de lado entre vertices %d y %d: ", 
        i, j);
      scanf(" %d", &mcostos[i][j]);
    }
  }

  // Relleno los demas valores del arbol
  for (int i = 0; i <= VERTICES-1; i++) {
    //mitad de la matriz de adyacencia
    for (int j = i+1; j <= VERTICES-1; j++) {
     /* Aca lo que se logra es tener una lista enlazada
      * tipo priority queue, donde cada nodo representa 
      * una rama minima del albol 
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
