#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

using namespace std;

class BankAccount
{
private:
    string ownerName;
    int accountNumber = 0;
    double balance = 0.0;
    bool accountCreated = false;

    void clearInput()
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

public:
    bool exists() const
    {
        return accountCreated;
    }

    void createAccount()
    {
        cout << "\nCreate Account\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        do
        {
            cout << "Enter your full name: ";
            getline(cin, ownerName);

            if (ownerName.empty())
            {
                cout << "Name cannot be empty. Try again.\n";
            }

        } while (ownerName.empty());

        while (true)
        {
            cout << "Enter account number: ";

            if (cin >> accountNumber && accountNumber > 0)
            {
                break;
            }

            cout << "Invalid account number. Enter a positive number.\n";
            clearInput();
        }

        while (true)
        {
            cout << "Enter initial balance: ";

            if (cin >> balance && balance >= 0)
            {
                break;
            }

            cout << "Invalid balance. It cannot be negative.\n";
            clearInput();
        }

        accountCreated = true;
        cout << "Account created successfully!\n";
    }

    void showAccount() const
    {
        if (!accountCreated)
        {
            cout << "\nPlease create an account first.\n";
            return;
        }

        cout << "\nAccount Information\n";
        cout << "Name: " << ownerName << '\n';
        cout << "Account Number: " << accountNumber << '\n';
        cout << "Balance: " << balance << " EGP\n";
    }

    void deposit()
    {
        if (!accountCreated)
        {
            cout << "\nPlease create an account first.\n";
            return;
        }

        double amount;

        cout << "\nEnter amount to deposit: ";

        if (!(cin >> amount) || amount <= 0)
        {
            cout << "Invalid amount.\n";
            clearInput();
            return;
        }

        balance += amount;

        cout << "Deposit successful!\n";
        cout << "New balance: " << balance << " EGP\n";
    }

    void withdraw()
    {
        if (!accountCreated)
        {
            cout << "\nPlease create an account first.\n";
            return;
        }

        double amount;

        cout << "\nEnter amount to withdraw: ";

        if (!(cin >> amount) || amount <= 0)
        {
            cout << "Invalid amount.\n";
            clearInput();
            return;
        }

        if (amount > balance)
        {
            cout << "Insufficient balance.\n";
            return;
        }

        balance -= amount;

        cout << "Withdrawal successful!\n";
        cout << "New balance: " << balance << " EGP\n";
    }

    void checkBalance() const
    {
        if (!accountCreated)
        {
            cout << "\nPlease create an account first.\n";
            return;
        }

        cout << "\nYour current balance is: "
             << balance << " EGP\n";
    }
};

int getChoice()
{
    int choice;

    while (true)
    {
        cout << "\nEnter your choice: ";

        if (cin >> choice && choice >= 1 && choice <= 6)
        {
            return choice;
        }

        cout << "Invalid choice. Please enter a number from 1 to 6.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    BankAccount account;
    int choice;

    cout << fixed << setprecision(2);

    do
    {
        cout << "\nBank System\n";
        cout << "1. Create Account\n";
        cout << "2. Show Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Check Balance\n";
        cout << "6. Exit\n";

        choice = getChoice();
