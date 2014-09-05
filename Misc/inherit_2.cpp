#include<iostream>
using namespace std;
class base {
public:
virtual void display();

};

class derived : base  {

public:
char a_;
unsigned int b_;
bool *c_;

virtual void donothing();

};

int main()
{
	cout<<sizeof(derived)<<endl;
	
	return 0;

}