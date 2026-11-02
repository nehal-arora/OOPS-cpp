#include <iostream>
using namespace std;

template <typename T>
T square(T a) {
    return a * a;
}

int main() {
    cout << "The square of 7 is: "
         << square(7) << endl;

    cout << "The square of 6.5 is: "
         << square(6.5) << endl;

    return 0;
}