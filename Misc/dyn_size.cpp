#include<iostream>
using namespace std;

class cdyn
{
public:
cdyn() : a(0),b(0.0),c('a') {

 }

	private:
	char c;
	int a;
	float b;
	
	//int a1[10];
};

int main()
{
	cdyn obj;
	cdyn *p =  new cdyn();
	cout<<endl<<sizeof(*p)<<endl;
	cout<<"Address is : "<<&p<<endl;
	p++;
	cdyn *p2 = p;
	cout<<"incremented address : "<<&p2<<endl;
	//cout<<p2-p<<endl;
	cout<<"Size is : "<< (int)&p - (int)&p2 <<endl;
		return 0;
	
}
