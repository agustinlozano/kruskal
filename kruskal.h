#ifndef KRUSKAL
#define KRUSKAL

#include <stdio.h>
#include <stdlib.h>

typedef int name_type;
typedef int element_type;
typedef int vertice;

#define VERTICES 5

//Una arista cuenta con dos vertices y un entero para su peso
typedef struct edge {
  vertice u;
  vertice v;
  int cost;
} Edge;

//Una rama cuenta con una Arista a y un enlace a la siguiente
typedef struct branch {
  Edge *a;
  struct branch *next;
} Branch;

//El header posee la cuenta 
typedef struct header {
  int count;
  int firts_element;
} Header;

typedef struct name {
  name_type set_name;
  int next;
} Name;

typedef struct ce_set {
  Name names[VERTICES];
  Header set_headers[VERTICES];
} CE_set;

void init(name_type A, element_type x, CE_set *C);
void _union(name_type A, name_type B, CE_set *C);
name_type _find(int x, CE_set *C);

void kruskal(Branch *V);


//Priority queue libraty
void print(Branch *head);
void push(Branch **edges_set, Edge *a);
  Branch * newNode(Edge *a);
Branch * pop(Branch **head);

Edge * initEdge(int u, int v, int cost);

#endif
