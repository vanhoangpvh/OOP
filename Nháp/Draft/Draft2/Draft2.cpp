#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Professor;

class Student {
private:
	int id;
	string name;
	vector <Professor*> list_professors;
public:
	Student(int, string);
	int getId();
	string getName();
	void enrollProfessor(Professor* pro);
	void display();
};

class Professor {
private:
	string name;
	vector<Student*>list_students;
public:
	Professor(string);
	string getName();
	void addStudent(Student* stu);
	void display();
};

int main() {
	//Create 3 students
	Student* student1 = new Student(22280006, "Bao");
	Student* student2 = new Student(22280033, "Hoang");
	Student* student3 = new Student(22280066, "Phuc");

	//Create 2 professors
	Professor* professor1 = new Professor("Ha Van Thao");
	Professor* professor2 = new Professor("Nguyen Hien Luong");

	//First 2 student enroll with 2 professors
	student1->enrollProfessor(professor1);
	student1->enrollProfessor(professor2);
	student2->enrollProfessor(professor2);
	student2->enrollProfessor(professor1);
	
	//The third student enrolls second professor
	student3->enrollProfessor(professor2);
	
	//Display students
	cout << "Students informations:" << endl;
	cout << "\n**Student 1:" << endl;
	student1->display();
	cout << "\n**Student 2" << endl;
	student2->display();
	cout << "\n**Student 3:" << endl;
	student3->display();

	//Display professors
	cout << "\nProfessors informations:" << endl;
	cout << "\n**Professor 1:" << endl;
	professor1->display();
	cout << "\n**Professor 2:" << endl;
	professor2->display();

	return 1;
}

Student::Student(int student_id, string student_name) {
	id = student_id;
	name = student_name;
}

int Student::getId() {
	return id;
}

string Student::getName() {
	return name;
}

Professor::Professor(string professor_name) {
	name = professor_name;
}

string Professor::getName() {
	return name;
}

void Student::enrollProfessor(Professor* pro) {
	list_professors.push_back(pro);
	pro->addStudent(this);
}

void Professor::addStudent(Student* stu) {
	list_students.push_back(stu);
}

void Student::display() {
	cout << "ID: " << id << endl;
	cout << "Name: " << name << endl;
	cout << "List professors that student enrolls:" << endl;
	for (Professor* element : list_professors) {
		cout << "Name: " << element->getName() << endl;
	}
}

void Professor::display() {
	cout << "Name: " << name << endl;
	cout << "List students enroll:" << endl;
	for (Student* element : list_students) {
		cout << "ID: " << element->getId() << endl;
		cout << "Name: " << element->getName() << endl;
	}
}