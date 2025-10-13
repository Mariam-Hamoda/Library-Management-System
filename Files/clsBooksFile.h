#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "../Books/clsBooks.h"

using namespace std;

class clsBooksFile {
public:


    void saveBooksInfo(const vector<clsBooks> &vbooks) {
        ofstream output("books.txt");
        if (!output.is_open()) {
            cout << "There is a problem opening the file..." << "\n";
            return;
        }

        for (const auto &book : vbooks) {
            string dataBookLine = ConvertBooksToLine(book);
            output << dataBookLine << "\n";
        }
        output.close();
    }


    vector<clsBooks> loadBooksInfo() {
        ifstream input("books.txt");
        vector<clsBooks> vBooks;

        if (!input.is_open()) {
            cout << "There is a problem..." << endl;
            return vBooks;
        }

        string line;
        while (getline(input, line)) {
            clsBooks book = ConvertLineToBook(line, "||");
            vBooks.push_back(book);
        }

        input.close();
        return vBooks;
    }

    string ConvertBooksToLine(const clsBooks &book, string separator = "||") {
        string stBooksRecord = "";
        stBooksRecord += book.getId() + separator;
        stBooksRecord += book.getTitle() + separator;
        stBooksRecord += book.getAuthor() + separator;
        stBooksRecord += book.getCategory() + separator;
        stBooksRecord += to_string(book.getQuantity()) + separator;
        stBooksRecord += (book.getIsAvailable() ? "1" : "0") + separator;
        stBooksRecord += to_string(book.getPrice());
        return stBooksRecord;
    }

    clsBooks ConvertLineToBook(const string& line, string separator = "||") {
        size_t pos1 = line.find(separator);
        size_t pos2 = line.find(separator, pos1 + separator.length());
        size_t pos3 = line.find(separator, pos2 + separator.length());
        size_t pos4 = line.find(separator, pos3 + separator.length());
        size_t pos5 = line.find(separator, pos4 + separator.length());
        size_t pos6 = line.find(separator, pos5 + separator.length());

        string id = line.substr(0, pos1);
        string title = line.substr(pos1 + separator.length(), pos2 - pos1 - separator.length());
        string author = line.substr(pos2 + separator.length(), pos3 - pos2 - separator.length());
        string category = line.substr(pos3 + separator.length(), pos4 - pos3 - separator.length());
        int quantity = stoi(line.substr(pos4 + separator.length(), pos5 - pos4 - separator.length()));
        bool isAvailable = (line.substr(pos5 + separator.length(), pos6 - pos5 - separator.length()) == "1");
        double price = stod(line.substr(pos6 + separator.length()));

        return clsBooks(id, title, author, category, quantity, isAvailable, price);
    }
};
