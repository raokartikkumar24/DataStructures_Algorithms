#include<iostream.h>
#include<iomanip.h>
#define max 5
#include<conio.h>
#include<stdlib.h>
class circle
 {
  int a[max];
  int f,r;
   public:
    circle()
	{
	  f=-1;
	  r=-1;
	}
  void insert(int x)
   {
    if((f==0 && r==max-1) || f==r+1)
	{
	 cout<<"Overflow"<<endl;
	}
	 else
	  {
	   if(f==-1 && r==-1)
	    {
		f=0;
		a[++r]=x;
	    }
	   else if(r==max-1 && f!=0)
		{
		 r=0;
		 a[r]=x;
		}
		else
		 {
		  r++;
		  a[r]=x;}
		 }
	}
	int deletec()
	 {
	   int temp;
	   if(f==-1)
	    {
		cout<<"Underflow"<<endl;
	    }
	    else if(f==r)
		{
		 temp=a[f];
		 f=-1;
		 r=-1;
		 cout<<"The deleted element is : "<<temp<<endl;
		}
	    else if(f==max-1)
		{
		 temp=a[f];
		 f=0;
		 cout<<"The deleted element is : "<<temp<<endl;
		}
		  else
		   {
			temp=a[f];
			f++;
		    cout<<"The dele element is : "<<temp<<endl;
		   }
		}
	   void display()
	    {
		int i,j;
		 if(f==-1)
		  {
		    cout<<"Q empty"<<endl;
		  }
		 else if(f>r)
		  {
		    cout<<"The Q elements are :"<<endl;
		    for(i=f;i<=max-1;i++)
			{cout<<a[i]<<endl;}
			for(i=0;i<=r;i++)
			  {
			   cout<<a[i]<<endl;
			  }
		    }
		   else
		    {
			cout<<"The Q elements are :"<<endl;
			for(i=f;i<=r;i++)
			 {
			  cout<<a[i]<<endl;
			 }
		    }
		 }
	   };
	    int main()
		{
		 circle c;
		 int p;
		 clrscr();
	    do
		{
		  cout<<"** CIRCLE OPERATIONS**"<<endl;
		  cout<<"1.INSERT"<<endl;
		  cout<<"2.DELETE"<<endl;
		  cout<<"3.DISPLAY"<<endl;
		  cout<<"4.EXIT"<<endl;
		  /*cout<<"5.DISPLAY"<<endl;
		  cout<<"6.EXIT"<<endl;*/
		  cout<<"Enter choice "<<endl;
		  cin>>p;
		   switch(p)
		    {
			 case 1 : int x;
					cout<<"Enter element to be inserted "<<endl;
					cin>>x;
					c.insert(x);
					break;
			 case 2 : c.deletec();
					break;
			 case 3 : c.display();
					break;
			 case 4 : exit(0);
		    }
	   }while(p!=5);
	   getch();
	return(0);
   }

















