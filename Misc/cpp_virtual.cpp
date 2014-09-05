#include<iostream>
using namespace std;

class base 
{
public:
 void print() { cout<<"base::print()"<<endl; print2();}
virtual void print2() { cout<<"base::print2()"<<endl; }

virtual ~base() { cout<<"base's dtor called"<<endl; }

base() { }
};

class derived : public base
{
 public:
 void print() { cout<<"derived::print()"<<endl; print2(); }
 void print2() { cout<<"derived::print2()"<<endl; }
 
 derived() { }
 
 
 ~derived() { cout<<"derived's dtor called"<<endl; }

};

int main()
{
	// base *bp = new derived;
	// bp->print();
	void *vptr = new base();
	delete static_cast<base*>(vptr);
	cout<<endl;
	return 0;

}