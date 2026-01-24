#include <iostream>
#include <string>
using namespace std;

struct BankEmployee {
    string name;
    int account_no;
    double balance;

    // Function to display employee details
    void displayDetails() const {
        cout << "\nEmployee Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << account_no << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Function to deposit an amount
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit Successful. Updated balance: $" << balance << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw an amount
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal Successful. Updated balance: $" << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            cout << "Invalid withdrawal amount!" << endl;
        }
    }
};

int main() {
    BankEmployee emp;
    double amount;
    int choice;

    cout << "Enter employee's name: ";
    getline(cin, emp.name);

    cout << "Enter account number: ";
    cin >> emp.account_no;

    cout << "Enter initial balance: $";
    cin >> emp.balance;

    emp.displayDetails();

    do {
        cout << "\nChoose an operation:" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        cout << "3. Display Details" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: $";
                cin >> amount;
                emp.deposit(amount);
                break;

            case 2:
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                emp.withdraw(amount);
                break;

            case 3:
                emp.displayDetails();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

