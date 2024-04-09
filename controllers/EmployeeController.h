#pragma once
#include "../utils/FileManager.h"

class EmployeeController
{
private:
    static inline Admin *_Admin = new Admin();

public:
    static void printEmployeeMenu()
    {
        system("clear");
        cout << "\t\t\t\t\t\tEmployee Functions\n";
        cout << "1-Add New Client\n";
        cout << "2-List Of All Clients\n";
        cout << "3-Search For A Client\n";
        cout << "4-Edit Client\n";
        cout << "5-Display\n";
        cout << "6-Update Password\n";
        cout << "7-Logout\n";
        cout << endl;
    }
    static void newClient(Employee *employee)
    {
        Client *client = new Client();
        string name, password;
        double balance;
        int id;
        cout << "Enter New Client\n\n";
        cout << "Name : ";
        cin >> name;
        cout << "Password : ";
        cin >> password;
        cout << "Balance : ";
        cin >> balance;
        if (client->setName(name) && client->setPassword(password) && client->setBalance(balance))
        {
            client->generateId();
            employee->addClient(client);
            cout << "\n*******************\n";
            cout << "Client Accepted\n";
            cout << "*******************\n\n";
        }
        else
        {
            cout << "\n**************************\n";
            cout << "Client Not Accepted\n";
            cout << "**************************\n\n";
        }
    }

    static void listAllClients(Employee *employee)
    {
        for (auto c : Client::AllClients)
            employee->listClient(c->getId());
    }

    static void searchForClient(Employee *employee)
    {
        int id;
        cout << "Client Id : ";
        cin >> id;
        Client *client = employee->searchClient(id);
        if (client == NULL)
        {
            cout << "\n**************************\n";
            cout << "Client Not Found\n";
            cout << "**************************\n\n";
        }
        else
        {
            client->display();
        }
    }

    static void editClientInfo(Employee *employee)
    {
        int choice, id;
        string name, password;
        double balance;

        cout << "Enter Id : ";
        cin >> id;

        Client *client = employee->searchClient(id);

        if (client != nullptr)
        {
            cout << "\nWhat You Want To Edit : \n";
            cout << "1-All data\n";
            cout << "2-Name\n";
            cout << "3-Password\n";
            cout << "4-Balance\n";

            cout << "\nEnter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nEnter New Name : ";
                cin >> name;
                cout << "\nEnter New Password : ";
                cin >> password;
                cout << "\nEnter New balance : ";
                cin >> balance;
                employee->editClient(id, name, password, balance);

                break;
            case 2:
                cout << "\nEnter New Name : ";
                cin >> name;
                password = client->getPassword();
                balance = client->getBalance();
                employee->editClient(id, name, password, balance);
                break;
            case 3:
                cout << "\nEnter New Password : ";
                cin >> password;
                name = client->getName();
                balance = client->getBalance();
                employee->editClient(id, name, password, balance);
                break;
            case 4:
                cout << "\nEnter New Balance : ";
                cin >> balance;
                name = client->getName();
                password = client->getPassword();
                employee->editClient(id, name, password, balance);
                break;
            default:
                cout << "\n*************************************\n";
                cout << "Your Choice Not Found In List\n";
                cout << "*************************************\n\n";
                editClientInfo(employee);
                break;
            }
        }
        else
        {
            cout << "\n************************\n";
            cout << "Client not found\n\n";
            cout << "************************\n\n";
            cout << "\n1 - Try Again\n";
            cout << "2 - Return\n";

            int choice;
            cout << "\nEnter Your Choice : ";
            cin >> choice;

            system("clear");
            if (choice == 1)
            {
                editClientInfo(employee);
            }
            else if (choice == 2)
            {
                printEmployeeMenu();
                employeeOptions(employee);
            }
            else
            {
                cout << "\n*************************************\n";
                cout << "Your Choice Not Found In List\n";
                cout << "*************************************\n\n";

                // a replacement for system("pause") in linux
                string c;
                cin >> c;

                printEmployeeMenu();
                employeeOptions(employee);
            }
        }
    }

    static bool employeeOptions(Employee *employee)
    {
        int choice = 0;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("clear");
            newClient(employee);
            break;
        case 2:
            system("clear");
            listAllClients(employee);
            break;
        case 3:
            system("clear");
            searchForClient(employee);
            break;
        case 4:
            system("clear");
            editClientInfo(employee);
            break;
        case 5:
            system("clear");
            employee->display();
            break;
        case 6:
            system("clear");
            updatePassword(employee);
            break;
        case 7:
            return true;
        default:
            cout << "\nYour Choice Not Found In List\n";
            employeeOptions(employee);
        }
        Back(employee);
        return true;
    }

    static void Back(Employee *employee)
    {
        // a replacement for system("pause") in linux
        string c;
        cin >> c;
        printEmployeeMenu();
        employeeOptions(employee);
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

    static Employee *Login(int id, string password)
    {
        Employee *e = _Admin->searchEmployee(id);

        if (e == NULL)
        {
            cout << "\nIncorrect Id Or Password\n";
            return NULL;
        }
        else
        {
            if (e->getPassword() == password)
            {
                return e;
            }
            else
            {
                cout << "\nIncorrect Id Or Password\n";
                return NULL;
            }
        }
    }
};