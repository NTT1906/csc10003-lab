## Question 1:
### 1. Code
```cpp
-5	#include <iostream>
-4	using namespace std;
-3	
-2	#include "cstring"
-1
1	class A{
2		char *m_s;
3	public:
4		A() { m_s = strdup("default"); }
5		A(char *s) { m_s = s; }
6		virtual void prepare() { cout << "A "; }
7		void display() {
8			prepare();
9			cout << m_s << endl;
10		}
11	};
12
13	class B : public A{
14	public:
15		B(char *s) : A(s) {}
16		B(const B &b) {}
17		void prepare() { cout << "B "; }
18	};
19
20	void foo(A *obj1, A obj2) {
21		obj1->display();
22		obj2.display();
23	}
24
25	int main() {
26		B obj1("text");
27		A *obj2 = new B(obj1);
28		foo(&obj1, *obj2);
29	
30		return 0;
31	}
```
### 2. Ouput
```ps1
B text
A default
```

### 3. Explanation
```cpp
26	B obj1("text")
```
In line 26, object obj1: B was created as an object saved in stack using constructor with input `char *` -> A(char *) got called then B(char *) -> obj1's **m_s** is `"text"`
```cpp
27	A *obj2 = new B(obj)
```
In line 27, object `obj2: A *` was allocated by copying obj1 using copy constructor of B. But the copy constructor of B
override the default one and do nothing (no calling A's copy constructor + no body)
-> A's default constructor got called. -> obj2's **m_s** is `"default"`

```cpp
20	void foo(A *obj1, A obj2) {
21		obj1->display();
22		obj2.display();
...
26		B obj1("text");
27		A *obj2 = new B(obj1);
28		foo(&obj1, *obj2);
```

In line 28, function `foo` got called with obj1 got pass by referenced and obj2 got dereferenced.<br>
In line 20, obj1 is a pointer; obj2 is a normal type. So as a result, obj1 got passed by reference but obj2 got passed by value.<br>

In function `foo`, obj1 is still the same object from previous scope while obj2 is a copy of the original object.<br>
Thus, obj1 still keep its polymorphism and obj2 lost its polymorphism.<br>
- obj1 is now an `A` pointer point to the original `B` object, so calling `obj1->display()` output `"B text"`<br>
- obj2 is now an `A` object, so calling `obj2.display()` output `"A default"` to the console.