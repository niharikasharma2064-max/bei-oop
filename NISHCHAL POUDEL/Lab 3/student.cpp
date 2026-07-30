#include <iostream>
using namespace std;

class StudentClass {
    int* studentIDs;
    int size;
public:
    // Dynamic Constructor
    StudentClass(int n) {
        size = n;
        studentIDs = new int[size]; 
        cout << "Enter " << n << " Student IDs: " << endl;
        for(int i = 0; i < size; i++) {
            cin >> studentIDs[i];
        }
    }

    void display() {
        cout << "Stored Student IDs: ";
        for(int i = 0; i < size; i++) {
            cout << studentIDs[i] << " ";
        }
        cout << endl;
    }

    ~StudentClass() {
        delete[] studentIDs; // Freeing heap memory
        cout << "Memory freed" << endl;
    }
};

int main() {
    int n;
    cout << "How many students? ";
    cin >> n;
    
    StudentClass s1(n);
    s1.display();
       cin.ignore(); // clears buffer
    cin.get();    // holds screen 
    return 0;
}