#pragma once
#include "EmployeeController.h"

class AdminController : public EmployeeController
{
public:
    static void printAdminMenu()
    {
        system("clear");
        cout << "\t\t\t\t\t\tAdmin Functions\n";
        cout << "1-Add New Client\n";
        cout << "2-List Of All Clients\n";
        cout << "3-Search For A Client\n";
        cout << "4-Edit Client\n";
        cout << "5-Add New Employee\n";
        cout << "6-List Of All Employee\n";
        cout << "7-Search For A Employee\n";
        cout << "8-Edit Employee\n";
        cout << "9-Display\n";
        cout << "10-Update Password\n";
        cout << "11-Logout\n";
        cout << endl;
    }

    static void newEmployee(Admin *admin)
    {
        Employee *employee = new Employee();
        string name, password;
        double salary;
        int id;
        cout << "Enter New Employee\n\n";
        cout << "Name : ";
        cin >> name;
        cout << "Password : ";
        cin >> password;
        cout << "Salary : ";
        cin >> salary;
        if (employee->setName(name) && employee->setPassword(password) && employee->setSalary(salary))
        {
            employee->generateId();
            admin->addEmployee(employee);
            cout << "\n*******************\n";
            cout << "Employee Accepted\n";
            cout << "*******************\n\n";
        }
        else
        {
            cout << "\n**************************\n";
            cout << "Employee Not Accepted\n";
            cout << "**************************\n\n";
        }
    }

    static void listAllEmployee(Admin *admin)
    {
        for (auto e : Employee::AllEmployees)
            admin->listEmployee(e->getId());
    }

    static void searchForEmployee(Admin *admin)
    {
        int id;
        cout << "Employee Id : ";
        cin >> id;
        Employee *employee = admin->searchEmployee(id);
        if (employee == NULL)
        {
            cout << "\n**************************\n";
            cout << "Employee Not Found\n";
            cout << "**************************\n\n";
        }
        else
        {
            employee->display();
        }
    }

    static void editEmployeeInfo(Admin *admin)
    {
        int choice;
        int id;
        string name, password;
        double salary;
        cout << "Enter Id : ";
        cin >> id;

        Employee *employee = admin->searchEmployee(id);

        if (employee != nullptr)
        {
            cout << "\nWhat You Want To Edit : \n";
            cout << "1-All data\n";
            cout << "2-Name\n";
            cout << "3-Password\n";
            cout << "4-Salary\n";

            cout << "\nEnter Your Choice : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nEnter New Name : ";
                cin >> name;
                cout << "\nEnter New Password : ";
                cin >> password;
                cout << "\nEnter New Salary : ";
                cin >> salary;
                admin->editEmployee(id, name, password, salary);
                break;
            case 2:
                cout << "\nEnter New Name : ";
                cin >> name;
                password = employee->getPassword();
                salary = employee->getSalary();
                admin->editEmployee(id, name, password, salary);
                break;
            case 3:
                cout << "\nEnter New Password : ";
                cin >> password;
                name = employee->getName();
                salary = employee->getSalary();
                admin->editEmployee(id, name, password, salary);
                break;
            case 4:
                cout << "\nEnter New Salary : ";
                cin >> salary;
                name = employee->getName();
                password = employee->getPassword();
                admin->editEmployee(id, name, password, salary);
                break;
            default:
                cout << "\n*************************************\n";
                cout << "Your Choice Not Found In List\n";
                cout << "*************************************\n\n";
                editEmployeeInfo(admin);
                break;
            }
        }
        else
        {
            cout << "\n************************\n";
            cout << "Employee not found\n\n";
            cout << "************************\n\n";
            cout << "\n1 - Try Again\n";
            cout << "2 - Return\n";

            int choice;
            cout << "\nEnter Your Choice : ";
            cin >> choice;

            system("clear");
            if (choice == 1)
            {
                editEmployeeInfo(admin);
            }
            else if (choice == 2)
            {
                printAdminMenu();
                AdminOptions(admin);
            }
            else
            {
                cout << "\nYour Choice Not Found In List\n\n";
                // a replacement for system("pause") in linux
                string c;
                cin >> c;
                printAdminMenu();
                AdminOptions(admin);
            }
        }
    }
    static bool AdminOptions(Admin *admin)
    {
        int choice = 0;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system("clear");
            newClient(admin);
            break;
        case 2:
            system("clear");
            listAllClients(admin);
            break;
        case 3:
            system("clear");
            searchForClient(admin);
            break;
        case 4:
            system("clear");
            editClientInfo(admin);
            break;
        case 5:
            system("clear");
            newEmployee(admin);
            break;
        case 6:
            system("clear");
            listAllEmployee(admin);
            break;
        case 7:
            system("clear");
            searchForEmployee(admin);
            break;
        case 8:
            system("clear");
            editEmployeeInfo(admin);
            break;
        case 9:
            system("clear");
            admin->display();
            break;
        case 10:
            system("clear");
            updatePassword(admin);
            break;
        case 11:
            return true;
        default:
            cout << "\n*************************************\n";
            cout << "Your Choice Not Found In List\n";
            cout << "*************************************\n\n";
            AdminOptions(admin);
        }
        Back(admin);
        return true;
    }

    static void Back(Admin *admin)
    {
        // a replacement for system("pause") in linux
        string c;
        cin >> c;
        printAdminMenu();
        AdminOptions(admin);
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

    static Admin *searchAdmin(int id)
    {
        for (auto a : Admin::AllAdmins)
        {
            if (a->getId() == id)
            {
                return a;
            }
        }
        return nullptr;
    }

    static Admin *Login(int id, string password)
    {
        Admin *a = searchAdmin(id);

        if (a == nullptr)
        {
            cout << "\n****************************\n";
            cout << "Incorrect Id Or Password\n";
            cout << "****************************\n\n";
            return nullptr;
        }
        else
        {
            if (a->getPassword() == password)
            {
                return a;
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