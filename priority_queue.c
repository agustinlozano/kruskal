#include "kruskal.h"

Branch * newNode(Edge a) {
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
//Head = edges_set
void push(Branch **head, Edge new_edge) {
  Branch *current = (*head);

  // Create new Node
  Branch *newnode = newNode(new_edge);

  // Special Case: The head of list has lesser
  // priority than new node. So insert new
  // node before head node and change head node.
  if ((*head)->a.cost > new_edge.cost) {
    // Insert New Node before head
    newnode->next = (*head);
    (*head) = newnode;

  } else {
    // Traverse the list and find a
    // position to insert new node
    while 
      (current->next != NULL 
        && 
      current->next->a.cost < new_edge.cost) 
    {
      current = current->next;
    }

    // Either at the ends of the list
    // or at required position
    newnode->next = current->next;
    current->next = newnode;
  }
}
