#include <iostream>
using namespace std;

class Bird
{
public:
	Bird(string tail = "五彩神光")
	{
		m_strTail = tail;
	}
	void showTail()
	{
		cout << m_strTail << endl;
	}
private:
	string m_strTail;
};

class Elephant
{
public:
	Elephant(string nose = "大鼻涕")
	{
		m_strNose = nose;
	}
	void shakeNose()
	{
		cout << m_strNose << endl;
	}
private:
	string m_strNose;
};

class Kongfu: public Bird, public Elephant
{
public:
	Kongfu(string tail, string nose
		   , string skill)
		: Bird(tail), Elephant(nose)
		  , m_strSkill(skill)
	{
	}
	//默认调用基类的构造函数
	Kongfu() : m_strSkill("寸拳")
	{}

	void work()
	{
		showTail();
		shakeNose();
		cout << m_strSkill << endl;
	}

private:
	string m_strSkill;
};

int main(void)
{
	cout << sizeof(Kongfu) << endl;

	Kongfu k;
	k.work();
//	k.showTail();
//	k.shakeNose();

#if 0
	Bird b("孔雀开屏");
	b.showTail();

	Elephant e("冬阴功");
	e.shakeNose();
#endif
	return 0;
}
