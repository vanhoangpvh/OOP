#include <vector>
#include <iostream>

using namespace std;

class CBorrowBook : public CLibrary{
protected:
	string full_name;
	int year;
	int number_borrow;
	vector<CBook*>list_books_borrow;
public:
	CBorrowBook();
	void input();
	void output();
	CBook* findBook(string);
	void updateListWhenBorrow();
};

CBorrowBook::CBorrowBook() {
	full_name = "<unknown>";
	year = 1;
	number_borrow = 1;
}

void CBorrowBook::input() {
	cout << "\nEnter full name: ";
	getline(cin, full_name);
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter number of books you borrow: ";
	cin >> number_borrow;
	for (int i = 0; i < number_borrow; i++) {
		CBook* element = new CBook;
		element->input();
		list_books_borrow.push_back(element);
	}
}

void CBorrowBook::output() {
	cout << "\nFull name: " << full_name << endl;
	cout << "Year: " << year;
	cout << "\nNumbers of books borrow: " << number_borrow;
	int run = 1;
	for (CBook* element : list_books_borrow) {
		cout << "\nInformation of book " << run << ":";
		element->output();
		cout << endl;
		run++;
	}
}

CBook* CBorrowBook::findBook(string id_find) {
	for (CBook* element : list_books_borrow) {
		CBook* temp = element->findBook(id_find);
		if (temp) {
			return temp;
		}
	}
	return NULL;
}

void CBorrowBook::updateListWhenBorrow() {
	// Iterate over each book in list_books
	for (auto it1 = list_books.begin(); it1 != list_books.end(); ++it1) {
		CBook* bookToRemove = *it1; // Get the current book in list_books
		// Iterate over each book in list_books_borrow
		for (CBook* bookToBorrow : list_books_borrow) {
			if (bookToRemove == bookToBorrow) { // Compare the pointers of the books
				// Book found in list_books, remove it
				it1 = list_books.erase(it1); // Update iterator after erasing
				--it1; // Adjust iterator if needed
				break; // Exit the inner loop as the book is found and removed
			}
		}
	}
	// Update the number of books in list_books
	number_books = list_books.size();
}
 

