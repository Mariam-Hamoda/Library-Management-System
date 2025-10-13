#include "clsUser.h"

clsUser::clsUser() {
    _username = "";
    _password = "";
    _email = "";
    _isAdmin = false;
}

clsUser::clsUser(string username, string password, string email, bool isAdmin) {
    _username = username;
    _password = password;
    _email = email;
    _isAdmin = isAdmin;
}

string clsUser::getUsername() const {
    return _username;
}

string clsUser::getEmail() const {
    return _email;
}

void clsUser::setEmail(const string &e) {
    _email = e;
}

string clsUser::getPassword() const {
    return _password;
}


void clsUser::setPassword(const string &p) {
    _password=p;
}

bool clsUser::isAdmin() const {
    return _isAdmin;
}

void clsUser::setUsername(const string &u) {
    _username=u;
}


bool clsUser::checkPassword(const string& inputPassword) const {
    return inputPassword == _password;
}


string clsUser::toLine(string separator) const {
    return _username + separator + _password + separator + _email + separator + (_isAdmin ? "1" : "0");
}

// Create user from line
clsUser clsUser::fromLine(const string& line, string separator) {
    size_t pos1=line.find(separator);
    size_t pos2=line.find(separator,pos1+separator.length());
    size_t pos3= line.find(separator,pos2+separator.length());

    string username = line.substr(0,pos1);
    string password = line.substr(pos1+separator.length(),pos2-pos1-separator.length());
    string email = line.substr(pos2+separator.length(),pos3-pos2-separator.length());
    bool isAdmin = (line.substr(pos3+separator.length())=="1");

    return clsUser(username, password, email, isAdmin);
}
