#include<iostream>
using namespace std;

class myclass {
public:
int x;
float y;

};

struct mystruct {

int x;
float y;

};
int main()
{
	mystruct st = {0};
	cout<<st.y<<endl<<st.x<<endl;
	myclass cs = 0;
	cout<<cs.x<<endl<<cs.y<<endl;
	return 0;
	
}