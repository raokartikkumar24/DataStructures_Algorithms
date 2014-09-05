#include<iostream>
using namespace std;

class CStatic {

public:

static int s_num;

static int getNum() { return s_num ; }

int get() { return s_num; }

};

int CStatic::s_num = 100;

int main()
{

	cout<<CStatic::getNum()<<endl;

	CStatic cs;
	cout<<cs.get()<<endl;

	return 0;
}
