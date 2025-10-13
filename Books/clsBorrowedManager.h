#pragma once
#include "clsBookManager.h"
#include "../Person/clsUsersManager.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "../Files/BorrowedBookFile.h"
#include "BorrowRecord.h"

using namespace std;

class clsBorrowedManager {
private:
    string removeNewline(string str) {
        if (!str.empty() && str.back() == '\n') {
            str.pop_back();
        }
        return str;
    }

public:
    vector<BorrowRecord> records;
    clsBorrowedBookFile fileHandler;

    void BorrowBook(clsUser &user, clsBooks &book, int borrowDays) {
        if (!book.getIsAvailable()) {
            cout << "\n[!] Sorry, this book is currently not available.\n";
            return;
        }

        if (borrowDays < 1 || borrowDays > 15) {
            cout << "\n[!] Borrowing period must be between 1 and 15 days.\n";
            return;
        }

        book.Borrow();

        BorrowRecord rec;
        rec.userEmail = user.getEmail();
        rec.bookTitle = book.getTitle();

        time_t now = time(0);
        rec.borrowDate = removeNewline(ctime(&now));

        time_t ret = now + (borrowDays * 24 * 60 * 60);
        rec.returnDate = removeNewline(ctime(&ret));

        vector<BorrowRecord> records = fileHandler.loadBorrowedBooksData();
        records.push_back(rec);
        fileHandler.saveBorrowedBooksData(records);

        cout << "\n========================================\n";
        cout << "  Book borrowed successfully!\n";
        cout << "  Book: " << book.getTitle() << "\n";
        cout << "  Borrower: " << user.getEmail() << "\n";
        cout << "  Borrow Date: " << rec.borrowDate << "\n";
        cout << "  Return Date: " << rec.returnDate << "\n";
        cout << "========================================\n";
    }

    void DisplayUserBorrowedBooks(string userEmail) {
        vector<BorrowRecord> records = fileHandler.loadBorrowedBooksData();

        cout << "\n======= Your Borrowed Books =======\n";
        bool found = false;
        for (const auto &record : records) {
            if (record.userEmail == userEmail) {
                cout << "Book Title: " << record.bookTitle << "\n";
                cout << "Borrow Date: " << record.borrowDate << "\n";
                cout << "Return Date: " << record.returnDate << "\n";
                cout << "------------------------------------\n";
                found = true;
            }
        }
        if (!found) {
            cout << "You have no borrowed books.\n";
        }
        cout << "===================================\n";
    }

    void DisplayAllBorrowedBooks() {
        vector<BorrowRecord> records = fileHandler.loadBorrowedBooksData();

        if (records.empty()) {
            cout << "\n======= No borrowed books yet =======\n";
            return;
        }

        cout << "\n======= All Borrowed Books =======\n";
        for (const auto &record : records) {
            cout << "User Email: " << record.userEmail << "\n";
            cout << "Book Title: " << record.bookTitle << "\n";
            cout << "Borrow Date: " << record.borrowDate << "\n";
            cout << "Return Date: " << record.returnDate << "\n";
            cout << "------------------------------------\n";
        }
        cout << "==================================\n";
    }
};