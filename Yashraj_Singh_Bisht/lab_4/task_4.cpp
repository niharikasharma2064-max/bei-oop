#include <iostream>
using namespace std;

// Forward declaration needed so Physics can see Maths exists
class Maths; 

class Physics {
private:
    int marks;
public:
    Physics(int m) { marks = m; }
    
    // Friend function declarations
    friend int totalMarks(Physics p, Maths m);
    friend bool isDistinction(Physics p, Maths m);
};

class Maths {
private:
    int marks;
public:
    Maths(int m) { marks = m; }
    
    // Friend function declarations
    friend int totalMarks(Physics p, Maths m);
    friend bool isDistinction(Physics p, Maths m);
};

// Friend function to calculate the sum
int totalMarks(Physics p, Maths m) {
    return p.marks + m.marks;
}

// Friend function to check for distinction
bool isDistinction(Physics p, Maths m) {
    return totalMarks(p, m) >= 160;
}

int main() {
    int pMarks, mMarks;

    cout << "Enter marks for Physics (out of 100): ";
    cin >> pMarks;
    cout << "Enter marks for Maths (out of 100): ";
    cin >> mMarks;

    Physics physObj(pMarks);
    Maths mathObj(mMarks);

    int total = totalMarks(physObj, mathObj);
    cout << "\nTotal Marks: " << total << " / 200" << endl;

    if (isDistinction(physObj, mathObj)) {
        cout << "Result: Distinction achieved!" << endl;
    } else {
        cout << "Result: No distinction." << endl;
    }

    return 0;
}
