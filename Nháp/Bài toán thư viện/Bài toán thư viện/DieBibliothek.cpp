#include <iostream>
#include <string>
#include <vector>
#include "CBook.hpp"
#include "CLibrary.hpp"
#include "CBorrowBook.hpp"

using namespace std;

int main() {
	CLibrary* library = new CLibrary;
	cout << "Books in Library:" << endl;
	//Input library;
	library->input();
	
	//Output library
	library->output();

	//Finding books in library using id
	cout << "\n\nFinding books in library using id:" << endl;
	cout << "Enter string: ";
	string id_find;
	getline(cin, id_find); // Read input directly into id_find

	// Trim leading and trailing whitespace from id_find
	id_find.erase(0, id_find.find_first_not_of(" \t\n\r"));
	id_find.erase(id_find.find_last_not_of(" \t\n\r") + 1);

	CBook* temp = library->findBook(id_find);
	if (temp != nullptr) {
		cout << "The information of the book you want to find is:" << endl;
		temp->output();
	}
	else {
		cout << "Can not find book you want to find";
	}

	//Borrow book list
	cout << "\n~~~Borrow books list~~~" << endl;
	CBorrowBook* borrow = new CBorrowBook;
	borrow->input();
	borrow->output();
	//Update library when borrow
	

	borrow->updateListWhenBorrow();
	cout << endl;
	library->output();
	
}