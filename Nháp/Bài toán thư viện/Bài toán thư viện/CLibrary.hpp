#include <iostream>
#include <vector>

using namespace std;

class CLibrary {
protected:
	int number_books;
	vector <CBook*> list_books;
public:
	CLibrary();
	void input();
	void output();
	CBook* findBook(string);
	CBook* findBook1(CBook*);
};

CLibrary::CLibrary() {
	number_books = 1;
}

void CLibrary::input() {
	cout << "\nEnter numbers of books you want to add in Lirary: ";
	cin >> number_books;
	for (int i = 0; i < number_books; i++) {
		cout << "\n\nEnter book number " << i + 1 << ":\n";
		CBook* element = new CBook;
		element->input();
		list_books.push_back(element);
	}
}

void CLibrary::output() {
	cout << "\nNumber of books in Library: " << number_books;
	cout << "\nInformation of books:" << endl;

	int run = 1;
	for (CBook* element : list_books) {
		cout << "\nInformation of book " << run << ":";
		element->output();
		cout << endl;
		run++;
	}
}

CBook* CLibrary::findBook(string id_find) {
	for (CBook* element : list_books) {
		CBook* temp = element->findBook(id_find);
		if (temp) {
			return temp;
		}
	}
	return NULL;
}

CBook* CLibrary::findBook1(CBook* b1) {
	for (CBook* element : list_books) {
		CBook* temp = element->findBook1(b1);
		if (temp) {
			return temp;
		}
	}
	return NULL;
}
