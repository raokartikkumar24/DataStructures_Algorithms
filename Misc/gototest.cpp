#include<iostream>

using namespace std;

int foo()
{
int x =0;
goto end;
goto start;
start:
 x = 10;

end:
return x;
}

int sample()
{
	cout<<"ret : "<<foo()<<endl;
	return(1);
}

int main()
{

int x=sample();


return 0;
}