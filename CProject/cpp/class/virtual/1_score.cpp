#include <iostream>
#include <string>

using namespace std;

class Score
{
public:
	Score(string name = ""
		  , float math = 0
		  , float english = 0
		  , float code = 0)
		: m_iId(m_iBasicId++)
		 , m_strName(name)
		 , m_fMath(math)
		 , m_fEnglish(english)
		 , m_fCode(code)
		 , m_fAvgScore(0)
	{
	
	}

	void inScore()
	{
		cout << "请输入学号为" << m_iId 
			 << "的数学,英语,编程成绩:\n";
	    cin >> m_fMath >> m_fEnglish >> m_fCode;
		m_fAvgScore =  (m_fMath+m_fEnglish+m_fCode)/3;	
	}

	void showScore()
	{
		cout << "学号:" << m_iId
			 << " 数学成绩:" << m_fMath
			 << " 英语成绩:" << m_fEnglish
			 << " 编程成绩:" << m_fCode
			 << " 平均成绩:" << m_fAvgScore
			 << endl;
	}

private:
	static int m_iBasicId;
	const int m_iId;
	string m_strName;
	float m_fMath;
	float m_fEnglish;
	float m_fCode;
	float m_fAvgScore;
};

int Score::m_iBasicId = 1000;

int main(void)
{
	int iNum = 0;
	cout << "请输入学生的个数:\n";
	cin >> iNum;
	
	Score *p = new Score[iNum];
	for (int i=0; i<iNum; i++)
	{
		p[i].inScore();
	}
	
	for (int i=0; i<iNum; i++)
	{
		p[i].showScore();
	}
	delete []p;
	p = NULL;

	return 0;
}
