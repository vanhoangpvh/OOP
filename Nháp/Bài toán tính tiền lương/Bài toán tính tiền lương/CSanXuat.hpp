#include <iostream>

using namespace std;

class CProduction : public CEmployee {
protected:
	double product_number;
public:
	CProduction();
	void input();
	void output();
	void calculateSalary();
	double getSalary();
	CEmployee* findEmployee(string);
};

CProduction::CProduction() {
	product_number = 0;
}

void CProduction::input() {
	cout << "\nEnter information of production worker";
	cout << "\nEnter ID: ";
	cin.ignore();
	getline(cin, id);
	cout << "Enter full name: ";
	getline(cin, full_name);

	input_birth:
	cout << "Enter date of birth: ";
	date_birth.inputDate();
	if (date_birth.isDate()) {
		cout << "Enter basic salary: ";
		cin >> basic_salary;
		cout << "Enter number of products: ";
		cin >> product_number;
	}
	else {
		cout << "You have entered wrong syntax of date, please try again." << endl;
		goto input_birth;
	}
	
}

void CProduction::output() {
	cout << "\n***Information of production worker***";
	cout << "\nID: " << id;
	cout << "\nFull name: " << full_name;
	cout << "\nDate of birth: ";
	date_birth.outputDate();
	cout << "\nNumber of products: " << fixed << setprecision(0) << product_number;
	cout << "\nBasic salary: " << fixed << setprecision(0) << basic_salary;
	cout << "\nSalary: " << fixed << setprecision(0) << salary;
}

void CProduction::calculateSalary() {
	salary = basic_salary + product_number * 2000;
}

double CProduction::getSalary() {
	return salary;
}

CEmployee* CProduction::findEmployee(string id_find) {
	if (id == id_find) {
		return this;
	}
	else {
		return NULL;
	}
}