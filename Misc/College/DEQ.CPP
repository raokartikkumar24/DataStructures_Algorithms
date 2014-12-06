#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdlib.h>
#define max 20
class deq
{
 int a[max];
 int f,r;
 public:
  deq()
   {
	r=-1;
	f=-1;
   }
   void insertfront(int x)
    {
	if(f==0)
	 {
	   cout<<"Q overflow"<<endl;
	 }
	 else if(f==-1 && r==-1)
	  {
	   r++;
	  a[f++]=x;
	   }
	  else
	   {
	    f--;
	    a[f]=x;
	   }
	}
	void deletefront()
	 {
	   int temp;
	   if(f==-1 || r==-1)
	    {
		cout<<"Q underflow"<<endl;
	    }
	    else if(f==r)
	    {
		temp=a[f];
		r=-1;
		f=-1;
		//temp=a[f];
		cout<<"The deleted item is :"<<temp<<endl;
	   }
	   else
	    {
		temp=a[f++];
		cout<<"The deleted item is : "<<temp<<endl;
	    }
	}
	void insertrear(int y)
	 {
	  if(r==max-1)
	   {
	    cout<<"Q overflow"<<endl;
	   }
	   else if(r==-1 && f==-1)
	    {
		f=0;
		a[++r]=y;
	    }
	    else
		{
		 r++;
		 a[r]=y;
		}
	  }
	  void deleterear()
	   {
	    int t;
	    if(r==-1)
		{
		 cout<<"Q underflow"<<endl;
		}
	    else if(f==r)
		{
		 t=a[r];
		 f=-1;
		 r=-1;
		 cout<<"The deleted elemnt is :"<<t<<endl;
		}
		else
		 {
		  //r--;
		  t=a[r--];
		  cout<<"The deleted element is : "<<t<<endl;
		 }
	}
	void display()
	 {
	  int i;
	   if(r==-1 || f==-1)
	    {
		cout<<"Empty Que"<<endl;
	    }
	    else
		{ cout<<"The ele are :"<<endl;
		  for(i=f;i<=r;i++)
		  {
		   cout<<a[i]<<endl;
		}  }

}  };
  int main()
   {
    deq d;
    int c;
	 clrscr();
	 do
		{
		  cout<<"**DEQ OPERATIONS**"<<endl;
		  cout<<"1.INSERTFRONT"<<endl;
		  cout<<"2.DELETEFRONT"<<endl;
		  cout<<"3.INSERTREAR"<<endl;
		  cout<<"4.DELETEREAR"<<endl;
		  cout<<"5.DISPLAY"<<endl;
		  cout<<"6.EXIT"<<endl;
		  cout<<"Enter choice "<<endl;
		  cin>>c;
		   switch(c)
		    {
			 case 1 : int b;
					cout<<"enter element to be inserted "<<endl;
					cin>>b;
					d.insertfront(b);
					break;
			 case 2 : d.deletefront();
					//cout<<"The deleted element is "<<v<<endl;
					break;
			 case 3 : int z;
					cout<<"Enter ele to be inserted :";
					cin>>z;
					d.insertrear(z);
					break;
			 case 4 : d.deleterear();
					break;
			 case 5 : d.display();
					break;
			 case 6 : exit(0);
		   }
		   }while(c!=7);
		return(0);
		}





