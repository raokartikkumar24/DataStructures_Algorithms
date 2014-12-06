#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
class node
 {
  int info;
  node *next;
  node *prev;
  public:
    node *insertfront(int x)
	 {
	   node *temp=new node;
	   temp->info=x;
	    if(this==NULL)
		{
		  temp->prev=NULL;
		  temp->next=NULL;
		  return(temp);
		}
	   else
		{
		  temp->prev=NULL;
		  temp->next=this;
		  this->prev=temp;
		  return(temp);
		}
	 }
	 node *insertatpos(int pos,int item)
		{
			int i=1;
			node *nnode=new node;
			node *temp=this;
			 if(pos==1)
			   {
				 insertfront(item);
			   }
			 else if(this==NULL)
			   {
				 cout<<"Invlid position"<<endl;
				 insertlast(item);
			   }
			 else
			   {
				 nnode->info=item;
				 while(i!=pos-1)
				    {
					  temp=temp->next;
					  i++;
				    }
				  nnode->prev=temp;
				  nnode->next=temp->next;
				  temp->next=nnode;
				  temp->next->prev=nnode;
				  return(this);
		}     }
	    node *insertlast(int y)
		{
		 node *temp=new node;
		 node *p=this;
		 temp->info=y;
		 if(this==NULL)
		   {
			 temp->next=NULL;
			 temp->prev=NULL;
			 return(temp);
		   }
		   else
			{
			  while(p->next!=NULL)
			   {
				p=p->next;
			   }
			  p->next=temp;
			  temp->prev=p;
			  temp->next=NULL;
			  return(this);
			}
		  }
		  node *deletef()
		    {
			 if(this==NULL)
			  {
			    cout<<"no element to delete"<<endl;
			  }
			  else
			   {
				int x;
				node *temp=this;
				x=temp->info;
				temp=temp->next;
				cout<<"the deleted ele is : "<<x<<endl;
				return(temp);
			   }
		    }
		  node *deletelast()
		    {

			 node *temp=this;
			 node *t;
			 if(this==NULL)
			   {
				cout<<"NO ele to delete"<<endl;
			   }
			   else
			    {
				  while(temp->next!=NULL)
				   {
					t=temp;
					temp=temp->next;
				   }
				   t->next=NULL;
				   return(this);
			    }
			}
			node *deletepos(int posit)
			  {
			    node *temp=this;
				int i=1;
				if(temp==NULL)
				 {
				   cout<<"No list/item to delete"<<endl;
				 }
			    else if(posit==1)
				 {
				   deletef();
				 }
				 else
				  {
				   while(i!=posit-1)
				    {
					 temp=temp->next;
					 i++;
				    }
				    temp->next->prev=temp;
				    temp->next=temp->next->next;
				    return(this);
					}
				  }
	  void rev()
	    {
		  node *temp=this;
		   if(temp==NULL)
			 {
			   cout<<"empty list"<<endl;
			 }
		   else
			{
			  while(temp->next!=NULL)
			   {temp=temp->next;}
			   while(temp->prev!=NULL)
				 {
				   cout<<temp->info<<endl;
				   temp=temp->prev;
				 }
				 cout<<temp->info<<endl;
		   }

	    }

    void display()
	{
	 node *temp=this;
	  if(this==NULL)
	    {
		 cout<<"Empty list"<<endl;
	    }
	    else
		 {
		  while(temp->next!=NULL)
		   {
			cout<<temp->info<<endl;
			temp=temp->next;
		   }
	   cout<<temp->info<<endl;
	   }
	}
  };
  int main()
   {
    node *first=NULL;
    int c;
    clrscr();
    do
	{
	  cout<<"MENU"<<endl;
	  cout<<"1.INSERTFRONT"<<endl;
	  cout<<"2.INSERTLAST"<<endl;
	  cout<<"3.INSERT AT POSITION"<<endl;
	  cout<<"4.DELETEFRONT"<<endl;
	  cout<<"5.DELETELAST"<<endl;
	  cout<<"6.DELETE AT POSITION"<<endl;
	  cout<<"7.DISPLAY"<<endl;
	  cout<<"8.REVERSE"<<endl;
	  cout<<"9.EXIT"<<endl;
	  cout<<"Enter choice : ";
	  cin>>c;
	switch(c)
	  {
	    case 1 : int y;
			   cout<<"enter ele to be inserted : ";
			   cin>>y;
			   first=first->insertfront(y);
			   cout<<"The elements are"<<endl;
			   first->display();
			   break;
	    case 2 : int z;
			   cout<<"Enter ele to be inserted : ";
			   cin>>z;
			   first=first->insertlast(z);
			   cout<<"The elements are"<<endl;
			   first->display();
			   break;
	    case 3 : int posi,a;
			   cout<<"enter the position : ";
			   cin>>posi;
			   cout<<"enter the ele to be inserted : ";
			   cin>>a;
			   first=first->insertatpos(posi,a);
			   cout<<"The elements are"<<endl;
			   first->display();
			   break;
	    case 4 : first=first->deletef();
				cout<<"The elements are"<<endl;
			   first->display();
			   break;
	    case 5 : first=first->deletelast();
				cout<<"The elements are"<<endl;
			   first->display();
			   break;
	    case 6 : int b;
			   cout<<"Insert the positon to be deleted : ";
			   cin>>b;
			   first=first->deletepos(b);
			   cout<<"The elements are"<<endl;
			   first->display();
			   break;
	    case 7 : first->display();
			   break;
	    case 8 : first->rev();
			   break;
	    case 9 : exit(0);
	}
  }while(c!=9);
   getch();
    return(0);
  }







