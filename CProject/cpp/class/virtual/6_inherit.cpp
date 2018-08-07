#include <iostream>
using namespace std;

class A
{
public:
	A(int a):m_a(a){}
	int m_a;
	void info()
	{
		cout << m_a << endl;
	}
};

class B: public A
{
public:
	B(int a, int b):A(a), m_b(b){}
	int m_b;
};

class C: public A
{
public:
	C(int a, int c):A(a), m_c(c){}
	int m_c;
};

class D: public B, public C
{
public:
	D(int a, int b, int c, int d)
		: B(a, b), C(a, c), m_d(d)
	{}
	int m_d;
};

int main(void)
{
	cout << sizeof(A) << endl;	
	cout << sizeof(B) << endl;	
	cout << sizeof(C) << endl;	
	cout << sizeof(D) << endl;	

	D d(1, 2, 3, 4);
	//d.B::info();
	//d.C::info();
	//d.A::info();  //X

	return 0;
}
