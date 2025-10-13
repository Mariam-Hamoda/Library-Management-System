#include "clsInputOutputAdmin.h"
#include "../Screens/clsScreenAdmin.h"
#include <limits>

#include "../Screens/clsScreenUser.h"

void clsInputOutputAdmin::HandleAdminMenu() {
    int choice;
    do {
        system("cls");
        clsScreenAdmin::ShowAdminMenu();

        cin >> choice;

        switch (choice) {
            case 1:
                ProcessManagementBooks();
                break;

            case 2:
                ProcessManagementUsers();
                break;

            case 3:
                cout << "Exiting admin menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
                system("pause");
                break;
        }
    } while (choice != 3);
}

void clsInputOutputAdmin::ProcessManagementBooks() {
    int choice;

    do {
        system("cls");
        clsScreenAdmin::ShowManagementBooks();

        cin >> choice;

        switch (choice) {
            case 1:
                books.addBooks();
                break;

            case 2:
                ProcessDeleteOptions();
                break;

            case 3:
                ProcessSearchOptions();
                break;

            case 4:
                system("cls");
                books.displayBooks();
                break;

            case 5:
                cout << "Returning to Admin Menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
                break;
        }
        if (choice != 5) system("pause");
    } while (choice != 5);
}

void clsInputOutputAdmin::ProcessManagementUsers()
{
    int option;
    do
    {

        system("cls");
        clsScreenAdmin::ShowManagementUsers();

        cin >> option;

        switch (option)
        {
        case 1:
            system("cls");
            borrowedBooks.DisplayAllBorrowedBooks();
            break;
        case 2:
            system("cls");
            users.DisplayUsersWhoBorrowed();
            break;
        case 3:
            users.displayUsers();
            break;
        case 4:
            cout << "Returning to Admin Menu...\n";
            break;
        default:
            cout << "Invalid choice. Please select a valid option.\n";
            break;
        }

        if (option != 4) system("pause");
    } while (option != 4);
}

void clsInputOutputAdmin::ProcessDeleteOptions() {
    int choice;
    do {
        system("cls");
        clsScreenAdmin::ShowDeleteBookOptions();

        cin >> choice;

        switch (choice) {
            case 1:
                books.deleteBookById();
                break;

            case 2:
                books.deleteBookByTitle();
                break;

            case 3:
                cout << "Returning to Books Menu...\n";
                break;

            default:
                cout << "Invalid choice.\n";
                break;
        }
        if (choice != 3) system("pause");
    } while (choice != 3);
}

void clsInputOutputAdmin::ProcessSearchOptions() {
    int choice;
    do {
        system("cls");
        clsScreenAdmin::ShowSearchBookOptions();

        cin >> choice;

        switch (choice) {
            case 1:
                books.searchBooksByID();
                break;

            case 2:
                books.searchBooksByTitle();
                break;

            case 3:
                books.searchBooksByCategory();
                break;

            case 4:
                cout << "Returning ...\n";
                break;

            default:
                cout << "Invalid choice.\n";
                break;
        }
        if (choice != 4) system("pause");
    } while (choice != 4);
}
