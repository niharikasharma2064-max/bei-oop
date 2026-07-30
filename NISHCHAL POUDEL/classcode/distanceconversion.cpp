#include <iostream>
using namespace std;
class Distance
{
private:
    int feet, inch;
public:
    Distance()
    {
        feet = 0;
        inch = 0;
    }
    friend void operator>>(istream &, Distance &);
    friend void operator<<(ostream &, Distance);
};
void operator>>(istream &in, Distance &dis)
{
    cout << endl << "Enter data members of the object:";
    cout << endl << "feet=";
    in >> dis.feet;
    cout << "inch=";
    in >> dis.inch;
}
void operator<<(ostream &out, Distance dis)
{
    out << endl << "The data members of the object:";
    out << dis.feet << "'";
    out << dis.inch << "\"";
}
int main()
{
    Distance d;
    cin >> d;   // Calls operator>>(cin, d)
    cout << d;  // Calls operator<<(cout, d)
    cin.ignore(); // clears buffer
    cin.get();    // holds screen
    return 0;
}