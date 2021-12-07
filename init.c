#include "kruskal.h"

void init(name_type A, element_type x, CE_set C) {
  C.names[x].set_name = A;
  C.names[x].next = 0;
  C.set_headers[A].count = 1;
  C.set_headers[A].firts_element = x;
}
