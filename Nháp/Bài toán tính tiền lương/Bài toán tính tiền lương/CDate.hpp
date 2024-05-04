#include <iostream>

using namespace std;

class CDate {
protected:
	int day;
	int month;
	int year;
public:
	CDate();
	void inputDate();
	void outputDate();
	int isDate();
	CDate& operator=(CDate);
};

CDate::CDate() {
	day = 1;
	month = 1;
	year = 1;
}

CDate& CDate::operator=(CDate d) {
	day = d.day;
	month = d.month;
	year = d.year;
	return (*this);
}

void CDate::inputDate() {
	cout << endl;
	cout << "Enter day: ";
	cin >> day;
	cout << "Enter month: ";
	cin >> month;
	cout << "Enter year: ";
	cin >> year;
}

void CDate::outputDate() {
	cout << day << " / " << month << " / " << year;
}

int CDate:: isDate() {
	//Check year
	if (year < 1) {
		return 0;
	}

	//Check month
	if (month <= 0 || month >= 13) {
		return 0;
	}

	//Check day
	if (day <= 0||day>=32) {
		return 0;
	}
	else {
		switch (month) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (day >= 32) {
				return 0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (day >= 31) {
				return 0;
			}
			break;
		case 2:
			if (year % 4 == 0) {
				if (day >= 30) {
					return 0;
				}
			}
			else {
				if (day >= 29) {
					return 0;
				}
			}
			break;

		}
	}
		return 1;
}