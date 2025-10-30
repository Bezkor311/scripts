#include <iostream>

struct Node {
  int data;
  Node *next;
  explicit Node(int d) : data(d), next(nullptr) {}
};

// -------------------------
// Hilfsfunktionen
// -------------------------

void printList(const Node *node) {
  while (node) {
    std::cout << node->data << " -> ";
    node = node->next;
  }
  std::cout << "null\n";
}

// -------------------------
// Einfügen eines Knotens
// -------------------------

/*
 * Fügt einen neuen Knoten mit Wert 'value' an der gegebenen Position ein.
 * Position = 1 bedeutet: am Anfang (neuer Kopf).
 * Gibt den (evtl. neuen) Kopf zurück.
 */
Node *insertNodeAtPosition(Node *head, int value, int position) {
  Node *newNode = new Node(value);

  // Fall 1: Liste leer oder am Anfang einfügen
  if (position <= 1 || !head) {
    newNode->next = head;
    return newNode;
  }

  Node *current = head;
  // Bis zum Knoten vor der Einfügestelle laufen
  for (int i = 1; i < position - 1 && current->next; ++i) {
    current = current->next;
  }

  // Einfügen zwischen current und current->next
  newNode->next = current->next;
  current->next = newNode;

  return head;
}

// -------------------------
// Löschen eines Knotens
// -------------------------

Node *deleteNode(Node *head, Node *target) {
  if (!head || !target)
    return head;

  // Fall 1: target ist der Kopf
  if (head == target) {
    Node *newHead = head->next;
    delete head;
    return newHead;
  }

  // Vorgänger von target suchen
  Node *prev = head;
  while (prev->next && prev->next != target) {
    prev = prev->next;
  }

  // target nicht gefunden
  if (!prev->next)
    return head;

  // Ausklinken und freigeben
  prev->next = target->next;
  delete target;
  return head;
}

// -------------------------
// Liste vollständig löschen
// -------------------------

void destroyList(Node *head) {
  while (head) {
    Node *next = head->next;
    delete head;
    head = next;
  }
}

// -------------------------
// main()
// -------------------------

int main() {
  // Liste erstellen: 3 -> 5 -> 13 -> 2 -> null
  Node *node1 = new Node(3);
  Node *node2 = new Node(5);
  Node *node3 = new Node(13);
  Node *node4 = new Node(2);

  node1->next = node2;
  node2->next = node3;
  node3->next = node4;

  std::cout << "Original:\n";
  printList(node1);

  // Beispiel: Einfügen eines neuen Knotens an Position 2
  node1 = insertNodeAtPosition(node1, 99, 2);
  std::cout << "Nach insert(99, Position 2):\n";
  printList(node1);

  // Beispiel: Einfügen eines neuen Knotens am Anfang
  node1 = insertNodeAtPosition(node1, 42, 1);
  std::cout << "Nach insert(42, Position 1):\n";
  printList(node1);

  // Beispiel: Löschen des Knotens node3 (mit Wert 13)
  node1 = deleteNode(node1, node3);
  std::cout << "Nach delete(node3):\n";
  printList(node1);

  // Beispiel: Kopf löschen
  node1 = deleteNode(node1, node1);
  std::cout << "Nach delete(head):\n";
  printList(node1);

  destroyList(node1);
  return 0;
}
