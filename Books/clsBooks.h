#pragma once
#include <string>
#include <iostream>
#include <ostream>
using namespace std;

class clsBooks {
private:
    string id;
    string title;
    string author;
    string category;
    int quantity;
    bool isAvailable;
    double price;

public:

    clsBooks();


    clsBooks(string _id, string _title, string _author, string _category,
             int _quantity, bool _isAvailable, double _price);


    string getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getCategory() const { return category; }
    int getQuantity() const { return quantity; }
    bool getIsAvailable() const { return quantity>0; }
    double getPrice() const { return price; }
    void Borrow() {
        if(isAvailable)
            --quantity;
        else
            cout<<"Not enough books to be borrowed"<<endl;
    }
};

