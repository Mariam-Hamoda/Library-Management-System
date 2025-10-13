#pragma once
#include "../Books/clsBookManager.h"
#include "../Screens/clsScreenAdmin.h"
#include <iostream>

#include "../Books/clsBorrowedManager.h"

class clsInputOutputAdmin:public clsScreenAdmin{
private:
    clsBookManager &books;
    clsBorrowedManager borrowedBooks;
    clsUsersManager users;

public:

    clsInputOutputAdmin(clsBookManager &manager) : books(manager), borrowedBooks(), users()
    {
    }

    void HandleAdminMenu();
    void ProcessManagementBooks();
    void ProcessManagementUsers();
    void ProcessDeleteOptions();
    void ProcessSearchOptions();
};


