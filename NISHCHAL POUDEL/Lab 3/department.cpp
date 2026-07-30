#include <iostream>
#include <string>
using namespace std;

class Department {
    int deptID;
    string deptName;
public:
    Department(int id, string name) : deptID(id), deptName(name) {
        cout << "Constructor: " << deptName << " created" << endl;
    }
    ~Department() {
        cout << "Destructor: " << deptName << " going out of scope" << endl;
    }
};

int main() {
    Department d1(1, "COMPUTER ENGINEERING");
    {
        Department d2(2, "MECHANICAL ENGINEERING");
        {
            Department d3(3, "CIVIL ENGINEERING");
        } // d3 destroyed
    } // d2 destroyed
    cin.ignore(); // clears buffer
    cin.get();    // holds screen 
    return 0;
} // d1 destroyed