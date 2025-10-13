#include "clsBooks.h"

clsBooks::clsBooks()
{
     id = "";
    title = "";
    author = "";
    category = "";
    quantity = 0;
    isAvailable =false;
    price = 0;
}

clsBooks::clsBooks(string _id, string _title, string _author, string _category, int _quantity, bool _isAvailable, double _price)
{
    id = _id;
    title = _title;
    author = _author;
    category = _category;
    quantity = _quantity;
    isAvailable = _isAvailable;
    price = _price;
}


