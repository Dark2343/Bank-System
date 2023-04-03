#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <vector>

using namespace std;

class BankAccount
{
private:
    string accountID;
    int balance;

protected:
    class Client* user;     // Pointer to Client
    void setID(){
        id++;
        accountID = "FCAI-" + to_string(id);
    }

public:

    static int id;

    BankAccount(){ //-V730
        this->balance = 0;
    };

    BankAccount(int Balance){ //-V730
        this->balance = Balance;
        setID();
    };

    void setClient(Client* User){
        this->user = User;
    }

    Client* getClient(){
        return this->user;
    }

    virtual void setBalance(int Balance){
        this->balance = Balance;
    }

    virtual int getBalance(){
        return this->balance;
    }

    virtual string getID(){
        return this->accountID;
    }

    virtual void withdraw(int Balance){

        if (Balance <= this->balance)
        {
            this->balance -= Balance;
            cout << "Successfully withdrawn " << Balance << " EGP\n";
            cout << "Current balance is now: " << this->balance <<" EGP\n";
        }
        else{
            cout << "Insufficient balance, Unable to withdraw\n";
        }
        
    }

    virtual void deposit(int Balance){
        
        this->balance += Balance;
        cout << "Successfully deposited " << Balance << " EGP\n";
        cout << "Current balance is now: " << this->balance <<" EGP\n";
        
    }

};

int BankAccount::id = 0;

class SavingsBankAccount: public BankAccount
{
private:
    int balance;
    int minimumBalance = 1000;
public:
    
    SavingsBankAccount(int Balance){
        this->balance = Balance;
        setID();
    };

    void setBalance(int Balance){
        this->balance = Balance;
    }

    int getBalance(){
        return this->balance;
    }

    void withdraw(int Balance){

        if (this->balance - Balance >= minimumBalance)
        {
            this->balance -= Balance;
            cout << "Successfully withdrawn " << Balance << " EGP\n";
            cout << "Current balance is now: " << this->balance <<" EGP\n";
        }
        else{
            cout << "Sorry withdrawn amount would make current balance below 1000 EGP\n";
        }
        
    }

    void deposit(int Balance){
        
        if (Balance >= 100)
        {
            this->balance += Balance;
            cout << "Successfully deposited " << Balance << " EGP\n";
            cout << "Current balance is now: " << this->balance <<" EGP\n";
        }

        else{
            cout << "Sorry deposited amount must be 100 EGP or more\n";
        }
        
    }
};

class Client
{
private:
    string name;
    string address;
    string phoneNumber;
    string accountType;
    class BankAccount* account;     // Pointer to bank account

public:
    Client(string Name, string Address, string PhoneNumber){ //-V730
        swap(name, Name);
        swap(address, Address);
        swap(phoneNumber, PhoneNumber);
    };

    void setAccount(BankAccount* Account){
        this->account = Account;
    }

    BankAccount* getAccount(){
        return account;
    }

    string getName(){
        return name;
    }

    string getAddress(){
        return address;
    }

    string getPhone(){
        return phoneNumber;
    }

    void setType(char type){

        if (type == '1')
        {
            accountType = "(Basic)";
        }
        else if (type == '2')
        {
            accountType = "(Savings)";
        }
        
    }

    string getType(){
        return accountType;
    }

};
