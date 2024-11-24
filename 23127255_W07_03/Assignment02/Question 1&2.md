## Header
Name: <br>
ID: 23127255

**SUMMARY**
- [Original Code](#code)
- [Question 1: What is printed to the console? Give an brief explanation](#question-1-what-is-printed-to-the-console-give-an-brief-explanation)
    + [Q1.1 Output](#1-ouput)
    + [Q1.2 Explanation](#2-explanation)
- [Question 2: Identify the memory issues in the above program and the correct them](#question-2-identify-the-memory-issues-in-the-above-program-and-the-correct-them)
	+ [Q2.1 Memory issue](#1-memory-issue)
	+ [Q2.2 Final code](#2-final-code)

## Code
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
29		return 0;
30	}
```

## Question 1: What is printed to the console? Give an brief explanation.
### 1. Ouput
```ps1
B text
A default
```

### 2. Explanation
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

In line 28, function `foo` got called with obj1 got referenced and obj2 got dereferenced before passing to `foo`<br>
In line 20, obj1 is a pointer; obj2 is a normal type. So as a result, obj1 got passed by reference but obj2 got passed by value.<br>

In function `foo`, obj1 is still the same object from previous scope while obj2 is a copy of the original object.<br>
Thus, obj1 still keep its polymorphism and obj2 lost its polymorphism.<br>
- obj1 is now an `A` pointer point to the original `B` object, so calling `obj1->display()` output `"B text"`<br>
- obj2 is now an `A` object, so calling `obj2.display()` output `"A default"` to the console.

## Question 2: Identify the memory issues in the above program and the correct them.
### 1. Memory issue
#### 1.1 Object A does not have a method to free allocated memory (deconstructor)
```cpp
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
```
**Solutions:** Add a deconstructor to free the allocated `m_s`
```cpp
1	class A{
2		char *m_s;
3	public:
4		A() { m_s = strdup("default"); }
5		~A() { delete[] m_s; }
...
12	};
```

#### 1.2 Line 27, allocated obj2 does not get freed.
```cpp
27	A *obj2 = new B(obj1);
28	foo(&obj1, *obj2);
29	return 0;
```
**Solutions:** Free obj2 when the scope is about to get freed.
```cpp
27	A *obj2 = new B(obj1);
28	foo(&obj1, *obj2);
29	delete obj2;
30	return 0;
```
#### 1.3 TODO
### 2. Final code
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
5		~A() { delete[] m_s; }
6		A(char *s) { m_s = s; }
7		virtual void prepare() { cout << "A "; }
8		void display() {
9			prepare();
10			cout << m_s << endl;
11		}
12	};
13
14	class B : public A{
15	public:
16		B(char *s) : A(s) {}
17		B(const B &b) {}
18		void prepare() { cout << "B "; }
19	};
20
21	void foo(A *obj1, A obj2) {
22		obj1->display();
23		obj2.display();
24	}
25
26	int main() {
27		B obj1("text");
28		A *obj2 = new B(obj1);
29		foo(&obj1, *obj2);
30 		delete obj2;
31		return 0;
32	}
```