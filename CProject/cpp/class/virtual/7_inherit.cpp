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
//虚继承
class B: virtual public A
{
public:
	B(int a, int b):A(a), m_b(b){}
	int m_b;
};

class C: virtual public A
{
public:
	C(int a, int c):A(a), m_c(c){}
	int m_c;
};

//被虚继承的基类右最派生类真正继承
class D: public B, public C
{
public:
	D(int a, int b, int c, int d)
		: B(a, b), C(a, c), m_d(d)
		  , A(998)
	{}
	int m_d;
};

int main(void)
{
	D d(1, 2, 3, 4);
	d.B::info();	

	cout << sizeof(A) << endl;	
	cout << sizeof(B) << endl;	
	cout << sizeof(C) << endl;	
	cout << sizeof(D) << endl;	
#if 0
	D d(1, 2, 3, 4);
	//d.B::info();
	//d.C::info();
	d.A::info();

	//若类B产生对象，则类B是最派生类
	//真正继承A
	B b(34, 89);
	b.info();
#endif
	return 0;
}
