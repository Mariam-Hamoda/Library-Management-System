#pragma once
#include"../Screens/clsScreenUser.h"
#include "../Person/clsUsersManager.h"
#include"../Books/clsBookManager.h"
#include"../Books/clsBorrowedManager.h"
#include<iostream>
#include<limits>
#include<string>
using namespace std;
class InputOutputUser {
private:
    string username, password, email;
    int daysBorrow;
    string bookname;
    clsUser currentUser;
    clsUsersManager userManager;

    clsBorrowedManager borrowManager;
    clsBookManager bookManager;

public:
    void handleOptionUser();
    void ProceesSearchOptionUser();
    void ProcessBorrowing();
    void ProcessSignin();
    void ProcessRegister();
};
