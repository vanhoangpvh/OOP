#include <iostream>
#include <cstdlib>
#include "CDate.hpp"
#include "CNhanVien.hpp"
#include "CQuanLy.hpp"
#include "CSanXuat.hpp"
#include "CVanPhong.hpp"
#include "CCongTy.hpp"

using namespace std;

int main() {

	CCompany* company = new CCompany;
	//Input employees of comany
	company->input();
	system("cls");

	//Output employees of company
	company->calculateSalary();
	company->output();

	//Sum of salarys in company
	cout << "\n\nSum of salarys in company is: " << company->sumSalary();

	//Find employee using id
	cout << "\n\nFinding Employee using ID:" << endl;
	cout << "Enter ID you want to find in list of employees: ";
	string id_find;
	cin.ignore();
	getline(cin, id_find);

	CEmployee* employee_find = company->findEmployee(id_find);
	if (employee_find) {
		cout << "\nID that you want to find correspond to this information:" << endl;
		employee_find->output();
	}
	else {
		cout << "\n Can't find ID that you want to find";
	}

	return 1;
}