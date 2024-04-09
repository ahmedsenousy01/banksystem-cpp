#pragma once
#include "../models/Client.h"
#include "../models/Employee.h"

class ClientController
{
private:
    static inline Employee *_Employee = new Employee();

public:
    static void printClientMenu()
    {
        system("clear");
        cout << "\t\t\t\t\t\tClient Functions\n";
        cout << "1-Deposit\n";
        cout << "2-Withdraw\n";
        cout << "3-transferTo\n";
        cout << "4-checkBalance\n";
        cout << "5-Display\n";
        cout << "6-Update Password\n";
        cout << "7-Logout\n";
        cout << endl;
    }

    static bool clientOptions(Client *_Client)
    {
        int choice = 0;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("clear");
            double amount = 1500;
            cout << "Enter Amount To Deposit : ";
            cin >> amount;
            _Client->deposit(amount);
            break;
        }
        case 2:
        {
            system("clear");
            double amount = 1500;
            cout << "Enter Amount To Withdraw : ";
            cin >> amount;
            _Client->withdraw(amount);
            break;
        }
        case 3:
        {
            system("clear");
            double amount = 1500;
            Client *otherClient;
            int id = 0;
            cout << "Enter Client Id you want Transfer to : ";
            cin >> id;
            otherClient = _Employee->searchClient(id);
            cout << "Enter Amount To transferTo : ";
            cin >> amount;
            if (otherClient != nullptr)
            {
                _Client->transferTo(amount, *otherClient);
            }
            else
            {
                cout << "\n******************************************\n";
                cout << "The Other Client Not Found In System\n";
                cout << "******************************************\n\n";
            }
            break;
        }
        case 4:
        {
            system("clear");
            _Client->checkBalance();
            break;
        }
        case 5:
        {
            system("clear");
            _Client->display();
            break;
        }
        case 6:
        {
            system("clear");
            updatePassword(_Client);
            break;
        }
        case 7:
        {
            return true;
        }
        default:
        {
            cout << "\n*************************************\n";
            cout << "Your Choice Not Found In List\n";
            cout << "*************************************\n\n";
            clientOptions(_Client);
        }
        }
        Back(_Client);
        return true;
    }

    static void Back(Client *_Client)
    {
        // a replacement for system("pause") in linux
        string c;
        cin >> c;

        printClientMenu();
        clientOptions(_Client);
    }

    static void updatePassword(Person *person)
    {
        string password;
        cout << "Enter New Password : ";
        cin >> password;
        if (person->setPassword(password))
        {
            cout << "\n*********************\n";
            cout << "Password Updated \n";
            cout << "*********************\n\n";
        }
    }

    static Client *login(int id, string password)
    {
        Client *c = _Employee->searchClient(id);
        if (c == nullptr)
        {
            cout << "\n****************************\n";
            cout << "Incorrect Id Or Password\n";
            cout << "****************************\n\n";
            return nullptr;
        }
        else
        {
            if (c->getPassword() == password)
            {
                return c;
            }
            else
            {
                cout << "\n****************************\n";
                cout << "Incorrect Id Or Password\n";
                cout << "****************************\n\n";
                return nullptr;
            }
        }
    }
};