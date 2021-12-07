#include "kruskal.h"

Node* newNode(int d, int p) {
  Node* temp = (Node *)malloc(sizeof(Node));
  temp->data = d;
  temp->priority = p;
  temp->next = NULL;

  return temp;
}

// Removes the element with the
// highest priority form the list
void pop(Node **head) {
  Node* temp = (*head);
  (*head) = (*head)->next;
  free(temp);
}

// Function to push according to priority
void push(Node **head, int d, int p) {
  Node* current = (*head);

  // Create new Node
  Node* temp = newNode(d, p);

  // Special Case: The head of list has lesser
  // priority than new node. So insert new
  // node before head node and change head node.
  if ((*head)->priority > p) {
    // Insert New Node before head
    temp->next = (*head);
    (*head) = temp;

  } else {
    // Traverse the list and find a
    // position to insert new node
    while (current->next != NULL && current->next->priority < p) {
        current = current->next;
    }

    // Either at the ends of the list
    // or at required position
    temp->next = current->next;
    current->next = temp;
  }
}
