#include <algorithm>
#include <iostream>

int main() {
  int array[] = {21, 312, 45, 65, 23, 1, 667, 41324, 767, 12, 43};
  int n = sizeof(array) / sizeof(array[0]);

  for (int i = 0; i < n - 1; i++) {
    int min_index = i;

    for (int j = i + 1; j < n; j++) {
      if (array[j] < array[min_index]) {
        min_index = j;
      }
    }
    if (min_index != i) {
      std::swap(array[i], array[min_index]);
    }
  }
  for (int i = 0; i < n; i++) {
    std::cout << array[i] << ", ";
  }
  std::cout << std::endl;

  return 0;
}
