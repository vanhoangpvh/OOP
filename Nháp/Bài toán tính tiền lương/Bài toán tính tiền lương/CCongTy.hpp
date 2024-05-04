#include <iostream>
#include <vector>

using namespace std;

class CCompany {
protected:
	int number_employees;
	vector<CEmployee*> list_employees;
public:
	CCompany();
	void input();
	void output();
	void calculateSalary();
	double sumSalary();
	CEmployee* findEmployee(string);
};

CCompany::CCompany() {
	number_employees = 1;
	for (int i = 0; i < number_employees; i++) {
		list_employees.push_back(new CEmployee());
	}
}

void CCompany::calculateSalary() {
	for (CEmployee* element : list_employees) {
		element->calculateSalary();
	}
}

double CCompany::sumSalary() {
	double sum = 0;
	for (CEmployee* element : list_employees) {
		sum = sum + element->getSalary();
	}
	return sum;
}

CEmployee* CCompany::findEmployee(string id_find) {
	for (CEmployee* element : list_employees) {
		CEmployee* temp = element->findEmployee(id_find);
		if (temp) {
			return temp;
		}
	}
	return NULL;
}

void CCompany::output() {
	cout << "~~~~List of employees in company~~~~\n";
	cout << "Number of employees: " << number_employees << endl;
	for (CEmployee* element : list_employees) {
		element->output();
	}
}

void CCompany::input() {
	cout << "~~~~Input employees information~~~~" << endl;
	cout << "Enter number of employees: ";
	cin >> number_employees;
	for (int i = 0; i < number_employees; i++) {
		int choice;
		cout << "\nInput employee "<<i+1<<": " << endl;
		cout << "Choose one of these choices (Employee type):" << endl;
		cout << "1. Management" << endl;
		cout << "2. Production" << endl;
		cout << "3. Office" << endl;
		cout << "Your choice is: ";
		cin >> choice;

		CEmployee* element = new CEmployee;
		switch (choice) {
		case 1:
			element = new CManagement;
			break;
		case 2:
			element = new CProduction;
			break;
		case 3:
			element = new COffice;
			break;
		}
		element->input();
		list_employees.push_back(element);
	}
}