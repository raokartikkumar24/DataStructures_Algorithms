#include<iostream>
#include<string>
#include<exception>

using namespace std;

class cexceptionTest 
{

public:
cexceptionTest() : id( 0 ),name("karthik")
{
	cout<<endl<<"ctor..default"<<endl;
	
}

cexceptionTest(char *_name, int _id):id(_id)
{
	cout<<endl<<"ctor...char_array"<<endl;
	strcpy(name,_name);
}


cexceptionTest(const cexceptionTest& _obj)
{
	cout<<endl<<"copy ctor.."<<endl;
	id = _obj.id;
	strcpy(name,_obj.name);
}

void test()
{
	//throw  new cexceptionTest();//throwing new pointer pointing to the class object
	throw cexceptionTest();//throwing a temp obj, will invoke copy ctor...
}

void exceptest()
{
	try
	{
		test();
	}
	
	catch(cexceptionTest &obj)//if catch(cexceptionTest cobj) is used then another call to copy ctor takes place. hence its better to have an ref
	{
		cout<<endl<<"exception caught"<<endl;
	}
	
	catch(cexceptionTest *p)
	{
		cout<<endl<<"caught in ..."<<endl;
	}
}

private:
char* name;
int id;
};


class excepderived : public exception 
{

    public:

	excepderived()
	{
		cout<<endl<<"excepderived ctor..."<<endl;
	}
	virtual const char* what() const throw()
	{
		return "Divide By zero!!";
	}
	
	void dividebyzero()
	{
		throw excepderived();
	}
	
	void causeexp()
	{
		try
		{
			dividebyzero();
		}
		
		catch(excepderived &ev)
		{
			cout<<endl<<"caused an exception of type : "<<ev.what()<<endl;
		}
	}
	
	
};


class base : public exception
{
public:
base() { cout<<endl<<"base ctor.."<<endl; }

virtual const char* what() const throw() {

	return "Exception from base";
}
void throwing()
{
	throw new base();
}
void displ()
{
	try
	{
		throwing();
	}
	
	catch(base *ptr)
	{
		cout<<endl<<"caught in base"<<endl;
	}
	
	catch(...)
	{
		cout<<endl<<"caught in base..catch..."<<endl;
	}
}



};

class derived : public base {

public:
derived() { cout<<endl<<"derived ctor.."<<endl; }

void test()
{
	throw derived();
}

void testtt()
{
	try
	{
		test();
	}
	
	catch(derived &dv)
	{
		cout<<endl<<"exception caused :"<<dv.what()<<endl;
		throw derived();
	}
	
	catch( base *ptr)
	{
		cout<<endl<<"exceotion caught in derived!.catching base pointer"<<endl;
	}
}

};


int main()
{
//char* s1 = "rao";
//cexceptionTest s(s1,24);
//cexceptionTest s2 = s;
//cexceptionTest s3(s2);

//s.exceptest();

//excepderived c;
//c.causeexp();

derived d;
d.testtt();



return 0;
}


