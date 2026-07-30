#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    bool isAvailable;

public:
    LibraryBook(string t, string a) {
        title = t;
        author = a;
        isAvailable = true; // Book is available by default
    }

    string getTitle() const { return title; }
    string getAuthor() const { return author; }

    void checkout() {
        if (isAvailable) {
            isAvailable = false;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is already checked out!" << endl;
        }
    }

    void returnBook() {
        isAvailable = true;
        cout << title << " has been returned." << endl;
    }

    void display() const {
        cout << "Title: " << title << ", Author: " << author 
             << ", Status: " << (isAvailable ? "Available" : "Checked Out") << endl;
    }
};

// Standalone function taking a const reference
void printBookInfo(const LibraryBook& book) {
    cout << "\n[Standalone Friend Info]" << endl;
    // Inside this function, we can only call const methods because 'book' is const
    cout << "Book Title: " << book.getTitle() << endl;
    cout << "Book Author: " << book.getAuthor() << endl;
    book.display(); 
}

int main() {
    LibraryBook myBook("2001", "George RR Martin");

    cout << "Initial status:" << endl;
    myBook.display();

    cout << "\nPerforming actions:" << endl;
    myBook.checkout();
    myBook.checkout(); // Trying to check out again
    
    // Pass object to the standalone function
    printBookInfo(myBook);

    cout << "\nReturning the book:" << endl;
    myBook.returnBook();
    myBook.display();

    return 0;
}
