#include <iostream>
using namespace std;

#include "cstring"

class A{
	char *m_s;
public:
	A() {
		cout << "Default A got called!\n";
		m_s = strdup("default");
	}
	A(char *s) {
		cout << "Input char * A got called\n";
//		m_s = s;
		m_s = strdup(s);
	}
	A(const A &other) {
		cout << "Copy A got called!\n";
		m_s = strdup(other.m_s);
	}
	virtual void prepare() { cout << "A "; }
	void display() {
		this->prepare();
		cout << m_s << endl;
	}
	virtual ~A() {
		cout << "Destroying ";
		display();
		delete m_s;
	}
};

class B : public A{
public:
	B(char *s) : A(s) {
		cout << "Input char * B got called\n";
	}
	B(const B &b) {
		cout << "Copy B got called\n";
	}
	void prepare() { cout << "B "; }
	~B() override {
	};
};

void foo(A *obj1, A obj2) {
	(*obj1).display();
//	A tmp = *obj1;
//	tmp.display();
	obj1->display();
	obj2.display();
	(&obj2)->display();
}

int main() {
	B obj1("text");
	std::cout << "Obj1    : ";
	obj1.display();
	std::cout << "Obj1 REF: ";
	(&obj1)->display();
	A *obj2 = new B(obj1);
	obj2->display();
	std::cout << "Obj2 DEREF: ";
	(*obj2).display();
	foo(&obj1, *obj2);
	delete obj2;
	return 0;
}
