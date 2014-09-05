#include<iostream>

using namespace std;

int Up(int _val)
{
	int v;
	// cout<<"Inside Up "<<endl;
	if( v < 5 ) return v;
	v = Up(_val-1);
	return v;
}


int main()
{
cout<<"value : "<<Up(5)<<endl;
return 0;

}