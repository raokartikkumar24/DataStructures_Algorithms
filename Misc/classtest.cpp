#include<iostream>
using namespace std;
class test{
public:
int x;
test *t1;
};

int main()
{
	test t2;
	cout<<endl;
	char a[128];// = "karthikrao";
	for(int i = 0 ; i < 128 ;i++)
		a[i] = 3;
	//for(int i = 0 ; i<128;i++)
	
	while( true )
		cout<<a[3]<<" ";
	return 0;
}