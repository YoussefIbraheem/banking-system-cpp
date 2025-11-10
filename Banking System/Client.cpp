#include "Client.h"
void  Client::set_balance(double balance)
{
    this->balance = balance;
}

double Client::get_balance()
{
    return balance;
}

void Client::deposit(double amount)
{
    this->balance += amount;
}

///check the balnce
void Client::withdraw(double amount)
{
    if (amount <= this->balance) {
       
        this->balance -=  amount;
    }
    else {
        cout << "There is not enough balance \n";
    }
}

void Client::transfer_to(double amount, Client& recipient)
{
    if (amount <= balance)
    {
 
        this->balance -= amount;
        recipient.balance += amount;
    }
    else
    {
        cout << "There is not enough balance \n";
    }
}
//check balance*********
void Client::checkBalance() {
    cout << "Current Balance:" << this->balance << endl;
}

void Client::display_client()
{
    cout << endl;
    cout << "Client " << Person::id << " Information : " << endl;
    Person::display_info();
    cout << "Current Balance : " << Client::balance << endl;
    cout << "-----------------" << endl;
}
