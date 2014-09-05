#include<iostream>
using namespace std;
union theunion
{
	int x;
	char y;
};
	struct mystruct
	{
		char az;
		int a[2];
		int x;
		theunion un[2];
		
	};
	
	struct st
	{
		int a[10];
		char b[10];
		int x;
		float y;
	};
class carr
{
	public:
	int a[3];
	//mystruct thestruct;
	//st _st;
	carr() 
	{
		
		//memset(a,0,sizeof(a));
		//cout<<"size : "<<sizeof(_st.a)<<endl;
		//memset(_st.a,0,sizeof(_st.a));
		//memset(_st.b,0,sizeof(_st.b));
		//_st.x = 0;
		//_st.y = 0.0;
		
		/*thestruct.x = 0;
		memset(thestruct.a,0,sizeof(thestruct.a));
		thestruct.az = 'k';
		//thestruct.un.x =12345;
		//thestruct.un.y='A';
		for(int i = 0 ; i < 2; i++)
			memset(&thestruct.un[i],0,sizeof(theunion));*/
		
	}
	
	void disp()
	{
	
		cout<<a[0]<<a[1]<<a[2]<<endl;
		int aa[3] = {0};
		
		cout<<aa[0]<<aa[1]<<aa[2]<<endl;
		
		/*for(int i = 0 ; i < 3 ; i++)
			cout<<a[i]<<endl;
			
		cout<<"size : "<<sizeof(_st.a)<<endl;
		cout<<_st.x<<" "<<_st.y<<endl;	*/
			
			
		/*cout<<sizeof(a)<<endl;
		cout<<"thestruct size : "<<sizeof(thestruct.a)<<endl;;
		
		for(int i = 0 ; i < 2 ; i++)
			cout<<thestruct.a[i]<<endl;
			
		cout<<"az : "<<thestruct.az<<endl;
		
		cout<<thestruct.x<<endl;
		
		cout<<"Union stuff"<<endl;
		cout<<thestruct.un.x<<" "<<thestruct.un.y<<endl;*/
		
	}
	
};
int main()
{
carr ca;
ca.disp();
return 0;
}