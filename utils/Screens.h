#pragma once
#include "../controllers/ClientController.h"
#include "../controllers/EmployeeController.h"
#include "../controllers/AdminController.h"
#include "../utils/FileManager.h"

class Screens
{
private:
    static inline string name = "";

public:
    static void loginOptions()
    {
        cout << "\t\t\t\t\t\tLogin As\n";
        cout << "1 - Client\n\n";
        cout << "2 - Employee\n\n";
        cout << "3 - Admin\n\n";
        cout << "4 - Exit\n\n";
    }
    static int loginAs()
    {
        int choice;
        cout << "Login As : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
        case 3:
            return 3;
            break;
        case 4:
            return 4;
            break;
        default:
            Invalid(choice);
            break;
        }
        return -1;
    }
    static void Invalid(int c)
    {
        cout << "\n\n*************************************\n";
        cout << "Your Choice Not Found In List\n";
        cout << "*************************************\n\n";
        loginAs();
    }
    static void LoginClient()
    {
        cout << "\t\t\t\t\t\tLogin Client Page\n";
        int id;
        string password;
        cout << "Id : ";
        cin >> id;
        cout << "Password : ";
        cin >> password;
        Client *client = ClientController::login(id, password);
        if (client != NULL)
        {
            ClientController::printClientMenu();
            if (ClientController::clientOptions(client))
            {
                system("clear");
                name = client->getName();
                loginOptions();
                loginScreen(loginAs());
            }
        }
        else
        {
            cout << "\n1 - Try Again\n";
            cout << "2 - Return\n";
            int choice;
            cout << "\nEnter Your Choice : ";
            cin >> choice;
            system("clear");
            if (choice == 1)
            {
                LoginClient();
            }
            else if (choice == 2)
            {
                system("clear");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout << "\n\n*************************************\n";
                cout << "Your Choice Not Found In List\n";
                cout << "*************************************\n\n";
                // a replacement for system("pause") in linux
                string c;
                cin >> c;

                system("clear");
                loginOptions();
                loginScreen(loginAs());
            }
        }
    }
    static void LoginEmployee()
    {
        cout << "\t\t\t\t\t\tLogin Employee Page\n";
        int id;
        string password;
        cout << "Id : ";
        cin >> id;
        cout << "Password : ";
        cin >> password;
        Employee *employee = EmployeeController::Login(id, password);
        if (employee != NULL)
        {
            EmployeeController::printEmployeeMenu();
            if (EmployeeController::employeeOptions(employee))
            {
                system("clear");
                name = employee->getName();
                loginOptions();
                loginScreen(loginAs());
            }
        }
        else
        {
            cout << "\n1 - Try Again\n";
            cout << "2 - Return\n";
            int choice;
            cout << "\nEnter Your Choice : ";
            cin >> choice;
            if (choice == 1)
            {
                LoginEmployee();
            }
            else if (choice == 2)
            {
                system("clear");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout << "\n\n*************************************\n";
                cout << "Your Choice Not Found In List\n";
                cout << "*************************************\n\n";
                // a replacement for system("pause") in linux
                string c;
                cin >> c;

                system("clear");
                loginOptions();
                loginScreen(loginAs());
            }
        }
    }
    static void LoginAdmin()
    {
        cout << "\t\t\t\t\t\tLogin Admin Page\n";
        int id;
        string password;
        cout << "Id : ";
        cin >> id;
        cout << "Password : ";
        cin >> password;

        Admin *admin = AdminController::Login(id, password);
        if (admin != NULL)
        {
            AdminController::printAdminMenu();
            if (AdminController::AdminOptions(admin))
            {
                system("clear");
                name = admin->getName();
                loginOptions();
                loginScreen(loginAs());
            }
        }
        else
        {
            cout << "\n1 - Try Again\n";
            cout << "2 - Return\n";
            int choice;
            cout << "\nEnter Your Choice : ";
            cin >> choice;
            if (choice == 1)
            {
                LoginAdmin();
            }
            else if (choice == 2)
            {
                system("clear");
                loginOptions();
                loginScreen(loginAs());
            }
            else
            {
                cout << "\n\n*************************************\n";
                cout << "Your Choice Not Found In List\n";
                cout << "*************************************\n\n";
                // a replacement for system("pause") in linux
                string c;
                cin >> c;

                system("clear");
                loginOptions();
                loginScreen(loginAs());
            }
        }
    }
    static void loginScreen(int c)
    {
        switch (c)
        {
        case 1:
            system("clear");
            LoginClient();
            break;
        case 2:
            system("clear");
            LoginEmployee();
            break;
        case 3:
            system("clear");
            LoginAdmin();
            break;
        case 4:
            SayThank();
            FileManager::saveData();
        }
    }
    static void SayThank()
    {
        system("clear");
        system("Color f4");
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "\t\t    ########  ##    ##   ######   ####    ##  ##   ##     ##    ##     ##     ##    ##\n";
        cout << "\t\t       ##     ##    ##  ##    ##  ## ##   ##  ##  ##       ##  ##    ##  ##   ##    ##\n";
        cout << "\t\t       ##     ########  ########  ##  ##  ##  ## #           ##     ##    ##  ##    ##\n";
        cout << "\t\t       ##     ##    ##  ##    ##  ##   ## ##  ##  ##         ##      ##  ##    ##  ##\n";
        cout << "\t\t       ##     ##    ##  ##    ##  ##    ####  ##   ##        ##        ##        ##\n";
        system("clear");
    }
    static void BankName()
    {
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "\t\t      ##     ##      ######      ##     ##     #######   ########  ####    ##  ##   ##\n";
        cout << "\t\t      ###   ###     ##    ##     ###   ###     ##    ##  ##    ##  ## ##   ##  ##  ##\n";
        cout << "\t\t      ## # # ##     ########     ## # # ##     #######   ########  ##  ##  ##  ## #\n";
        cout << "\t\t      ##  #  ##     ##    ##     ##  #  ##     ##    ##  ##    ##  ##   ## ##  ##  ##\n";
        cout << "\t\t      ##     ##  @  ##    ##  @  ##     ##     #######   ##    ##  ##    ####  ##   ##\n   ";
    }

    static void Welcome()
    {
        cout << "\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t##       ##   ######    ##      #######  ########   ##     ##   ######\n";
        cout << "\t\t\t##   #   ##   ##        ##      ##       ##    ##   ###   ###   ##\n";
        cout << "\t\t\t##  # #  ##   ######    ##      ##       ##    ##   ## # # ##   ######\n";
        cout << "\t\t\t## #   # ##   ##        ##      ##       ##    ##   ##  #  ##   ##\n";
        cout << "\t\t\t###     ###   ######    ######  #######  ########   ##     ##   ######\n";
    }

    static void runApp()
    {
        BankName();
        // a replacement for system("pause") in linux
        string c;
        cin >> c;

        system("clear");
        Welcome();
        // a replacement for system("pause") in linux
        cin >> c;

        system("clear");
        FileManager::getData();
        loginOptions();
        loginScreen(loginAs());
    }
};