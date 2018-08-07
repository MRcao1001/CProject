#include <iostream>
using namespace std;

class Bird
{
public:
	Bird(string tail = "五彩神光")
	{
		m_strTail = tail;
	}
	void work()
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
	void work()
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
//		showTail();
//		shakeNose();
		Bird::work();
		Elephant::work();	
		cout << m_strSkill << endl;
	}

private:
	string m_strSkill;
};

int main(void)
{
	Kongfu k;
	k.work();
		
	return 0;
}
