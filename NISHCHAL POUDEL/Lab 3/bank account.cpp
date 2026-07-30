#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string holderName;
    float balance;

public:
    // Default constructor
    BankAccount() {
        accountNumber = 0;
        holderName = "Unknown";
        balance = 0.0;
    }

    // Parameterized constructor
    BankAccount(int accNum, string name, float initialBalance) {
        accountNumber = accNum;
        holderName = name;
        balance = initialBalance;
    }

    // Destructor
    ~BankAccount() {
        cout << "[System Log] Account Session closed for ID: " << accountNumber << endl;
    }
    void deposit(float amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited Rs." << amount << " successfully." << endl;
        }
    }
    void withdraw(float amount) {
        if (amount > balance) {
            cout << "Transaction Failed! Insufficient Balance." << endl;
        } else if (amount <= 0) {
            cout << "Invalid withdrawal value." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew Rs." << amount << " successfully." << endl;
        }
    }
    void display() {
        cout << "\n--- Account Status Update ---" << endl;
        cout << "Account Holder: " << holderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: Rs." << balance << endl;
        cout << "-----------------------------\n" << endl;
    }
};
int main() {
    int accNum;
    string name;
    float initBalance, depAmount, withAmount;
    cout << "--- Create New Bank Account ---" << endl;
    cout << "Enter Account Number: ";
    cin >> accNum;
    cout << "Enter Holder Name: ";
    cin.ignore(); // Clear buffer 
    getline(cin, name);
    cout << "Enter Initial Balance: Rs.";
    cin >> initBalance;
    // Instantiate with user configurations
    BankAccount userAccount(accNum, name, initBalance);
    userAccount.display();

    cout << "Enter amount to deposit: Rs.";
    cin >> depAmount;
    userAccount.deposit(depAmount);
    userAccount.display();
    cout << "Enter amount to withdraw: Rs.";
    cin >> withAmount;
    userAccount.withdraw(withAmount);
    userAccount.display();
    cout << "Press Enter to finish and trigger destructor...";
        cin.ignore(); // Clear buffer 
    cin.get();    // holds screen  
    return 0;
} 