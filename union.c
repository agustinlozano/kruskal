#include "kruskal.h"

void _union(name_type A, name_type B, CE_set C) {
  int i;

  //A es el conjunto mas grande, combina B dendro de A
  if (C.set_headers[A].count > C.set_headers[B].count) {
    i = C.set_headers[B].firts_element;

    /* Encuentra el final de B, cambiando los nombres de los conjuntos
     * por A conforme se avanza
     */
    do {
      C.names[i].set_name = A;
      i = C.names[i].next;
    } while (C.names[i].next == 0);

    //Agrega a la lista A al final de la B y llama A al resultado
    //Ahora i es el indice del ultimo elemento de B
    C.names[i].set_name = A;
    C.names[i].next = C.set_headers[A].firts_element;
    C.set_headers[A].firts_element = C.set_headers[B].firts_element;
    C.set_headers[A].count = C.set_headers[A].count + C.set_headers[B].count;
  
  //B es al menos tan grande como A
  } else {
    i = C.set_headers[A].firts_element;

    do {
      C.names[i].set_name = B;
      i = C.names[i].next;
    } while (C.names[i].next == 0);

    C.names[i].set_name = B;
    C.names[i].next = C.set_headers[B].firts_element;
    C.set_headers[B].firts_element = C.set_headers[A].firts_element;
    C.set_headers[B].count = C.set_headers[A].count + C.set_headers[B].count;
  }
}
