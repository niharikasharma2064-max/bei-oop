#include <iostream>
using namespace std;
class Box {
private:
    float l, b, h;
public:
    // i) Default constructor
    Box() {
        l = 1.0; b = 1.0; h = 1.0;
        cout << "[Default Constructor Called] Box initialized with dimensions 1x1x1." << endl;
    }
    // ii) Parameterized constructor
    Box(float length, float breadth, float height) {
        l = length; b = breadth; h = height;
        cout << "[Parameterized Constructor Called] Box initialized with customized dimensions." << endl;
    }

    // iii) Constructor with a default argument 
    Box(float side) {
        l = side; b = side; h = 5.0; // Height defaults to 5.0
        cout << "[Default Argument Constructor Called] Square base box created with default height 5.0." << endl;
    }
    // iv) Copy constructor
    Box(const Box &old_box) {
        l = old_box.l; b = old_box.b; h = old_box.h;
        cout << "[Copy Constructor Called] New box cloned from an existing box instance." << endl;
    }

    // v) Destructor
    ~Box() {
        cout << "[Destructor Called] Box object with length " << l << " is being destroyed." << endl;
    }

    void display() {
        cout << "Dimensions: " << l << " x " << b << " x " << h << endl;
    }
};
int main() {
    cout << "--- Creating obj1 ---" << endl;
    Box obj1; // Calls Default
    obj1.display();

    cout << "\n--- Creating obj2 ---" << endl;
    Box obj2(4.5, 3.0, 2.5); // Calls Parameterized
    obj2.display();

    cout << "\n--- Creating obj3 ---" << endl;
    Box obj3(7.2); 
    obj3.display();

    cout << "\n--- Creating obj4 ---" << endl;
    Box obj4(obj2); // Calls Copy
    obj4.display();

    cout << "\n--- Exiting Main Block (Objects go out of scope) ---" << endl;
    cin.ignore(); // clears buffer
    cin.get();    // holds screen
    return 0;
}