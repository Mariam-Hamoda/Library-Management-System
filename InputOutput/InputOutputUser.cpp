#include "InputOutputUser.h"

void InputOutputUser::ProceesSearchOptionUser() {
    int choice;
    do {
        system("cls");
        clsScreenUser::ShowSearchMenuForUser();
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            bookManager.searchBooksByTitle();
            system("pause");
            break;

        case 2:
            system("cls");
            bookManager.searchBooksByCategory();
            system("pause");
            break;

        case 3:
            cout << "Returning ...\n";
            break;

        default:
            cout << "Invalid choice.\n";
            system("pause");
            break;
        }
      //  if (choice != 3) system("pause");
    } while (choice != 3);
}

void InputOutputUser::ProcessBorrowing() {
    if (currentUser.getUsername().empty()) {
        cout << "\n[!] You must sign in before borrowing.\n";
        system("pause");
        return;
    }

    clsScreenUser::BorrowingBook(bookname, daysBorrow);

    if (bookname.empty() || daysBorrow < 1) {
        cout << "\n[!] Borrowing cancelled.\n";
        system("pause");
        return;
    }
    clsBooks book = bookManager.findBookByTitle(bookname);
    if (book.getTitle().empty()) {
        cout << "\n[!] Book '" << bookname << "' not found.\n";
        cout << "    Make sure you entered the exact title.\n";
    } else {
        borrowManager.BorrowBook(currentUser, book, daysBorrow);
    }

    system("pause");
}

void InputOutputUser::ProcessSignin() {
    clsScreenUser::ScreenSignin(username, password);
    clsUser loggedInUser = userManager.signIn(username, password);

    if (loggedInUser.getUsername() != "") {
        currentUser = loggedInUser;
    } else {
        cout << "Sign in failed. Please try again.\n";
    }

}

void InputOutputUser::ProcessRegister() {
    clsScreenUser::ScreenRegister(username, password, email);
  if (  userManager.registerUser(username, password, email, false)) {
      currentUser.setUsername(username);
      currentUser.setPassword(password);
      currentUser.setEmail(email);
      cout << "Registration successful! You are now signed in.\n";
    }
    else {
        cout << "Registration failed. User may already exist.\n";
    }
}

void InputOutputUser::handleOptionUser() {
    int option;

    do {
        system("cls");
        clsScreenUser::ShowUserMenu();
        cin >> option;

        switch(option) {

        case 1:
            system("cls");
            bookManager.displayBooks();
            system("pause");
            break;
        case 2:
            ProceesSearchOptionUser();
            break;

        case 3:
            ProcessBorrowing();
            break;

        case 4:
            ProcessSignin();
            system("pause");
            break;

        case 5:
            ProcessRegister();
            system("pause");
            break;

        case 6:
            system("cls");
            borrowManager.DisplayUserBorrowedBooks(currentUser.getEmail());
            system("pause");
            break;

        case 7:
            cout << "Back to Main Menu\n";
            break;

        default:
            cout << "Invalid option, try again.\n";
            system("pause");
            break;
        }
    } while (option != 7);
}

