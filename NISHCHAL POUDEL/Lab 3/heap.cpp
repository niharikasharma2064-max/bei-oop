#include <iostream>
using namespace std;

class StudentClass {
private:
    int* studentIDs;
    int size;

public:
    // Dynamic constructor allocating heap tracking fields
    StudentClass(int n) {
        size = n;
        studentIDs = new int[size]; 
        cout << "[Heap Allocation Success] Reserved memory space for " << size << " items." << endl;
    }

    // Destructor
    ~StudentClass() {
        delete[] studentIDs; 
        cout << "Memory freed." << endl;
    }

    void readIDs() {
        cout << "Please type in the " << size << " student registration IDs:\n";
        for (int i = 0; i < size; i++) {
            cout << "Student Slot [" << i + 1 << "]: ";
            cin >> studentIDs[i];
        }
    }

    void display() {
        cout << "\n--- Printing Database Registry View ---" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index Pos [" << i << "] -> Registered ID: " << studentIDs[i] << endl;
        }
        cout << "----------------------------------------\n" << endl;
    }
};

int main() {
    int totalCount;
    cout << "Enter how many student records you want to allocate memory space for: ";
    cin >> totalCount;

    // Direct object creation fires up the dynamic constructor mechanics
    StudentClass SectionB(totalCount);
    
    SectionB.readIDs();
    SectionB.display();

    cout << "Press Enter to terminate program execution and release heap memory...";
    cin.ignore(); 
    cin.get();    
    return 0;
}