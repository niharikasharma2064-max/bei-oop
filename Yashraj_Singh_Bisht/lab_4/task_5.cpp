#include <iostream>
using namespace std;

class Temperature {
private:
    float celsius;

public:
    // Parameterized constructor
    Temperature(float c) {
        celsius = c;
    }

    void setTemp(float c) {
        celsius = c;
    }

    float toFahrenheit() const {
        return (celsius * 9.0f / 5.0f) + 32.0f;
    }

    float toKelvin() const {
        return celsius + 273.15f;
    }

    // Friend function to compare two temperatures
    friend bool areEqual(Temperature t1, Temperature t2);
};

// Friend function definition
bool areEqual(Temperature t1, Temperature t2) {
    return t1.celsius == t2.celsius;
}

int main() {
    Temperature t1(25.0f);
    Temperature t2(100.0f);

    cout << "T1 in Fahrenheit: " << t1.toFahrenheit() << " F" << endl;
    cout << "T1 in Kelvin: " << t1.toKelvin() << " K" << endl;
    cout << "T2 in Fahrenheit: " << t2.toFahrenheit() << " F" << endl;

    // Check equality
    if (areEqual(t1, t2)) {
        cout << "Temperatures T1 and T2 are equal." << endl;
    } else {
        cout << "Temperatures T1 and T2 are different." << endl;
    }

    cout << "\nUpdating T2 to match T1..." << endl;
    t2.setTemp(25.0f);

    if (areEqual(t1, t2)) {
        cout << "Temperatures T1 and T2 are now equal." << endl;
    } else {
        cout << "Temperatures are still different." << endl;
    }

    return 0;
}
