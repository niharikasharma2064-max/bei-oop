#include <iostream>
using namespace std;

class Dollar; 

class Rupees
{
private:
    long Rs;
    float Paisa;

public:
    Rupees()
    {
        Rs = 0;
        Paisa = 0;
    }
    
    Rupees(long r, float p)
    {
        Rs = r;
        Paisa = p;
    }
    
    void Display() 
    {
        cout << "Rs. " << Rs << " and " << Paisa << " paisa";
    }
};

class Dollar
{
private:
    int dol;
    float cent;

public:
    Dollar()
    {
        dol = 0;
        cent = 0.0;
    }
    
    Dollar(int d, float c)
    {
        dol = d;
        cent = c;
    }
    
    void Display()
    {
        cout << "$" << dol << " and " << cent << " cent";
    }

    operator Rupees(); 
};

Dollar::operator Rupees()
{
    long rr;
    float pp, total_rs;
    
    total_rs = 89 * (dol + cent / 100.0); 
    rr = (long)total_rs;
    pp = (total_rs - rr) * 100;
    
    return Rupees(rr, pp); 
}

int main()
{
    Dollar d(4300, 1.5);
    Rupees r;
    
    r = d; 
    
    cout << "In Dollar: ";
    d.Display();
    
    cout << endl << "In Rupees: ";
    r.Display();
    cout << endl;
    
    return 0;
}