#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
class opera
 {
  int x,y;
  public:
	 void getdata()
    {
	cout<<"Enter X :";cin>>x;
	cout<<"Enter Y :";cin>>y;
    }
	void display()
	{
	 cout<<"X= "<<x<<endl;
	 cout<<"Y= "<<y<<endl;
	}
    /*	opera operator*(opera b)
	  {
	   opera c;
	   c.x=x*b.x;
	   c.y=y*b.y;
	   return(c);
	  }*/
	 /* opera operator>(opera b)
	   {
	    if((x>b.x)&&(y>b.y))
		{cout<<"X And Y is great";}
		    else
		    cout<<"X and Y does not exist";
		   return(0);
		   }*/
		  opera operator++(int b)
		  {
				   x++;
		   y++;
		   b.x++;
		   b.y++;
		   return(int(x,b));
		  }

	};
	int main()
	 {
	  opera o1,o2,o4,o5;
	  clrscr();
	  o1.getdata();
	  o2.getdata();
	 // o3=o1*o2;
	 // o3.display();
	 // o3=o1>o2;
	  o4=o1++;
	  o5=o2++;
	  o4.display();
	  o5.display();
	  getch();
	  return(0);
	 }




