#include<iostream>

using namespace std;

class base {

public:
base() { cout<<"base::ctor"<<endl; }

virtual ~base() { cout<<"base::destructor"<<endl; }


};

class derived :public base {
public:
derived() { cout<<"derived::ctor"<<endl; }

~derived() { cout<<"derived::dtor"<<endl; }

};

int main()
{

base *ptr = new derived();

delete ptr;

return 0;

}