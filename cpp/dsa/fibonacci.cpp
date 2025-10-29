#include <iostream>
#include <vector>

using namespace std;

vector<int> folge = {0, 1};

void fibonacci(int a, int b) {
  if (b < 1000) {
    folge.push_back(a + b);
    fibonacci(b, b + a);
  }
}

void print() {
  for (int i = 0; i < folge.size(); i++) {
    cout << folge[i] << ", ";
  }
}

int main() {
  fibonacci(0, 1);
  print();
}
