#include <iostream>
#include <cmath>   
using namespace std;
class Dollar
{
private:
    float dol;  
    float cent; 
public:
    Dollar()
    {
        dol = 0.0;
        cent = 0.0;
    }
    Dollar(int Rs) 
    {
        float equiv_dollar = Rs / 150.0;     
        dol = floor(equiv_dollar);           
        cent = 100.0 * (equiv_dollar - dol); 
    }
    void Display()
    {
        cout << "$" << dol << " and " << cent << " cents";
    }
};
int main() 
{
    int user_rs;
    cout << "===== Nepali Rupees to USD Converter (All Float) =====" << endl;
    cout << "Enter the amount in Nepali Rupees (Rs): ";
    cin >> user_rs;
    Dollar d1 = user_rs; 
    cout << "\n--- Conversion Result ---" << endl;
    cout << "Equivalent of Rs. " << user_rs << " is: ";
    d1.Display();
    cout << endl << endl;
    system("pause"); 
    return 0;
}