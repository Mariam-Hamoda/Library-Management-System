#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "../Books/BorrowRecord.h"

using namespace std;

class clsBorrowedBookFile {
private:
    string _fileName = "borrowedBooksInfo.txt";

public:

    void saveBorrowedBooksData(const vector<BorrowRecord> &vDataBorrowed) {
        ofstream output(_fileName);
        if (!output.is_open()) {
            cout << "Error opening file for saving.\n";
            return;
        }
        for (const auto &data : vDataBorrowed) {
            output << ConvertDataToLine(data, "||")<<"\n" ;
        }
        output.close();
    }

    vector<BorrowRecord> loadBorrowedBooksData() {
        ifstream input(_fileName);
        vector<BorrowRecord> vDataBorrowed;

        if (!input.is_open()) {
            ofstream createFile(_fileName);
            createFile.close();
            return vDataBorrowed;
        }

        string line;
        while (getline(input, line)) {
            if (line.empty()) {
                continue;
            }

            BorrowRecord rec = ConvertLineToData(line, "||");

            if (!rec.userEmail.empty() && !rec.bookTitle.empty()) {
                vDataBorrowed.push_back(rec);
            }
        }
        input.close();
        return vDataBorrowed;
    }

    string ConvertDataToLine(const BorrowRecord &data, string separator = "||") {
        return data.userEmail + separator +
               data.bookTitle + separator +
               data.borrowDate + separator +
               data.returnDate;
    }

    BorrowRecord ConvertLineToData(const string &line, string separator = "||") {
        BorrowRecord rec;

        if (line.empty()) {
            return rec;
        }

        size_t pos1 = line.find(separator);
        size_t pos2 = line.find(separator, pos1 + separator.length());
        size_t pos3 = line.find(separator, pos2 + separator.length());

        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos) {
            cerr << "Error: Invalid borrow record format: " << line << endl;
            return rec;
        }

        rec.userEmail  = line.substr(0, pos1);
        rec.bookTitle  = line.substr(pos1 + separator.length(), pos2 - pos1 - separator.length());
        rec.borrowDate = line.substr(pos2 + separator.length(), pos3 - pos2 - separator.length());
        rec.returnDate = line.substr(pos3 + separator.length());

        return rec;
    }
};