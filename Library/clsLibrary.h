#pragma once
#include <string>
#include <iostream>

#include "../Screens/clsScreenUser.h"
#include "../Person/clsAdmin.h"
#include "../Screens/clsScreenAdmin.h"
#include "../InputOutput/clsInputOutputAdmin.h"
#include"../InputOutput/InputOutputUser.h"

using namespace std;

class clsLibrary {
private:
    clsInputOutputAdmin adminUI;

public:
    clsLibrary(clsBookManager &manager) : adminUI(manager) {}

    void menu() {
        int choice;
        do {
            cout << "\t\t\t=====================================\n";
            cout << "\t\t\t     Library Management System       \n";
            cout << "\t\t\t=====================================\n";
            cout << "\t\t\t1. User\n";
            cout << "\t\t\t2. Librarian\n";
            cout << "\t\t\t0. Exit\n";
            cout << "\t\t\t=====================================\n";
            cout << "\t\t\tEnter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: {
                    system("cls");
                    InputOutputUser userUI;
                    userUI.handleOptionUser();
                    break;
            }

            case 2:
                {
                    if (!clsAdmin::checkPassword()) {
                        cout << "Access denied. Returning to main menu...\n";
                        system("pause");
                        break;
                    }
                    cout << "Correct password! Access granted.\n";
                    system("pause");
                    adminUI.HandleAdminMenu();
                    break;
                }

            case 0:
                cout << "Exiting system...\n";
                break;

            default:
                cout << " Invalid choice. Please enter 0, 1, or 2.\n";
                break;
            }
             system("pause");
        } while (choice != 0);
    }
};
