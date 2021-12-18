#include "kruskal.h"

void init(name_type A, element_type x, CE_set *C) {
  C->names[x].set_name = A;
  C->names[x].next = 0;
  C->set_headers[A].count = 1;
  C->set_headers[A].firt_element = x;
}

name_type _find(int x, CE_set *C) {
  /* Devuleve el nombre de aquel conjunto que tiene
   * a x como miembro, esto lo usamos cuando queremos
   * chequear que no se genere un ciclo
   */
  return C->names[x].set_name;
}

void _union(name_type A, name_type B, CE_set *C) {
  //A es el conjunto mas grande, combina B dendro de A
  if (C->set_headers[A].count > C->set_headers[B].count) {
    int i = C->set_headers[B].firt_element;

    /* Encuentra el final de B, cambiando los nombres de los conjuntos
     * por A conforme se avanza
     */
    for (int j = 0; j < VERTICES-1; j++) {
      C->names[i].set_name = A;
      i = C->names[i].next;
    }

    //Agrega a la lista A al final de la B y llama A al resultado
    //Ahora i es el indice del ultimo elemento de B
    C->names[i].set_name = A;
    C->names[i].next = C->set_headers[A].firt_element;
    C->set_headers[A].firt_element = C->set_headers[B].firt_element;
    C->set_headers[A].count = (C->set_headers[A].count) + (C->set_headers[B].count);
  
  //B es al menos tan grande como A
  } else {
    int i = C->set_headers[A].firt_element;

    for (int j = 0; j < VERTICES-1; j++) {
      C->names[i].set_name = A;
      i = C->names[i].next;
    }

    C->names[i].set_name = B;
    C->names[i].next = C->set_headers[B].firt_element;
    C->set_headers[B].firt_element = C->set_headers[A].firt_element;
    C->set_headers[B].count = (C->set_headers[A].count) + (C->set_headers[B].count);
  }
}
