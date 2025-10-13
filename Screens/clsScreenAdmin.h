#pragma once
#include <iostream>
using namespace std;

class clsScreenAdmin {
public:

    static void ShowAdminMenu() {
        cout << "\n==================  Admin Menu ==================\n";
        cout << "1. Books Management\n";
        cout << "2. Users Management\n";
        cout << "3. Back to Main Menu\n";
        cout << "=================================================\n";
        cout << "Enter your choice: ";
    }

    static void ShowManagementBooks() {
        cout << "\n==================  Books Management ==================\n";
        cout << "1. Add Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display Books\n";
        cout << "5. Back to Admin Menu\n";
        cout << "=======================================================\n";
        cout << "Enter your choice: ";
    }

    static void ShowManagementUsers() {
        cout << "\n===============  Users Management  ===============\n";
        cout << "1. Display All Borrowed Books\n";
        cout << "2. Display Users Who Borrowed\n";
        cout << "3. Display All Users\n";
        cout << "4. Back to Admin Menu\n";
        cout << "==================================================\n";
        cout << "Enter your choice: ";
    }
    static void ShowSearchBookOptions() {
        cout << "\n==================  Search Book Options ==================\n";
        cout << "1. Search by ID\n";
        cout << "2. Search by Title\n";
        cout << "3. Search by Category\n";
        cout << "4. Back to Books Menu\n";
        cout << "==========================================================\n";
        cout << "Enter your choice: ";
    }

    static void ShowDeleteBookOptions() {
        cout << "\n==================  Delete Book Options ==================\n";
        cout << "1. Delete by ID\n";
        cout << "2. Delete by Title\n";
        cout << "3. Back to Books Menu\n";
        cout << "==========================================================\n";
        cout << "Enter your choice: ";
    }
};
