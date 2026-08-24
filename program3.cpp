#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
    float x;
    float y;

public:
    
    Point() {
        x = 0;
        y = 0;
    }

    
    Point(float a) {
        x = a;
        y = a;
    }

    
    Point(float a, float b) {
        x = a;
        y = b;
    }

    
    void show() {
        cout << "(" << x << ", " << y << ")";
    }

    
    float distanceFromOrigin() {
        return sqrt(x * x + y * y);
    }

    
    float distanceBetween(Point p) {
        return sqrt((x - p.x) * (x - p.x) +
                    (y - p.y) * (y - p.y));
    }
};

int main() {
    
    Point p1;

    
    Point p2(5);

    
    Point p3(2, 7);

    
    cout << "Point 1: ";
    p1.show();

    cout << "\nPoint 2: ";
    p2.show();

    cout << "\nPoint 3: ";
    p3.show();

    
    cout << "\n\nDistance of Point 1 from origin: "
         << p1.distanceFromOrigin();

    cout << "\nDistance of Point 2 from origin: "
         << p2.distanceFromOrigin();

    cout << "\nDistance of Point 3 from origin: "
         << p3.distanceFromOrigin();

    
    cout << "\n\nDistance between Point 2 and Point 3: "
         << p2.distanceBetween(p3);

    return 0;
}