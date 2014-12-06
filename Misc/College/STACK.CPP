#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#define max 5
class stack
{
 protected:
 int st[max];
 int top;
 public:
 stack()
 {
  top=-1;
 }
 void push()
 {
 int item;
 cout<<"enter the item to push";
 cin>>item;
 top++;
 st[top]=item;
 }
 int pop()
 {
  int item;

  item=st[top];
  top--;
  return(item);
 }
 void display()
 {
    {
	  if(top==MAX-1)
	    {
		 cout<<"Stack overflow "<<endl;
	    }
		 else
		  {
		    a[++top]=n;
		  }
	 }
	 int pop()
	  {
			int temp;
			if(top==-1)
		 {
		   cout<<"Stack underflow"<<endl;
		 }
		 else
		  {
			temp=a[top--];
			cout<<"The popped element is "<<temp<<endl;
		  }
	 }
  cout<<"\n the stack contains\n"<<endl;
  for(int i=top;i>=0;i--)
  cout<<st[i]<<endl;
 }
};
class stack_cond:public stack
{
 public:
  void push()
  {
  if(top==max-1)
  cout<<"\n stack overflow"<<endl;
  else
  {
   stack::push();
   if(top==max-1)
   cout<<endl<<"after push stack is full"<<endl;
   }
  }
  int pop()
  {
  int item;
  if(top==-1)
  {
   cout<<endl<<"stack is overflow"<<endl;
   return NULL;
  }
  else
  {
   item=stack::pop();
   if(top==-1)
   cout<<endl<<"after pop stack is empty"<<endl;
   return(item);
  }
 }
 void display()
 {
  if(top==-1)
  cout<<"stack is empty"<<endl;
 else
 stack::display();
}
};
void main()
{
 stack_cond s;
 int choice;
 cout<<"Program for stack using inheritance\n";
 do
 {
  clrscr();
  cout<<"1.push\n";
  cout<<"2.pop\n";
  cout<<"3.display\n";
  cout<<"4.exit\n";
  cout<<"enter your choice:";
  cin>>choice;
  switch(choice)
  {
  case 1:s.push();
	    s.display();
	    break;
  case 2:s.pop();
  s.display();

	    /*choice=s.pop();
	    if(choice!=0)
	    cout<<endl<<"the item"<<choice<<"is poped from the top of the stack"<<endl;
	    */
	    break;

  case 3:s.display();
	    break;
  case 4:exit(0);
 }
 cout<<"press any key to continue...."<<endl;
 getch();
 }
 while(choice!=4);
}