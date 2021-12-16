#include "kruskal.h"

Branch * newNode(Edge *a) {
  Branch *temp = (Branch *)malloc(sizeof(Branch));
  temp->a = a;
  temp->next = NULL;

  return temp;
}

// Removes the element with the
// highest priority form the list
Branch * pop(Branch **head) {
  Branch *b = (*head);
  (*head) = (*head)->next;
  
  return b;
}

// Function to push according to priority
// Head = edges_set
void push(Branch **head, Edge *new_edge) {
  Branch *current = (*head);

  // Create new Node
  Branch *newnode = newNode(new_edge);
 
  if ((*head)->a->cost == 0) {
    // Special Case: Add head to the list
    (*head) = newnode;
    
  } else if ((*head)->a->cost > new_edge->cost) {
    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    newnode->next = (*head);
    (*head) = newnode;

  } else {
    // Traverse the list and find a
    // position to insert new node
    while 
      (current->next != NULL 
        && 
      current->next->a->cost < new_edge->cost) 
    {
      current = current->next;
    }

    // Either at the ends of the list
    // or at required position
    newnode->next = current->next;
    current->next = newnode;
  }
}

void print(Branch *head) {
  Branch *current = head;

  if (head != NULL) {
    printf("\nAristas del arbol:\n");    
    while (current != NULL) {
      printf("\ta = (u, v) -> u = %d & v = %d & cost = %d\n", 
        current -> a->u, current -> a->v, current -> a->cost);

      current = current -> next;
    }
  } else {
    printf("\nNada que mostrar, la lista esta vacia\n\n");
  }
}

Edge * initEdge(int u, int v, int cost) {
  Edge *a = (Edge *)malloc(sizeof(Edge));
  a->cost = cost;
  a->u = u;
  a->v = v;
  return a;
}
