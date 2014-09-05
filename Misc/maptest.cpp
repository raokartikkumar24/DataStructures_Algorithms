#include<iostream>
#include<map>
using namespace std;
int main()
{
	map<int,int> maptest;
	maptest[1] = 100;
	maptest[1] = 200;
	
	cout<<maptest[1]<<endl;
	
	return 0;
}
