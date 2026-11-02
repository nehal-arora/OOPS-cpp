#include <iostream>
using namespace std;

template <class T>
class Larger {
    T a, b;

public:
    Larger(T x, T y) {
        a = x;
        b = y;
    }

    void display() {
        if (a > b) {
            cout << "Larger value between "
                 << a << " and " << b
                 << " is: " << a << endl;
        } else {
            cout << "Larger value between "
                 << a << " and " << b
                 << " is: " << b << endl;
        }
    }

    ~Larger() {
    }
};

int main() {
    Larger<int> obj1(7, 5);
    obj1.display();

    Larger<float> obj2(6.5, 4.2);
    obj2.display();

    return 0;
}