#pragma once
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class clsScreenUser {

public:
    static void ShowUserMenu() {
        cout << "\n==================  User Menu ==================\n";
        cout << "1. Display Books in the library\n";
        cout << "2. Search Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Sign In\n";
        cout << "5. Register\n";
        cout << "6. My Borrowed Books\n";
        cout << "7. Back to Main Menu\n";
        cout << "================================================\n";
        cout << "Enter your choice: ";
    }

    static void ShowSearchMenuForUser() {
        system("cls");
        cout << "\n==================  Search Book Options ==================\n";
        cout << "1. Search by Title\n";
        cout << "2. Search by Category\n";
        cout << "3. Back to Books Menu\n";
        cout << "==========================================================\n";
        cout << "Enter your choice: ";
    }

    static void BorrowingBook(string &bookName, int &days) {
        system("cls");
        cout << "\n==================  Borrowing ==================\n";

        cout << "Enter the book title: ";
        cin.ignore();
        getline(cin, bookName);

        if (bookName.empty()) {
            cout << "[!] Error: Book title cannot be empty!\n";
            days = -1;
            return;
        }

        cout << "\nEnter the days to borrow (1-15): ";
        cin >> days;

        if (cin.fail() || days < 1 || days > 15) {
            cout << "[!] Error: Please enter a valid number between 1 and 15!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            days = -1;
        }
    }

    static void ScreenSignin(string &username, string &password) {
        system("cls");
        cout << "\n==================  Sign in ==================\n";
        do {
            cout << "Enter the username: ";
            cin.ignore();
            getline(cin, username);

            if (username.empty()) {
                cout << "[!] Error: Username cannot be empty!\n";
            }
        } while (username.empty());

        do {
            cout << "\nEnter the password: ";
            getline(cin, password);

            if (password.empty()) {
                cout << "[!] Error: Password cannot be empty!\n";
            } else if (password.length() < 6) {
                cout << "[!] Error: Password must be at least 6 characters!\n";
                password = "";
            }
        } while (password.empty());
    }

    static void ScreenRegister(string &username, string &password, string &email) {
        system("cls");
        cout << "\n==================  Register ==================\n";

        do {
            cout << "Enter the username: ";
            cin.ignore();
            getline(cin, username);

            if (username.empty()) {
                cout << "[!] Error: Username cannot be empty!\n";
            } else if (username.length() < 3) {
                cout << "[!] Error: Username must be at least 3 characters!\n";
                username = "";
            }
        } while (username.empty());

        do {
            cout << "\nEnter the password (min 6 characters): ";
            getline(cin, password);

            if (password.empty()) {
                cout << "[!] Error: Password cannot be empty!\n";
            } else if (password.length() < 6) {
                cout << "[!] Error: Password must be at least 6 characters!\n";
                password = "";
            }
        } while (password.empty());

        do {
            cout << "\nEnter the email: ";
            getline(cin, email);

            if (email.empty()) {
                cout << "[!] Error: Email cannot be empty!\n";
            } else if (email.find('@') == string::npos) {
                cout << "[!] Error: Email must contain '@'!\n";
                email = "";
            } else if (email.find('.', email.find('@')) == string::npos) {
                cout << "[!] Error: Invalid email format!\n";
                email = "";
            } else if (email.find(' ') != string::npos) {
                cout << "[!] Error: Email cannot contain spaces!\n";
                email = "";
            }
        } while (email.empty());

        cout << "\nRegistration data collected successfully!\n";
    }
};