#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <sstream>

class Student{
	int id;
	char* fullname;
	char* address;
	double gpa;
public:
	Student();
	Student(int _id, const char* _fullname);
	Student(int _id, const char* _fullname, const char* _address);
	Student(int _id, const char* _fullname, const char* _address, double _gpa);
	Student(const Student& other);
	Student(const std::string &s);
	Student clone();
	std::string toString() const;
	Student(Student&& other) noexcept;
	~Student();
	int getID() const;
	double getGPA() const;
	std::string getFullName() const;
	std::string getAddress() const;
};

#endif //STUDENT_H
