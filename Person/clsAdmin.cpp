#include "clsAdmin.h"

string clsAdmin::password = "lib109booo";


clsAdmin::clsAdmin(const string &_password) {
    password = _password;
}


void clsAdmin::setPassword(const string &_password) {
    if (_password.length() < 6) {
        cout << "Password too short!" << endl;
        return;
    }
    password = _password;
}

bool clsAdmin::checkPassword() {
    cout << "\t\t\tEnter the password: ";
    string inputPassword;
    cin >> inputPassword;

    return(inputPassword == password);
}
