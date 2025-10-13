#include "clsUsersManager.h"

#include "../Books/BorrowRecord.h"

bool clsUsersManager::userExists(const string& username) {
    vector<clsUser> users = _storage.loadUsersInfo();
    for (auto& user : users) {
        if (user.getUsername() == username) {
            return true;
        }
    }
    return false;
}

// تسجيل مستخدم جديد
bool clsUsersManager::registerUser(const string& username, const string& password, const string& email, bool isAdmin) {
    vector<clsUser> users = _storage.loadUsersInfo();

    if (userExists(username)) {
        cout << " User already exists!\n";
        return false;
    }

    users.push_back(clsUser(username, password, email, isAdmin));
    _storage.saveUsersInfo(users);

    cout << " User registered successfully!\n";
    return true;
}

// تسجيل الدخول
clsUser clsUsersManager::signIn(const string &username, const string &password) {
    vector<clsUser> users = _storage.loadUsersInfo();

    for (auto& user : users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            cout << "Login successful!\n";
            return user;
        }
    }

    cout << "Invalid username or password.\n";
    return clsUser();
}

bool clsUsersManager::signinCheck(const string& username, const string& password) {
    vector<clsUser> users = _storage.loadUsersInfo();
    for (auto& user : users) {
        if (user.getUsername() == username && user.checkPassword(password)) {
            return true;
        }
    }
    return false;
}

vector<clsUser> clsUsersManager::listUsers() {
    return _storage.loadUsersInfo();
}

void clsUsersManager::DisplayUsersWhoBorrowed()
{
    vector<BorrowRecord> records = fileHandler.loadBorrowedBooksData();

    if (records.empty()) {
        cout << "\n======= No users have borrowed books yet =======\n";
        return;
    }

    cout << "\n========== Users Who Borrowed Books ==========\n";
    set<string> uniqueUsers;
    for (const auto &record : records)
    {
        uniqueUsers.insert(record.userEmail);
    }
    int index=1;
    for (auto &email : uniqueUsers)
    {
        cout << index++ << ". " << email << "\n";
    }
    cout << "----------------------------------------------\n";
    cout << "Total users who borrowed: " << uniqueUsers.size() << "\n";
    cout << "==============================================\n";
}

void clsUsersManager::displayUsers()
{

    vector<clsUser> users = listUsers();

    if (users.empty()) {
        cout << "\n No users registered yet.\n";
    }
    else {
    cout << "\n============== All Registered Users ==============\n";
    cout << "------------------------------------------------\n";

    for (size_t i = 0; i < users.size(); i++) {
        cout << "User #" << (i + 1) << "\n";
        cout << "  Username : " << users[i].getUsername() << "\n";
        cout << "  Email    : " << users[i].getEmail() << "\n";
        cout << "  Admin    : " << (users[i].isAdmin() ? "Yes" : "No") << "\n";
        cout << "------------------------------------------------\n";
    }
    cout << "Total users: " << users.size() << "\n";
    cout << "==================================================\n";

    }
}

