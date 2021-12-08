#include "kruskal.h"

int main(void) {
  int mcostos[VERTICES][VERTICES];
  Branch *tree;

  for (int i = 0; i <= VERTICES-1; i++) {
    for (int j = i+1; j <= VERTICES-1; j++) {
      printf("Ingrese el costo de lado entre vertices %d y %d: ", 
        i, j);
      scanf(" %d", &mcostos[i][j]);
    }
  }

  // for (int i = 0; i <= VERTICES-1; i++) {
  //   //La mitad de la diagonal de la matriz
  //   for (int j = i+1; j <= VERTICES-1; j++) {
  //     //pushear los costos en una lista enlazada diferente?
  //     if (mcostos[i][j] != 0) {
  //       push(/*?*/);
  //     }
  //   }
  // }

  kruskal(tree);

  return EXIT_SUCCESS;
}
