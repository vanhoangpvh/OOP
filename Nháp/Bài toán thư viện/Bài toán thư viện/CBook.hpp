#include <iostream>
#include <string>

using namespace std;

class CBook {
protected:
	string title;
	string id;
	string genre;
public:
	CBook();
	void input();
    void output();
	string getTitle();
	CBook* findBook(string);
	CBook* findBook1(CBook*);
	bool operator==(const CBook& other) const {
		return id == other.id; // Assuming id is a member variable of CBook
	}
};

CBook::CBook() {
	title = "<unknown>";
	id = "<unknown>";
	genre = "<unknown>";
}

void CBook::input() {
	cout << "\nEnter the title of the book: ";
	cin.ignore();
	getline(cin, title);
	cout << "Enter the ID of the book: ";
	getline(cin, id);
	cout << "Enter the genre of the book: ";
	getline(cin, genre);
}

void CBook::output() {
	cout << "\nTitle of the book: " << title << endl;
	cout << "ID of the book: " << id << endl;
	cout << "Genre of the book: " << genre << endl;
}

CBook* CBook::findBook(string id_find) {
	cout << "Comparing IDs: " << id << " and " << id_find << endl; // Debugging output

	if (id==id_find ){
		return this;
	}
	else {
		return NULL;
	}
}

CBook* CBook::findBook1(CBook* b) {
	if (id == b->id) {
		return this;
	}
	else {
		return NULL;
	}
}

string CBook::getTitle() {
	return title;
}