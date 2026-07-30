#include <iostream>
using namespace std;

class Circle {
private:
    float r;

public:
    Circle(float r1 = 0) {
        r = r1;
    }

    void setRadius(float x) {
        r = x;
    }

    float getArea() const {
        return 3.1416 * r * r;
    }

    float getCircumference() const {
        return 2 * 3.1416 * r;
    }

    void display() const {
        cout << "Radius: " << r << endl;
        cout << "Area: " << getArea() << endl;
        cout << "Circumference: " << getCircumference() << endl;
    }
};

int main() {
    Circle c1(6);
    const Circle c2(2);

    c1.display();
    c1.setRadius(7);

    c2.display();
    cout << c2.getArea() << endl;
    cout << c2.getCircumference() << endl;
  cin.ignore(); // clears buffer
    cin.get();    // holds screen
    return 0;
}