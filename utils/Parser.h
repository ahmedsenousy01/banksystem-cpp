#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Admin.h"

using namespace std;

class Parser
{
public:
    static vector<string> split(string line)
    {
        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (getline(ss, token, '&'))
        {
            tokens.push_back(token);
        }
        return tokens;
    }

    static Client *parseToClient(string line)
    {
        vector<string> tokens = split(line);
        return new Client(tokens[0], tokens[1], stod(tokens[2]));
    }

    static Employee *parseToEmployee(string line)
    {
        vector<string> tokens = split(line);
        return new Employee(tokens[0], tokens[1], stod(tokens[2]));
    }

    static Admin *parseToAdmin(string line)
    {
        vector<string> tokens = split(line);
        return new Admin(tokens[0], tokens[1], stod(tokens[2]));
    }
};
