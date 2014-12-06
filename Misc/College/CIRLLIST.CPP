#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<stdlib.h>
class node
 {
    int info;
    node *next,*head;
	public:
	  node()
	   {
		 head=this;
	   }
	 node *insertfront(int x)
	   {
		 node *temp=new node;
		 temp->info=x;
		 temp->next=head;
		 head->next=temp;
		 return(temp);
	   }
	 node *insertatpos(int pos,int item)
		{
		   int i=1;
		   node *nnode=new node;
		   node *temp=head;
		   node *t;
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
				   return(temp);
			 }

		}
		 node *insertlast(int y)
		   {
			 node *temp=new node;
			 node *p=head;
			 temp->info=y;
			 while(p->next!=head)
			    {
				  p=p->next;
			    }
			 if(p->next==head)
			    {
				  p->next=temp;
				  temp->next=head->next->next;
				  return(temp);
			    }

		  }
		  node *deletef()
		    {
			 return(head->next);
		    }
		  node *deletelast()
		    {
			 node *temp=head;
			 node *t;
			  while(temp->next!=head)
			   {
				t=temp;
				temp=temp->next;
			   }
			   t->next=head->next;
			   return(head);
			}
			node *deletepos(int posit)
			  {
			    node *temp=head;
			    node *t;
				int i=1;
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
				   return(head);
								  }
				  }

    void display()
	{
	 node *temp=head;
	 while(temp->next!=head)
	    {
		  //temp=temp->next;
		  cout<<temp->info<<endl;
		  temp=temp->next;
	    }
	    cout<<temp->info<<endl;
	  }


  };
  int main()
   {
    node first;
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
	  cout<<"Enter choice : ";
	  cin>>c;
	switch(c)
	  {
	    case 1 : int y;
			   cout<<"enter ele to be inserted : ";
			   cin>>y;
			   first.insertfront(y);
			   break;
	    case 2 : int z;
			   cout<<"Enter ele to be inserted : ";
			   cin>>z;
			   first.insertlast(z);
			   break;
	    case 3 : int posi,a;
			   cout<<"enter the position : ";
			   cin>>posi;
			   cout<<"enter the ele to be inserted : ";
			   cin>>a;
			   first.insertatpos(posi,a);
			   break;
	    case 4 : first.deletef();
			   break;
	    case 5 : first.deletelast();
			   break;
	    case 6 : int b;
			   cout<<"Insert the positon to be deleted : ";
			   cin>>b;
			   first.deletepos(b);
			   break;
	    case 7 : first.display();
			   break;
	    case 8 : exit(0);
	    default : cout<<"invalid choice"<<endl;
	}
  }while(c!=9);
   getch();
    return(0);
  }



