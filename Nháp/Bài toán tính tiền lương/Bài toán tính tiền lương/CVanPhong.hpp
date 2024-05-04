#include <iostream>

using namespace std;

class COffice : public CEmployee{
protected:
	double day_work;
	double allowance;
public:
	COffice();
	void input();
	void output();
	void calculateSalary();
	double getSalary();
	CEmployee* findEmployee(string);
};

COffice::COffice() {
	day_work = 0;
	allowance = 0;
}

void COffice::input() {
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
		cout << "Enter number of day works: ";
		cin >> day_work;
		cout << "Enter allowance: ";
		cin >> allowance;
	}
	else {
		cout << "You have entered wrong syntax of date, please try again." << endl;
		goto input_birth;
	}
}

void COffice::output() {
	cout << "\n***Information of office staff***";
	cout << "\nID: " << id;
	cout << "\nFull name: " << full_name;
	cout << "\nDate of birth: ";
	date_birth.outputDate();
	cout << "\nNumber of day works: " << fixed << day_work;
	cout << "\nAllowance: " << fixed << setprecision(0) << allowance;
	cout << "\nBasic salary: " << fixed << setprecision(0) << basic_salary;
	cout << "\nSalary: " << fixed << setprecision(0) << salary;
}

void COffice::calculateSalary() {
	salary = basic_salary + day_work * 1000000 + allowance;
}

double COffice::getSalary() {
	return salary;
}

CEmployee* COffice::findEmployee(string id_find) {
	if (id == id_find) {
		return this;
	}
	else {
		return NULL;
	}
}