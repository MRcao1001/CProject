#include <iostream>
#include <string>

using namespace std;

class Sample
{
public:
	Sample(int n = 0):m_n(n)
	{}

	Sample add(const Sample &other)
	{
		//return Sample(m_n+other.m_n);
		Sample s;
		s.m_n = m_n+other.m_n;
		return s;
	}
	int getData()
	{
		return m_n;
	}
private:
	int m_n;
};

int main(void)
{
	Sample s1(10);
	Sample s2(20);
	Sample s3(30);
	Sample s4(40);

	int val = s1.add(s2).add(s3).add(s4).getData();
	cout << val << endl;

	//int iResult = s1.add(s2) + s3.add(s4);
	//cout << iResult << endl;

	return 0;
}
