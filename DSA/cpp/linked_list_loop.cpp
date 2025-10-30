#include <iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

void print_node(node *head) {
  node *current = head;

  for (int i = 0; i < 102; i++) {
    cout << current->data << " -> ";
    current = current->next;
  }
  cout << "NULL";
}

int main() {
  node *n;
  node *t;
  node *h;

  n = new node;
  n->data = 1;
  h = n;
  t = n;

  n = new node;
  n->data = 2;
  t->next = n;
  t = n;

  for (int i = 0; i < 100; i++) {
    n = new node;
    n->data = i + 2;
    t->next = n;
    t = n;
  }

  print_node(h);
  return 0;
}
