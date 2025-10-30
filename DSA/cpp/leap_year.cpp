#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    int year;

    for (int i = 1; i < argc; ++i) {
        year = stoi(argv[i]);
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) {
            cout << year << " is a leap year." << endl;
        } else {
            cout << year << " is not a leap year." << endl;
        }
    }
    return 0;
}

