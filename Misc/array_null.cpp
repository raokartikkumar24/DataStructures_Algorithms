#include<iostream>
using namespace std;

int main()
{
int *ptr[0];
if( ptr == NULL ) cout<<"null"<<endl;
else cout<<"not null"<<endl;
return 0;
}