#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int img;

public:
    Complex() {
        real = 0;
        img = 0;
    }

    Complex(int r) {
        real = r;
        img = 0;
    }

    Complex(int r, int i) {
        real = r;
        img = i;
    }

    Complex add(Complex c) {
        Complex temp;

        temp.real = real + c.real;
        temp.img = img + c.img;

        return temp;
    }

    void show() {
        cout << "(" << real << " + " << img << "i)" << endl;
    }
};

int main() {
    Complex c1(4, 5);
    Complex c2(2, 3);

    Complex c3 = c1.add(c2);

    cout << "First Complex Number: ";
    c1.show();

    cout << "Second Complex Number: ";
    c2.show();

    cout << "Sum: ";
    c3.show();

    return 0;
}