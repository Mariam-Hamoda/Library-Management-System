#pragma once

#include<string>
#include<iostream>

using namespace std;

class clsAdmin {
private:
    static string password;
public:

    clsAdmin(const string &_password);
    void setPassword(const string &_password);
    bool  static checkPassword();

};

