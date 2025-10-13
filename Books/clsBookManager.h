#pragma once
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <algorithm>
#include "clsBooks.h"
#include "../Files/clsBooksFile.h"

class clsBookManager {
private:
    vector<clsBooks> vbooksData;
    clsBooksFile fileHandler;

public:
    void displayBookDetails(const clsBooks& book);
    void addBooks();
    void deleteBookById();
    void deleteBookByTitle();
    void displayBooks();
    void searchBooksByID();
    void searchBooksByTitle();
    clsBooks findBookByTitle( string &title);
    void searchBooksByCategory();
    void listCategories();
    clsBooks *FindBook(string title);



    clsBookManager() {
        vbooksData = fileHandler.loadBooksInfo();
    }
};
