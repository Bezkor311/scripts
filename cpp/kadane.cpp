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

    int max = 0;
    int abs_max = 0;
    int s = 0,e = 0;


    for(int i = 0; i < (sizeof(array)/ sizeof(array[0]));i++) {
        max += array[i];

        if (max < 0) {
            max = 0;
            s = i+1;
            continue;
        } else {
            abs_max = max;
            e = i;

        }
    }
    std::cout << abs_max << " start: " << s << " end: " << e << std::endl;
    print_sub(s,e,array);
}