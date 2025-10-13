#pragma once
#include <iostream>
#include <string>
using namespace std;

class clsUser {
private:
    string _username;
    string _password;
    string _email;
    bool _isAdmin;

public:

    clsUser();
    clsUser(string username, string password, string email, bool isAdmin = false);


    string getUsername() const;
    void setUsername( const string& u);

    string getEmail() const;
    void setEmail( const string& e);

    string getPassword() const;
    void setPassword( const string& p);
    bool isAdmin() const;



    bool checkPassword(const string& inputPassword) const;

    // for file
    string toLine(string separator = "||") const;
    static clsUser fromLine(const string& line, string separator = "||");
};
