#pragma once
#include <iostream>
#include <set>
#include <vector>
#include "clsUser.h"
#include "../Files/BorrowedBookFile.h"
#include "../Files/UsersInfoFile.h"
using namespace std;

class clsUsersManager {
private:
    UsersInfoFile _storage;
    clsBorrowedBookFile fileHandler;
    clsUser user;

public:

    bool userExists(const string& username);

    bool registerUser(const string& username, const string& password, const string& email, bool isAdmin = false);

    clsUser signIn(const string &username, const string &password);
    bool signinCheck(const string& username, const string& password) ;


    vector<clsUser> listUsers();
    void DisplayUsersWhoBorrowed();
    void displayUsers();

};
