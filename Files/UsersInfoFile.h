#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../Person/clsUser.h"

using namespace std;
class UsersInfoFile {
public:
    void saveUsersInfo(vector <clsUser> users)
    {
        ofstream usersFile("users.txt");
        if (!usersFile.is_open())
        { cout << "There is a problem opening the file..." << "\n";
            return;
        }

        for (const auto &user : users)
        {
            usersFile<<user.toLine("||")<<"\n";
        }
        usersFile.close();
    }
    vector<clsUser> loadUsersInfo()
    {
        vector<clsUser> users;
        ifstream usersFile("users.txt");
        if (!usersFile.is_open())
        { cout << "There is a problem opening the file..." << "\n";
            return users;
        }

        string line;
        while (getline(usersFile, line))
        {
            if(!line.empty())
            {
                clsUser user= clsUser::fromLine(line,"||");
                users.push_back(user);
            }
        }
        usersFile.close();
        return users;
    }

};