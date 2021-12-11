#include "kruskal.h"

/*  La funcion toma como parametro un arbol
 *  
 *  Arbol:
 *  Es una lista enlazada de tipo priority queue
 *  donde cada node de esta lista es una rama minima del
 *  arbol.
 *  
 *  Nodo priority queue: rama minima
 * 
 *     Branch {
 *       Edge   a    -> (U, V, Cost)
 *       Branch next -> (siguiente rama)
 *     }
 */

void kruskal(Branch *graph) {
  Branch *T = (Branch *)malloc(sizeof(Branch));
  Edge *a = (Edge *)malloc(sizeof(Edge)); 
  T->a = a;

  //Conjunto V agrupado en un conjunto de componentes tipo CE_set
  CE_set *components = (CE_set *)malloc(sizeof(CE_set));

  /* Comienzo */
  //Cantidad actual de componentes
  int comp_n = VERTICES;

  //Asignamos el valor inicial a cada componente
  for (int i = 0; i < VERTICES-1; i++) {
    int comp = i;
    init(comp, i, components);
  }

  while (comp_n > 1) {
    Branch *b = pop(&graph);
    Edge *a = b->a;

    name_type u = _find(a->u, components);
    name_type v = _find(a->v, components);

    if (u != v) {
      // a conecta dos componentes diferentes - ESTA TILDA EL PROGRAMA
      _union(a->u, a->v, components);
      push(&T, a);
      comp_n--;
    }
  }

  //Recorremos T
  print(T);
}
