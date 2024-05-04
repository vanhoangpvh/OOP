#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class CEmployee {
protected:
	string id;
	string full_name;
	CDate date_birth;
	double salary;
	double basic_salary;
public:
	CEmployee();
	virtual void input();
	virtual void output();
	virtual void calculateSalary();
	virtual double getSalary();
	virtual CEmployee* findEmployee(string);
};

CEmployee::CEmployee() {
	id = "<Unknown>";
	full_name = "<Unknown>";
	date_birth = CDate();
	salary = 0;
	basic_salary = 0;
}

void CEmployee::input() {
	return;
}

void CEmployee::output() {
	return;
}

void CEmployee::calculateSalary() {
	return;
}

double CEmployee::getSalary() {
	return salary;
}

CEmployee* CEmployee::findEmployee(string id_find) {
	if (id == id_find) {
		return this;
	}
	else {
		return NULL;
	}
}