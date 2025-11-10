#pragma once
#include <iostream>
#include "Person.h"
using namespace std;
class Client : public Person
{
protected:
    double balance;
public:
    Client() {}
    Client(string name, string password, double balance) : Person(name, password)
    {

        set_balance(balance);
    }

    void set_balance(double balance);
    double get_balance();
    void deposit(double amount);
    void withdraw(double amount);
    void transfer_to(double amount, Client& recipient);
    void checkBalance();
    void display_client();
  
};

extern vector<Client> allClients;
extern vector<Client>::iterator cltitr;
