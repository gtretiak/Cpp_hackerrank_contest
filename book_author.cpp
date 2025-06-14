#include <string>
#include <iostream>
using namespace std;

class Book {
protected:
    string title;
    string author;
public:
    Book(string t, string a) {
        title = t;
        author = a;
    }
    virtual void display() = 0;
};

class MyBook : public Book {
private:
    int price;
public:
    MyBook(string title, string author, int price) : Book(title, author), price(price) {}
    
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
};

int main() {
    string title, author;
    int price;
    
    cout << "The book's title is: ";
    getline(cin, title);
    cout << "The book's author is: ";
    getline(cin, author);
    cout << "The book's price is: ";
    cin >> price;
    MyBook novel(title, author, price);
    cout << "Let's see what we've got..." << endl;
    novel.display();
    return 0;
}
