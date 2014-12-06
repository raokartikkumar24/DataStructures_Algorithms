#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
int count=0;
class node
 {
  int info;
  node *next;
   public:
	node *insertfront(int x)
	 {

	   node *temp=new node;
	   temp->info=x;

	    if(this==NULL)
		{
		  count++;
		  temp->next=NULL;
		  return(temp);
		}
	   else
		{
		  count++;
		  temp->next=this;
		  return(temp);
		}
	 }
	 node *insertatpos(int pos,int item)
		{
		  int i=1;
		  node *nnode=new node;
		  node *temp=this;
		  node *t;
		  count++;
		   if(pos==1)
		    {
			 insertfront(item);
		    }
		    else
			{
			  nnode->info=item;

			  while(i!=pos-1)
			    {
				 temp=temp->next;
				 i++;
			    }
			    t=temp->next;
			    temp->next=nnode;
			    nnode->next=t;
			    return(this);
		}     }
	    node *insertlast(int y)
		{
		 node *temp=new node;
		 node *p=this;
		 temp->info=y;
		 count++;
		 while(p->next!=NULL)
		  {
		    p=p->next;
		  }
		   if(p->next==NULL)
			{
			  p->next=temp;
			  temp->next=NULL;
			  return(this);
			}
		  }
		  node *deletef()
		    {
			count--;
			 return(this->next);
		    }
		  node *deletelast()
		    {
			 node *temp=this;
			 node *t;
			 count--;
			  while(temp->next!=NULL)
			   {
				t=temp;
				temp=temp->next;
			   }
			   t->next=NULL;
			   return(this);
			}
			node *deletepos(int posit)
			  {
			    node *temp=this;
			    node *t;
				int i=1;
			    count--;
				if(posit==1)
				 {
				   deletef();
				 }
				 else
				  {
				   while(i!=posit)
				    {
					 t=temp;
					 temp=temp->next;
					 i++;
				    }
				   t->next=t->next->next;
				   return(this);

				  }
				  }
				  node *countn()
				   {
					int tempo;
					tempo=count;
					cout<<"The no of nodes are : "<<tempo<<endl;

				   }
				   node *search(int q)
					{
					node *temp=this;
					int i=0;

					while(temp->info!=q)
					  {
					    i++;
					    temp=temp->next;
					  }
					  if(temp->info==q)
					  {
					    cout<<" element "<<temp->info<<" found at "<<i+1<<endl;
					  }
					  else
					   {
						cout<<"Ele not found"<<endl;}
				    }
    void display()
	{
	 node *temp=this;
	 while(temp->next!=NULL)
	  {
	   cout<<temp->info<<endl;
	   temp=temp->next;
	  }
	  cout<<temp->info<<endl;
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
	  cout<<"8.EXIT"<<endl;
	  cout<<"9.COUNT"<<endl;
	  cout<<"10.SEARCH"<<endl;
	  cout<<"Enter choice : ";
	  cin>>c;
	switch(c)
	  {
	    case 1 : int y;
			   cout<<"enter ele to be inserted : ";
			   cin>>y;
			   first=first->insertfront(y);
			   break;
	    case 2 : int z;
			   cout<<"Enter ele to be inserted : ";
			   cin>>z;
			   first=first->insertlast(z);
			   break;
	    case 3 : int posi,a;
			   cout<<"enter the position : ";
			   cin>>posi;
			   cout<<"enter the ele to be inserted : ";
			   cin>>a;
			   first=first->insertatpos(posi,a);
			   break;
	    case 4 : first=first->deletef();
			   break;
	    case 5 : first=first->deletelast();
			   break;
	    case 6 : int b;
			   cout<<"Insert the positon to be deleted : ";
			   cin>>b;
			   first=first->deletepos(b);
			   break;
	    case 7 : first->display();
			   break;
	    case 8 : exit(0);
	    case 9 : first=first->countn();
			   break;
	    case 10 : int rr;
			    cout<<"Enter element to be searched : ";
			    cin>>rr;
			    first->search(rr);
			    break;

	}
  }while(c!=11);
   getch();
    return(0);
  }



