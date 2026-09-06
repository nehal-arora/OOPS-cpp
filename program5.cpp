#include <iostream>
using namespace std;

class LIST {
public:
    virtual void store(int) = 0;
    virtual int retrieve() = 0;
};

class stack : public LIST {
    int arr[100];
    int top;

public:
    stack() {
        top = -1;
    }

    void store(int x) override {
        if (top < 99)
            arr[++top] = x;
    }

    int retrieve() override {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
};

class queue : public LIST {
    int arr[100];
    int front, rear;

public:
    queue() {
        front = 0;
        rear = -1;
    }

    void store(int x) override {
        if (rear < 99)
            arr[++rear] = x;
    }

    int retrieve() override {
        if (front > rear) {
            cout << "Queue Underflow\n";
            return -1;
        }
        return arr[front++];
    }
};

int main() {
    stack s;
    s.store(10);
    s.store(20);

    cout << s.retrieve() << endl;
    cout << s.retrieve() << endl;

    queue q;
    q.store(10);
    q.store(20);

    cout << q.retrieve() << endl;
    cout << q.retrieve() << endl;

    return 0;
}