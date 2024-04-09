#pragma once

#include <iostream>
#include <string>

#include "../utils/Validation.h"

using namespace std;

class Person
{
private:
    int id;
    string name;
    string password;

protected:
    void setId(int id) { this->id = id; }

public:
    Person() {}
    Person(string name, string password)
    {
        setName(name);
        setPassword(password);
    }

    int getId() { return id; }
    string getName() { return name; }
    string getPassword() { return password; }

    bool setName(string name)
    {
        if (Validation::nameIsValid(name))
        {
            this->name = name;
            return true;
        }
        return false;
    }
    bool setPassword(string password)
    {
        if (Validation::passIsValid(password))
        {
            this->password = password;
            return true;
        }
        return false;
    }

    void display()
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Password: " << password << endl;
    }
};