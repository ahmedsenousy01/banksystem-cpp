#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Admin.h"

#include "Parser.h"

using namespace std;

class FileManager
{
public:
    static void addClient(Client *c)
    {
        fstream file;
        file.open("db/clients.txt", ios::app);
        file << c->getName() << "&" << c->getPassword() << "&" << c->getBalance() << endl;
        file.close();
    }

    static void addEmployee(Employee *e)
    {
        fstream file;
        file.open("db/employees.txt", ios::app);
        file << e->getName() << "&" << e->getPassword() << "&" << e->getSalary() << endl;
        file.close();
    }

    static void addAdmin(Admin *a)
    {
        fstream file;
        file.open("db/admins.txt", ios::app);
        file << a->getName() << "&" << a->getPassword() << "&" << a->getSalary() << endl;
        file.close();
    }

    static void getClients()
    {
        fstream file;
        file.open("db/clients.txt", ios::in);

        string line;
        while (getline(file, line))
        {
            Client::AllClients.push_back(Parser::parseToClient(line));
        }

        file.close();
    }

    static void getEmployees()
    {
        fstream file;
        file.open("db/employees.txt", ios::in);

        string line;
        while (getline(file, line))
        {
            Employee::AllEmployees.push_back(Parser::parseToEmployee(line));
        }

        file.close();
    }

    static void getAdmins()
    {
        fstream file;
        file.open("db/admins.txt", ios::in);

        string line;
        while (getline(file, line))
        {
            Admin::AllAdmins.push_back(Parser::parseToAdmin(line));
        }

        file.close();
    }

    static void saveClients()
    {
        for (auto c : Client::AllClients)
        {
            addClient(c);
        }
    }

    static void saveEmployees()
    {
        for (auto e : Employee::AllEmployees)
        {
            addEmployee(e);
        }
    }

    static void saveAdmins()
    {
        for (auto a : Admin::AllAdmins)
        {
            addAdmin(a);
        }
    }

    static void getData()
    {
        getClients();
        getEmployees();
        getAdmins();
    }

    static void saveData()
    {
        saveClients();
        saveEmployees();
        saveAdmins();
    }

    static void removeData()
    {
        remove("db/clients.txt");
        remove("db/employees.txt");
        remove("db/admins.txt");
    }
};
