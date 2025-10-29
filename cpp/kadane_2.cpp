#include <iostream>

void print_sub(int s, int e,int array[]) {
    std::cout << "[";
    for(int i = s + 0; i<= (e-1); i++) {
        std::cout << array[i] << ", ";
    }
    std::cout << array[e] << "]" << std::endl;
}

int main() {
    int array[] = {2,-3,-2,4,8,-4,-3,7,2,-4,-3};
    int n = sizeof(array) / sizeof(array[0]);

    int current_max = array[0];
    int max_so_far  = array[0];
    int start = 0, end = 0, s = 0;

    for (int i = 1; i < n; ++i) {
        if (current_max + array[i] < array[i]) {
            current_max = array[i];
            s = i; 
        } else {
            current_max += array[i];
        }

        if (current_max > max_so_far) {
            max_so_far = current_max;
            start = s;
            end = i;
        }
    }

    std::cout << "max sum = " << max_so_far << " start: " << start << " end: " << end << std::endl;
    print_sub(start, end, array);
    return 0;
}