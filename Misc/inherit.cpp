#include<iostream>

using namespace std;

class B 
{
public :

void funB() { cout<<"----B----"<<endl; }

};

class D : public B {

public:

//void funB() { cout<<"----D----"<<endl; }


};

int main()
{
	B *bPtr;
	D dobj;
	
	bPtr = &dobj;
	
	bPtr->funB();
	
	
	
	B bobj;
	B *ptr;
	
	ptr = &bobj;
	
	ptr->funB();
	
	D *Dptr;
	
	Dptr = &dobj;
	Dptr->funB();
	
	return 0;
	

}