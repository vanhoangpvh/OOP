#include <iostream>
#include <string>

using namespace std;

class CManagement :  public CEmployee {
protected:
	double postiton_coeff;
	double bonus;
public:
	CManagement();
	void input();
	void output();
	void calculateSalary();
	double getSalary();
	CEmployee* findEmployee(string);
};

CManagement::CManagement() {
	postiton_coeff = 0;
	bonus = 0;
}

void CManagement::input() {
	cout << "\nEnter information of Management staff:";
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
		cout << "Enter position coefficent: ";
		cin >> postiton_coeff;
		cout << "Enter bonus: ";
		cin >> bonus;
	}
	else {
		cout << "You have entered wrong syntax of date, please try again."<<endl;
		goto input_birth;
	}
	
}

void CManagement::output() {
	cout << "\n***Management Staff Imformation***";
	cout << "\nID: " << id;
	cout << "\nFull name: " << full_name;
	cout << "\nDate of birth: ";
	date_birth.outputDate();
	cout << "\nPosition Coefficent: " << fixed << setprecision(0) << postiton_coeff;
	cout << "\nBonus: " << fixed << setprecision(0) << bonus;
	cout << "\nBasic salary: " << fixed << setprecision(0) << basic_salary;
	cout << "\nSalary: " << fixed << setprecision(0) << salary;
}

void CManagement::calculateSalary() {
	salary = basic_salary * postiton_coeff + bonus;
}

double CManagement::getSalary() {
	return salary;
}

CEmployee* CManagement::findEmployee(string id_find) {
	if (id == id_find) {
		return this;
	}
	else {
		return NULL;
	}
}