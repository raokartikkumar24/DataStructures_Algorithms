#include<iostream>

using namespace std;

class test
{
public:
test() : x(100) { }
void display()
{
	cout<<endl<<x<<endl;
}

static void dis()
{	
	test a;
	a.display();
	
}
private:
int x;
static int y;
};

int test::y = 0;

int main()
{

	test t1;
	t1.dis();
	return 0;
}