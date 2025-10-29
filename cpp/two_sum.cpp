
#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v) {
    for (int x : v) cout << x << ", ";
}

int main() {
    
    int numbers[] = {2,-34,4356,78,-2,-12,23};

    int sum = 0;
    int last_sum = 0;
    vector<int> v;

    for(int i = 0; i < (sizeof(numbers)/ sizeof(numbers[0])); i++) {
        sum += numbers[i];
        if(sum > last_sum) {
            v.push_back(i);
            last_sum = sum;
        } else {
            sum = last_sum;
        }
    }

    cout << sum << endl;
    print_vector(v);
}


