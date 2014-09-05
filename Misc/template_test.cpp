#include<iostream>
#include<string>
using namespace std;

template<class T>
void function(T x, T y)
{
	cout<<x<<" :: " <<y<<endl;
}


template<class T>
class ctemplate {
public:
ctemplate(T val, int k) : value(val),key(k)  { }

void display()
{
	cout<<endl<<key<<" :: "<<value<<endl;
}



private:
T value;
int key;
};

template<class Sam1, class Sam2>
class ctemplate2 {
public:
ctemplate2(Sam1 _s, Sam2 _ss) : s(_s),s2(_ss) { }

void display()
{
	cout<<endl<<s<<" : : "<<s2<<endl;
}


private:
Sam1 s;
Sam2 s2;
};


int main()
{
	function(10,20);
	function(20.3,34.56);
	function('a','b');
	
	cout<<endl;
	
	ctemplate<int> t(1,12);
	t.display();
	
	ctemplate<float> t2(1,13.45);
	t2.display();
	
	ctemplate<int> *t_ptr = new ctemplate<int>(34,5);
	t_ptr->display();
	
	ctemplate2<int,int> ct(1,10);
	ct.display();
	
	ctemplate2<string,string> sct("karthik","rao");
	sct.display();
	
	return 0;
}

