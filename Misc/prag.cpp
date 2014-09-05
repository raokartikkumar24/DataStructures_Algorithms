#include<iostream>
using namespace std;

#pragma pack(1)

struct xyz {
char a;
int b;
char c;

};
#pragma pop()
int main()
{
	cout<<sizeof( xyz )<<endl;
	
	return 0;

}

