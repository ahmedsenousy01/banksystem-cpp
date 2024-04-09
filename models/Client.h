#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Person.h"
#include "../utils/Validation.h"

using namespace std;

class Client : public Person
{
private:
    static inline int numberOfClients = 11000;
    double balance;

public:
    Client() : Person() {}
    Client(string name, string password, double balance)
        : Person(name, password)
    {
        this->setId(++numberOfClients);
        setBalance(balance);
    }

    void generateId()
    {
        this->setId(++numberOfClients);
    }

    double getBalance() { return balance; }

    bool setBalance(double balance)
    {
        if (Validation::balanceIsValid(balance))
        {
            this->balance = balance;
            return true;
        }
        return false;
    }

    void deposit(double amount)
    {
        setBalance(getBalance() + amount);
        cout << "Deposited successfully." << endl;
    }

    void withdraw(double amount)
    {
        setBalance(getBalance() - amount);
        cout << "Withdrawn successfully." << endl;
    }
    void transferTo(double amount, Client &recipient)
    {
        if (amount <= 0)
        {
            cout << "Invalid transfer amount." << endl;
            return;
        }
        if (amount > getBalance())
        {
            cout << "Insufficient balance for transfer." << endl;
        }
        else
        {
            setBalance(getBalance() - amount);
            {
                recipient.setBalance(recipient.getBalance() + amount);
                cout << "Transferred successfully to ."
                     << recipient.getName() << "." << endl;
            }
        }
    }

    void checkBalance()
    {
        cout << "Current balance : " << getBalance() << endl;
    }

    void display()
    {
        Person::display();
        cout << "Balance : " << getBalance() << endl;
    }

    static inline vector<Client *> AllClients = {};
};
