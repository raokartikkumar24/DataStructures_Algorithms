#include<iostream>

using namespace std;

int main()
{
	int a = 10, b =100;
	int &ref = a;
	
	int *ptr = &b;
	
	cout<<"a :"<<a<<endl;
	cout<<"b : "<<b<<endl;
	cout<<"&a : "<<&a<<endl;
	cout<<"ref : "<<ref<<endl;
	cout<<"&ref :"<<&ref<<endl;
	//cout<<"*ref :"<<*ref<<endl; //Invalid type of unary..cannot apply for the refrence
	cout<<"ptr : "<<ptr<<endl;
	cout<<"*ptr : "<<*ptr<<endl;
	cout<<"&ptr : "<<&ptr<<endl;
	
	
	return 0;
}