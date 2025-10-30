#include <algorithm>
#include <iostream>

int main() {
  int array[] = {21, 312, 45, 65, 23, 1, 667, 41324, 767, 12, 43};
  bool switched;
  int n = sizeof(array) / sizeof(array[0]);

  do {
    switched = false;
    for (int i = 0; i < n - 1; i++) {
      if (array[i] < array[i + 1]) {
        continue;
      } else {
        std::swap(array[i], array[i + 1]);
        switched = true;
      }
    }
  } while (switched);

  for (int i = 0; i < n; i++) {
    std::cout << array[i] << ", ";
  }
  return 0;
}
