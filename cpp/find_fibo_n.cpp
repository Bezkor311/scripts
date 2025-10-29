#include <iostream>
#include <stdlib.h>

using namespace std;

int fibo_at_n(int n) {
  int num;
  if (n == 0) {
    return 0;
  } else if (n == 1) {
    return 1;
  } else {
    num = fibo_at_n(n - 1) + fibo_at_n(n - 2);
    return num;
  }
}

int main(int argc, char *argv[]) {
  int n;
  int fibo_num;

  if (argc == 2) {
    n = atoi(argv[1]);
  } else {
    cout << "only one Integer Number!!" << endl;
    cin >> n;
  }

  fibo_num = fibo_at_n(n);
  cout << "The n-th Fibonacci Number is: " << fibo_num;

  return 0;
}
