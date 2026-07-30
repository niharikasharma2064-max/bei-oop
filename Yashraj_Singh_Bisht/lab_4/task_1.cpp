#include <iostream>
#include <string>

using namespace std;

class ATM {
private:
    string ownerName;
    float balance;
    
    // global tracking variables
    static int totalTransactions;
    static float totalMoneyMoved;

public:
    // constructor
    ATM(string name, float init_balance) {
        ownerName = name;
        balance = init_balance;
    }

    void deposit(float amount) {
        if(amount > 0) {
            balance += amount;
            totalTransactions++;
            totalMoneyMoved += amount;
            cout << ownerName << " deposited: " << amount << endl;
        } else {
            cout << "Error: Invalid deposit." << endl;
        }
    }

    void withdraw(float amount) {
        if(amount > 0 && amount <= balance) {
            balance -= amount;
            totalTransactions++;
            totalMoneyMoved += amount;
            cout << ownerName << " withdrew: " << amount << endl;
        } else {
            cout << ownerName << " tried to withdraw " << amount << " but failed." << endl;
        }
    }

    void showBalance() {
        cout << ownerName << " has a balance of: " << balance << endl;
    }

    // static function to print the stats
    static void showStats() {
        cout << endl << "=== ATM STATS ===" << endl;
        cout << "Total Transactions: " << totalTransactions << endl;
        cout << "Total Money Moved: " << totalMoneyMoved << endl;
        cout << "=================" << endl << endl;
    }
};

// must initialize static members outside class
int ATM::totalTransactions = 0;
float ATM::totalMoneyMoved = 0.0;

int main() {
    // testing with two objects
    ATM user1("ramu", 1000.0);
    ATM user2("shayamu", 500.0);

    user1.showBalance();
    user2.showBalance();
    cout << endl;

    // do some transactions
    user1.deposit(200.0);
    user1.withdraw(150.0);
    
    user2.deposit(300.0);
    user2.withdraw(50.0);
    cout << endl;

    // final check
    user1.showBalance();
    user2.showBalance();

    // print combined stats
    ATM::showStats();

    return 0;
}
