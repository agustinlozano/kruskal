#include "kruskal.h"

name_type _find(int x, CE_set *C) {
  /* Devuleve el nombre de aquel conjunto que tiene
   * a x como miembro, esto lo usamos cuando queremos
   * chequear que no se genere un ciclo
   */
  return C->names[x].set_name;
}
