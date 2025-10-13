#include "clsBookManager.h"
#include <limits>

string toLower(const string &input) {
    string result = input;
    transform(result.begin(), result.end(), result.begin(),
              [](unsigned char c){ return tolower(c); });
    return result;
}

void clsBookManager::displayBookDetails(const clsBooks& book) {
    cout << "--------------------------------------------------\n";
    cout << "ID       : " << book.getId() << "\n";
    cout << "Title    : " << book.getTitle() << "\n";
    cout << "Author   : " << book.getAuthor() << "\n";
    cout << "Category : " << book.getCategory() << "\n";
    cout << "Quantity : " << book.getQuantity() << "\n";
    cout << "Price    : " << book.getPrice() << "\n";
    cout << "--------------------------------------------------\n";
}

void clsBookManager::addBooks() {
    string id, title, author, category;
    int quantity;
    double price;

    cout << "\n========== Add New Book ==========\n";

    bool idExists;
    do {
        idExists = false;
        cout << "\n[*] Enter book ID (required): ";
        cin >> id;

        if (id.empty()) {
            cout << "[!] Error: ID cannot be empty!\n";
            continue;
        }

        for (auto &book : vbooksData) {
            if (id == book.getId()) {
                cout << "[!] Error: ID '" << id << "' already exists!\n";
                idExists = true;
                break;
            }
        }
    } while (idExists || id.empty());

    cin.ignore();

    do {
        cout << "\n[*] Enter title (required): ";
        getline(cin, title);
        if (title.empty()) {
            cout << "[!] Error: Title cannot be empty!\n";
        }
    } while (title.empty());

    do {
        cout << "\n[*] Enter author (required): ";
        getline(cin, author);
        if (author.empty()) {
            cout << "[!] Error: Author cannot be empty!\n";
        }
    } while (author.empty());

    do {
        cout << "\n[*] Enter category (required): ";
        getline(cin, category);
        if (category.empty()) {
            cout << "[!] Error: Category cannot be empty!\n";
        }
    } while (category.empty());

    do {
        cout << "\n[*] Enter quantity (0 or more): ";
        cin >> quantity;

        if (cin.fail() || quantity < 0) {
            cout << "[!] Error: Please enter a valid positive number!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            quantity = -1;
        }
    } while (quantity < 0);

    do {
        cout << "\n[*] Enter price (must be positive): ";
        cin >> price;

        if (cin.fail() || price <= 0) {
            cout << "[!] Error: Please enter a valid positive price!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            price = -1;
        }
    } while (price <= 0);

    clsBooks newBooks(id, title, author, category, quantity, true, price);
    vbooksData.push_back(newBooks);
    fileHandler.saveBooksInfo(vbooksData);

    cout << "\n==================================\n";
    cout << "  SUCCESS: Book added!\n";
    cout << "  Title: " << newBooks.getTitle() << "\n";
    cout << "  ID: " << newBooks.getId() << "\n";
    cout << "==================================\n";
}

void clsBookManager::deleteBookById() {
    string IdDelete;
    cout << "Enter ID to delete: ";
    cin >> IdDelete;

    auto it = remove_if(vbooksData.begin(), vbooksData.end(), [&](clsBooks& book) {
        return book.getId() == IdDelete;
    });

    if (it != vbooksData.end()) {
        vbooksData.erase(it, vbooksData.end());
        fileHandler.saveBooksInfo(vbooksData);
        cout << "Book has been deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

void clsBookManager::deleteBookByTitle() {
    string TitleDelete;
    cout << "Enter title to delete: ";
    cin.ignore();
    getline(cin, TitleDelete);

    if (TitleDelete.empty()) {
        cout << "Title cannot be empty.\n";
        return;
    }

    TitleDelete = toLower(TitleDelete);

    auto it = remove_if(vbooksData.begin(), vbooksData.end(), [&](clsBooks& book) {
        return toLower(book.getTitle()) == TitleDelete;
    });

    if (it != vbooksData.end()) {
        vbooksData.erase(it, vbooksData.end());
        fileHandler.saveBooksInfo(vbooksData);
        cout << "Book has been deleted successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}

void clsBookManager::displayBooks() {
    if (vbooksData.empty()) {
        cout << "\n No books available in the library.\n";
        return;
    }

    cout << "\n========== Books List ==========\n";
    for (auto &book : vbooksData) {
        displayBookDetails(book);
    }
    cout << "\nTotal books: " << vbooksData.size() << "\n";
}

void clsBookManager::searchBooksByID() {
    string IdSearch;
    cout << "Enter book ID to search: ";
    cin >> IdSearch;

    if (IdSearch.empty()) {
        cout << " ID cannot be empty.\n";
        return;
    }

    bool found = false;
    for (auto &book : vbooksData) {
        if (book.getId() == IdSearch) {
            cout << "\n Book found:\n";
            displayBookDetails(book);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nBook with ID '" << IdSearch << "' not found.\n";
    }
}

void clsBookManager::searchBooksByTitle() {
    string TitleSearch;
    cout << "Enter title to search: ";
    cin.ignore();
    getline(cin, TitleSearch);

    if (TitleSearch.empty()) {
        cout << "Title cannot be empty.\n";
        return;
    }

    TitleSearch = toLower(TitleSearch);

    bool found = false;
    for (auto &book : vbooksData) {
        if (toLower(book.getTitle()).find(TitleSearch) != string::npos) {
            if (!found) {
                cout << "\nBooks found:\n";
                found = true;
            }
            displayBookDetails(book);
        }
    }

    if (!found) {
        cout << "\nNo book found with title containing '" << TitleSearch << "'.\n";
    }
}

clsBooks clsBookManager::findBookByTitle(string &title) {
    string lowerTitle = toLower(title);
    for (auto &book : vbooksData) {
        if (toLower(book.getTitle()) == lowerTitle) {
            return book;
        }
    }
    return clsBooks();
}

void clsBookManager::searchBooksByCategory() {
    listCategories();

    if (vbooksData.empty()) {
        return;
    }

    cout << "\n--------------------------------------------------\n";
    string categorySearch;
    cout << "Enter book category to search: ";
    cin.ignore();
    getline(cin, categorySearch);

    if (categorySearch.empty()) {
        cout << "Category cannot be empty.\n";
        return;
    }

    categorySearch = toLower(categorySearch);

    bool found = false;
    cout << "\nBooks in category '" << categorySearch << "':\n";
    for (auto &book : vbooksData) {
        if (toLower(book.getCategory()) == categorySearch) {
            displayBookDetails(book);
            found = true;
        }
    }

    if (!found) {
        cout << "\n No books found in category '" << categorySearch << "'.\n";
    }
}

void clsBookManager::listCategories() {
    if (vbooksData.empty()) {
        cout << "\n No categories available (no books in library).\n";
        return;
    }

    cout << "\n========== Available Categories ==========\n";

    set<string> uniqueCategories;
    for (auto &book : vbooksData) {
        uniqueCategories.insert(toLower(book.getCategory()));
    }

    int index = 1;
    for (const auto &category : uniqueCategories) {
        cout << "  " << index++ << ". " << category << "\n";
    }
    cout << "==========================================\n";
}

clsBooks* clsBookManager::FindBook(string title) {
    if (title.empty()) {
        return nullptr;
    }

    string lowerTitle = toLower(title);
    for (auto &book : vbooksData) {
        if (toLower(book.getTitle()) == lowerTitle) {
            return &book;
        }
    }
    return nullptr;
}