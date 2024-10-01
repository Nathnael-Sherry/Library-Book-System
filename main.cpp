#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
private:
    string title;
    string author;
    string isbn;
    bool isBorrowed;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i), isBorrowed(false) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    bool isAvailable() const { return !isBorrowed; }

    void borrow() {
        if (isBorrowed) {
            cout << "Error: The book '" << title << "' is already borrowed." << endl;
        } else {
            isBorrowed = true;
            cout << "You have successfully borrowed '" << title << "'." << endl;
        }
    }

    void returnBook() {
        if (!isBorrowed) {
            cout << "Error: The book '" << title << "' was not borrowed." << endl;
        } else {
            isBorrowed = false;
            cout << "You have successfully returned '" << title << "'." << endl;
        }
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author << ", ISBN: " << isbn;
        if (isBorrowed) {
            cout << " (Borrowed)";
        } else {
            cout << " (Available)";
        }
        cout << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.borrow();
                return;
            }
        }
        cout << "Error: Book '" << title << "' not found in the library." << endl;
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook();
                return;
            }
        }
        cout << "Error: Book '" << title << "' not found in the library." << endl;
    }

    void displayAvailableBooks() const {
        cout << "\nAvailable Books:\n";
        for (const auto& book : books) {
            if (book.isAvailable()) {
                book.display();
            }
        }
    }
};

int main() {
    Library library;

    // Adding some books to the library
    library.addBook(Book("1984", "George Orwell", "1234567890"));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", "0987654321"));
    library.addBook(Book("The Great Gatsby", "F. Scott Fitzgerald", "1122334455"));

    int choice;
    string title;

    do {
        cout << "\nLibrary Book System\n";
        cout << "1. Borrow a book\n";
        cout << "2. Return a book\n";
        cout << "3. Display available books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the title of the book to borrow: ";
                cin.ignore();
                getline(cin, title);
                library.borrowBook(title);
                break;
            case 2:
                cout << "Enter the title of the book to return: ";
                cin.ignore();
                getline(cin, title);
                library.returnBook(title);
                break;
            case 3:
                library.displayAvailableBooks();
                break;
            case 4:
                cout << "Exiting the system.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
