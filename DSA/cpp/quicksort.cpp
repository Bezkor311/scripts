
#include <ctime>     // C Time Library
#include <iostream>  // Standard Input / Output Streams Library
#include <stdlib.h>  // C Standard General Utilities Library
using namespace std; // import everything from 'std' into current

template <class Item>         // datentypneutraler Tausch des
void exch(Item &A, Item &B) { // Inhalts von Speicherzellen
  Item t = A;
  A = B;
  B = t;
}

template <class Item> // datentypneutrale Sortierung
void quickSort(Item a[], int l, int r) {
  int i = l, j = r;        // bisherige Intervallgrenzen
  Item p = a[(l + r) / 2]; // Pivot-Element in Intervallmitte
  while (i <= j) {         // Partitionierung des zu sortierenden Bereichs
    while (a[i] < p)
      i++; // linke Grenze im sortierten Bereich nach rechts verschieben
    while (a[j] > p)
      j--;      // rechte Grenze im sortierten Bereich nach links verschieben
    if (i <= j) // Bereich ist sortiert, wenn sich die Zeiger beruehren
      exch(a[i++], a[j--]); // Vertauschen der Elemente
  };
  if (l < j)
    quickSort(a, l, j); // linken Teilbereich sortieren
  if (i < r)
    quickSort(a, i, r); // rechten Teilbereich sortieren
}

int main(int argc, char *argv[]) {
  int i, N = atoi(argv[1]); // Anzahl Elemente im Array
  int sw = atoi(argv[2]);   // Auswahl der Datenquelle
  int *a = new int[N];      // Array mit definierter Laenge und Datentyp aus
                            // Parameter des Compileraufrufs anlegen
  if (sw) {
    srand((unsigned)time(0)); // Initialisierung des Zufallszahlengenerators
    for (int i = 0; i < N;)   // Array mit Zufalsszahlen fuellen
      a[i++] = static_cast<int>(1000 * (1.0 * rand() / RAND_MAX));
  } else {
    N = 0;
    while (cin >> a[N]) // Array mit Daten aus der
      N++;              // Standardeingabe fuellen
  }
  quickSort(a, 0, N - 1); // Array-Inhalt sortieren
  for (i = 0; i < N; i++)
    cout << a[i] << " "; // Array-Inhalt protokolieren
  cout << endl;
}
