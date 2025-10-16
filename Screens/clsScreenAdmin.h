#pragma once
#include <iostream>
using namespace std;

class clsScreenAdmin {
public:

    static void ShowAdminMenu() {
        cout << "\n\t\t\t==================  Admin Menu ==================\n";
        cout << "\t\t\t1. Books Management\n";
        cout << "\t\t\t2. Users Management\n";
        cout << "\t\t\t3. Back to Main Menu\n";
        cout << "\t\t\t=================================================\n";
        cout << "\t\t\tEnter your choice: ";
    }

    static void ShowManagementBooks() {
        cout << "\n\t\t\t==================  Books Management ==================\n";
        cout << "\t\t\t1. Add Book\n";
        cout << "\t\t\t2. Delete Book\n";
        cout << "\t\t\t3. Search Book\n";
        cout << "\t\t\t4. Display Books\n";
        cout << "\t\t\t5. Back to Admin Menu\n";
        cout << "\t\t\t=======================================================\n";
        cout << "\t\t\tEnter your choice: ";
    }

    static void ShowManagementUsers() {
        cout << "\n\t\t\t===============  Users Management  ===============\n";
        cout << "\t\t\t1. Display All Borrowed Books\n";
        cout << "\t\t\t2. Display Users Who Borrowed\n";
        cout << "\t\t\t3. Display All Users\n";
        cout << "\t\t\t4. Back to Admin Menu\n";
        cout << "\t\t\t==================================================\n";
        cout << "\t\t\tEnter your choice: ";
    }

    static void ShowSearchBookOptions() {
        cout << "\n\t\t\t==================  Search Book Options ==================\n";
        cout << "\t\t\t1. Search by ID\n";
        cout << "\t\t\t2. Search by Title\n";
        cout << "\t\t\t3. Search by Category\n";
        cout << "\t\t\t4. Back to Books Menu\n";
        cout << "\t\t\t==========================================================\n";
        cout << "\t\t\tEnter your choice: ";
    }

    static void ShowDeleteBookOptions() {
        cout << "\n\t\t\t==================  Delete Book Options ==================\n";
        cout << "\t\t\t1. Delete by ID\n";
        cout << "\t\t\t2. Delete by Title\n";
        cout << "\t\t\t3. Back to Books Menu\n";
        cout << "\t\t\t==========================================================\n";
        cout << "\t\t\tEnter your choice: ";
    }
};
