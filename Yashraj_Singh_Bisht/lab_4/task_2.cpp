#include <iostream>
using namespace std;

class Circle {
private:
    float radius;

public:
    Circle(float r) {
        radius = r;
    }

    void setRadius(float r) {
        radius = r;
    }

    float getArea() const {
        return 3.14159f * radius * radius;
    }

    float getCircumference() const {
        return 2 * 3.14159f * radius;
    }

    void display() const {
        cout << "Radius: " << radius << ", Area: " << getArea() 
             << ", Circumference: " << getCircumference() << endl;
    }
};

int main() {
    // Normal (non-const) object
    Circle normalCircle(5.0f);
    cout << "--- Normal Object Calls ---" << endl;
    normalCircle.setRadius(7.0f); // Allowed: non-const object can call non-const functions
    normalCircle.display();        // Allowed: non-const object can call const functions

    // Const object
    const Circle constCircle(10.0f);
    cout << "\n--- Const Object Calls ---" << endl;
    constCircle.display();         // Allowed: const object calling a const function

    /* 
       WHY CERTAIN CALLS ARE NOT ALLOWED:
          
       Reason: 'constCircle' is declared as a constant object, which guarantees 
       that its data members (radius) cannot be modified after initialization. 
       The function 'setRadius()' is a non-const member function, meaning it has 
       the potential to change the object's state. C++ strictly prohibits calling 
       non-const member functions on const objects to protect data integrity.
    */

    return 0;
}
