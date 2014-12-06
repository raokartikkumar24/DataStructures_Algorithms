#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 10
class stack
 {
  int a[MAX];
  int top;
   public:
    stack()
	 {
	   top=-1;
	 }
	 void push(char x)
	   {
		if(top==MAX)
		 {
		   cout<<"Stack overflow";
		 }
		 else
		 { x=a[++top];

		 }
	   }
	   int pop()
	    {
		if(top==-1)
		 {
		  cout<<"Stack ovwerflow";
		 }
		 else
		 {a[top--];}
	  }
	};
	int main()
	 {
	  stack s;
	  char str[20],temp;
	  int i,len;
	   clrscr();
	   len=strlen(str);
	  cout<<"Enter string"<<endl;
	  cin>>str;
	  //cout<<strrev(str);
	   for(i=0;i<len;i++)
	   {
	   s.push(str[i]);}

		 for(i=0;i<len;i++)
		{
		  cout<<s.pop();
		}


	    getch();
	    return (0);

}
