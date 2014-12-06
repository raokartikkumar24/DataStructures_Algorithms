#include<iostream.h>
#include<stdio.h>
#include<conio.h>
int gcd(int x,int y)
{
	//cout<<"gcd"<<endl;

	while(x%y!=0)
	{
		cout<<"gcd"<<endl;
		gcd(y,x%y);

		if(x%y==0)
		{break;}
	}
	return y;
}
void main()
{
	int a,b,temp,min,max;
	clrscr();
	cout<<"Enter a and b :";
	cin>>a>>b;
	if(a>b)
	{
		//max=a;
		//min=b;
		temp=gcd(a,b);
	}
	else
	{
		//max=b;
		//min=a;
	    temp=gcd(b,a);
	}
	//temp=gcd(max,min);
	cout<<"GCD = "<<temp;
	getch();
  }




