#pragma once

#include "Person.h"
#include "Client.h"
#include "../utils/Validation.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee : public Person
{
private:
    double salary;

protected:
    static inline int numberOfEmployees = 22000;

public:
    Employee() : Person() {}
    Employee(string name, string password, double salary)
        : Person(name, password)
    {
        this->setId(++numberOfEmployees);
        setSalary(salary);
    }

    void generateId()
    {
        this->setId(++numberOfEmployees);
    }

    double getSalary() { return salary; }

    bool setSalary(double salary)
    {
        if (Validation::salaryIsValid(salary))
        {
            this->salary = salary;
            return true;
        }
        return false;
    }

    void display()
    {
        Person::display();
        cout << "Salary: " << salary << endl;
    }

    void addClient(Client *client)
    {
        Client::AllClients.push_back(client);
    }

    Client *searchClient(int id)
    {
        for (auto client : Client::AllClients)
        {
            if (client->getId() == id)
            {
                return client;
            }
        }
        return nullptr;
    }

    bool listClient(int id)
    {
        Client *client = searchClient(id);
        if (client != nullptr)
        {
            client->display();
            return true;
        }
        return false;
    }

    bool editClient(int id, string name, string password, double balance)
    {
        Client *client = searchClient(id);
        if (client != nullptr)
            if (client->setName(name) && client->setPassword(password) && client->setBalance(balance))
                return true;
        return false;
    }

    static inline vector<Employee *> AllEmployees = {};
};