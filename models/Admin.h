#pragma once

#include <iostream>
#include <vector>

#include "Employee.h"

using namespace std;

class Admin : public Employee
{
private:
    static inline int numberOfAdmins = 33000;
    double Salary;

public:
    Admin() : Employee() {}
    Admin(string Name, string Password, double Salary)
        : Employee(Name, Password, Salary)
    {
        this->setId(++numberOfAdmins);
        Employee::numberOfEmployees--;
    }

    void generateId()
    {
        this->setId(++numberOfAdmins);
    }

    void addEmployee(Employee *e)
    {
        Employee::AllEmployees.push_back(e);
    }

    Employee *searchEmployee(int id)
    {
        for (auto e : Employee::AllEmployees)
        {
            if (e->getId() == id)
            {
                return e;
            }
        }
        return nullptr;
    }

    bool listEmployee(int id)
    {
        Employee *e = searchEmployee(id);
        if (e != nullptr)
        {
            e->display();
            return true;
        }
        return false;
    }

    bool editEmployee(int id, string name, string password, double balance)
    {
        Employee *e = searchEmployee(id);
        if (e != nullptr)
            if (e->setName(name) && e->setPassword(password) && e->setSalary(balance))
                return true;
        return false;
    }

    static inline vector<Admin *> AllAdmins = {};
};
