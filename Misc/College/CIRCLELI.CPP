#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
class node
  {
   int info;
   node *next;
   public:
	node()
	  {
	    next=this;
	  }
	 void insertfront(int x)
	   {
		node *temp=new node;
		temp->info=x;
		if(this->next==this)
		  {
		    this->next=temp;
		    temp->next=this;
		  }
		else
		  {
		    temp->next=this->next;
		    this->next=temp;
		  }
	    }
	    void insertlast(int x)
		 {
		   node *temp=new node;
		   node *t=this;
		   temp->info=x;
		   temp->next=this;
		   if(t->next==this)
			{
			  t->next=temp;
			  return;
			}

		    while(t->next!=this)
			t=t->next;
			t->next=temp;
		 }
		int count()
		  {
		    node *t=this;
		    int c=0;
		    if(t->next==this)
			return 0;
		    while(t->next!=this)
			 {
			   t=t->next;
			   c++;
			 }
			 return c;
		    }
		   void insertatpos(int x,int pos)
			 {
			   int c=count();
			   if(pos>c+1)
				{
				  cout<<"INvalid"<<endl;
				  return;
				}
			    node *temp=new node;
			    node *t=this;
			    temp->info=x;
			    int i=0;
			    while(i!=pos-1)
				 {
				   t=t->next;i++;
				 }
				 temp->next=t->next;
				 t->next=temp;
			    }
			    void display()
				 {
				   node *t=this;
				   if(t->next==this)
				    cout<<"Empty list"<<endl;
				    else
					{
					  while(t->next!=this)
					    {
						 t=t->next;
						 cout<<t->info<<endl;
					    }
					 }
				  }
				  int deletelast()
				    {
					 node *n;
					 node *t=this;
					 if(t->next==this)
					   {
						return 0;
					  }
					  while(t->next->next!=this)
					  t=t->next;
					  n=t->next;
					  t->next=this;
					  return(n->info);
				    }

				int deletefront()
				 {
				  node *n;
				  node *t=this;
				  if(t->next==this)
				    {
					return 0;
				    }
				    n=t->next;
				    t->next=n->next;
				    return(n->info);
				  }
				  void delet(int num)
					{
					  node *t=this;
					  node *n;
					  if(t->next==this)
					   {
						cout<<"Empty list"<<endl;
						return ;
					  }
					  while(t->next!=this)
					    {
						if(t->next->info==num)
						 {
						  n=t->next;
						  t->next=n->next;
						  return ;
						  }
						  t=t->next;
						  }
						  cout<<"elenot found"<<endl;
					    }
					    };
				  int main()
				   {
				    node head;
				    int n,pos,d,choice;
				    char c;
				    clrscr();
				    do
					{
					 cout<<"MENU"<<endl;
					 cout<<"1:INSERTFRONT"<<endl;
					 cout<<"2:INSERTLAST"<<endl;
					 cout<<"3:INSERTATPOSITION"<<endl;
					 cout<<"4:DELETEFRONT"<<endl;
					 cout<<"5:DELTELASR"<<endl;
					 cout<<"6:DELTEan element"<<endl;
					 cout<<"7:display"<<endl;
					 cout<<"enter the choice:";
					 cin>>choice;
					 switch(choice)
					   {
						case 1 : cout<<"Enter ele : ";
							    cin>>n;
							    head.insertfront(n);
							    break;
						case 2 : cout<<"Enter ele : ";
							    cin>>n;
							    head.insertlast(n);
							    break;
						case 3 : cout<<"Enter ele : ";
							    cin>>n;
							    cout<<"enter the position : ";
							    cin>>pos;
							    head.insertatpos(n,pos);
							    break;
						 case 4 : d=head.deletefront();
								if(d==0)
								cout<<"underflow"<<endl;
								else
								cout<<"deleted ele is : "<<d<<endl;
								break;
						 case 5 : d=head.deletelast();
								if(d==0)
								cout<<"underflow"<<endl;
								else
								cout<<"THe deleted elemn : "<<d<<endl;
								break;
						 case 6 : cout<<"Enter the element to be deleted : ";
								cin>>n;
								head.delet(n);
								break;
						 case 7 : head.display();
								break;
						 default : cout<<"Invalais entry "<<endl;
								 break;
					   }
				   }while(choice!=8);
				   getch();
				   return(0);
		   }






