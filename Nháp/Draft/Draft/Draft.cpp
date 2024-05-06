#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Many to many relationship

class CCourse;

class CStudent {
private:
	string id;
	string full_name;
	vector<CCourse*> list_courses;
public:
	//Constructor
	CStudent(string, string);
	//Getter
	string getId();
	string getFullName();
	vector<CCourse*> getListCourses();
	//Method
	void display();
	void enrollCourse(CCourse* crs);
};

class CCourse {
private:
	string id;
	string full_name;
	vector<CStudent*>list_students;
public:
	//Constructor
	CCourse(string crs_id, string crs_name);
	//Getter
	string getId();
	string getFullName();
	vector <CStudent*> getListStudents();
	//Method
	void display();
	void addStudent(CStudent* st);
};

int main() {

	CStudent* student1 = new CStudent("1","Hoang");
	CStudent* student2 = new CStudent("2", "Phuc");

	CCourse* course1 = new CCourse("001", "Math");
	CCourse* course2 = new CCourse("002", "English");
	CCourse* course3 = new CCourse("003", "History");

	student1->enrollCourse(course1);
	student1->enrollCourse(course2);
	student2->enrollCourse(course2);
	student2->enrollCourse(course3);

	cout << "Student 1:" << endl;
	student1->display();
	cout << "\nStudent 2:" << endl;
	student2->display();

}

CStudent::CStudent(string stu_id, string stu_name) {
	id = stu_id;
	full_name = stu_name;
}

string CStudent::getId() {
	return id;
}

string CStudent::getFullName() {
	return full_name;
}

vector <CCourse*> CStudent::getListCourses() {
	return list_courses;
}

void CStudent::enrollCourse(CCourse* crs) {
	list_courses.push_back(crs);
	crs->addStudent(this);
}

CCourse::CCourse(string crs_id, string crs_name) {
	id = crs_id;
	full_name = crs_name;
}

string CCourse::getId() {
	return id;
}

string CCourse::getFullName() {
	return full_name;
}

vector <CStudent*> CCourse:: getListStudents() {
	return list_students;
}

void CCourse::addStudent(CStudent*st) {
	list_students.push_back(st);
}

void CStudent::display() {
	cout << "\nID: " << id;
	cout << "\nFull name: " << full_name;
	for (CCourse* element : list_courses) {
		cout << "-" << element->getId() << ": " << element->getFullName() << endl;
	}
}

void CCourse::display() {
	cout << "\nID: " << id;
	cout << "\nFull name: " << full_name;
	for (CStudent* element : list_students) {
		cout << "-" << element->getId() << ": " << element->getFullName() << endl;
	}
}

