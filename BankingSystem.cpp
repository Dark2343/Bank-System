#include "BankSystem.h"

int main(){

    Client** customerArray = new Client*[1];
    BankAccount** accountArray = new BankAccount*[1];
    SavingsBankAccount** savingsArray = new SavingsBankAccount*[1];
    map<int, BankAccount*> accountsMap;
    char choice;

    cout << "Welcome to FCAI Banking Application\n";
    while (true)
    {
        cout << "1. Create a New Account\n2. List Clients and Accounts\n";
        cout << "3. Withdraw Money\n4. Deposit Money\n5. Exit\n";
        cout << "Please enter your choice\n";
        cin >> choice;
        cin.ignore();

        if (choice == '1')
        {
            char type;
            string Name, Address, Phone;

            cout << "\nPlease enter your name: ";
            getline(cin, Name);
            
            cout << "Please enter your address: ";
            getline(cin, Address);
            
            cout << "Please enter your phone number: ";
            getline(cin,Phone);

            customerArray[0] = new Client (Name, Address, Phone);

            type:;
            cout << "\nWhat type of account would you like? (1) Basic (2) Saving: ";
            cin >> type;

            if (type == '1')
            {
                int balance;
                customerArray[0]->setType(type);

                cout << "Please enter your starting balance: ";
                cin >> balance;
                
                accountArray[0] = new BankAccount(balance);
                accountArray[0]->setClient(customerArray[0]);
                customerArray[0]->setAccount(accountArray[0]);

                accountsMap[BankAccount::id] = accountArray[0];

                cout << "\nAn account was created with ID: " << accountArray[0]->getID() <<  ", and starting balance " << accountArray[0]->getBalance() << " L.E.\n";
                cout << "-------------------------------------------------------------------\n";
            }

            // Savings account
            else if (type == '2')
            {
                int balance;
                customerArray[0]->setType(type);

                setAmount:;
                cout << "Please enter your starting balance: ";
                cin >> balance;

                if (balance < 1000)
                {
                    cout << "Sorry a savings account must have minimum balance of 1000 EGP\n";
                    goto setAmount;
                }
                
                else{
                    savingsArray[0] = new SavingsBankAccount(balance);
                    savingsArray[0]->BankAccount::setClient(customerArray[0]);
                    customerArray[0]->setAccount(savingsArray[0]);

                    accountsMap[BankAccount::id] = savingsArray[0];

                    cout << "\nAn account was created with ID: " << savingsArray[0]->getID() <<  ", and starting balance " << savingsArray[0]->getBalance() << " L.E.\n";
                    cout << "-------------------------------------------------------------------\n";
                }
                
            }
            
            else{
                cout << "Incorrect input, please try again\n";
                goto type;
            }
        }

        // Lists Clients and accounts
        else if (choice == '2')
        {
            for (int i = 1; i <= BankAccount::id; i++)
            {
                cout << "----------" <<  accountsMap[i]->getClient()->getName() << "----------" << "\n";
                cout << "Address: " <<  accountsMap[i]->getClient()->getAddress() << "\n";
                cout << "Phone Number: " <<  accountsMap[i]->getClient()->getPhone() << "\n";
                cout << "Account ID: " <<  accountsMap[i]->getID() << " " << accountsMap[i]->getClient()->getType() << "\n";
                cout << "Account Balance: " <<  accountsMap[i]->getBalance() << "\n";
            }   

            cout << "-------------------------------------------------------------------\n";
            
        }

        // Withdraw
        else if (choice == '3')
        {
            int balance, id;
 
            cout << "\nPlease Enter Account ID number: ";
            cin >> id;
            
            if (id > BankAccount::id || id <= 0){
                cout << "Incorrect ID number\n";
            }

            else{
                cout << "\nAccount ID: " << accountsMap[id]->getID();
                cout << "\nAccount Balance: " << accountsMap[id]->getBalance();
                cout << "\nAccount Type: " << accountsMap[id]->getClient()->getType();

                cout << "\nEnter how much you would like to withdraw\n";
                cin >> balance;

                accountsMap[id]->withdraw(balance);
                cout << "-------------------------------------------------------------------\n";
            }
        }

        // Deposit
        else if (choice == '4')
        {
            int balance, id;
 
            cout << "\nPlease Enter Account ID number: ";
            cin >> id;
            
            if (id > BankAccount::id || id <= 0){
                cout << "Incorrect ID number\n";
            }

            else{
                cout << "\nAccount ID: " << accountsMap[id]->getID();
                cout << "\nAccount Balance: " << accountsMap[id]->getBalance();
                cout << "\nAccount Type: " << accountsMap[id]->getClient()->getType();

                cout << "\nPlease enter how much you would like to deposit\n";
                cin >> balance;

                accountsMap[id]->deposit(balance);
                cout << "-------------------------------------------------------------------\n";
            }
            
        }

        // Exits the program
        else if (choice == '5')
        {
            cout << "Thank you for choosing FCAI Banking System\n";
            cout << "Your money is safe with us....\n";
            exit(0);
        }
        

        else{
            cerr << "Sorry incorrect input, Please try again\n\n";
        }
    }
}
