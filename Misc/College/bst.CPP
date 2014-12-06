#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
class treenode
  {
	 int info;
	 treenode *left;
	 treenode *right;
	 public:
	 treenode *createtree(treenode *temp,int x)
	    {
		   if(temp==NULL)
			 {
				temp=new treenode;
				temp->info=x;
				temp->left=NULL;
				temp->right=NULL;
			 }
		   else if(x==temp->info)
			 {
				cout<<"!!!!Cannot enter the node !!!! "<<endl;
			 }
		   else if(x>temp->info)
			 {
			    temp->right=createtree(temp->right,x);
			 }
		   else
			 {
			    temp->left=createtree(temp->left,x);
			 }
		   return(temp);
	    }

    treenode *preorder(treenode *temp)
	   {
		  if(temp!=NULL)
		    {
			  cout<<temp->info<<endl;
			  preorder(temp->left);
			  preorder(temp->right);
		    }
			  return(temp);
	    }

	treenode *inorder(treenode *temp)
	   {
			if(temp!=NULL)
				{
					inorder(temp->left);
					cout<<temp->info<<endl;
					inorder(temp->right);
				}
					return(temp);
	    }


	 treenode *postorder(treenode *temp)
	   {
			  if(temp!=NULL)
				{
					postorder(temp->left);
					postorder(temp->right);
					cout<<temp->info<<endl;
				}
			 return(temp);
	    }
	   treenode *search(treenode *temp,int x)
		 {
				if(temp==NULL)
					{
						cout<<"Element not found"<<endl;
					}
				else if(temp->info==x)
					{
						cout<<"element "<<temp->info<<" found "<<endl;
					}
				else if(x>temp->info)
					{
						temp->right=search(temp->right,x);
					}
				else
					{
						temp->left=search(temp->left,x);
					}
				return(temp);
		 }
treenode *del(treenode *temp,int x)
  {
		  treenode *pt=temp;
		  treenode *prev,*s;

		  while(temp!=NULL && temp->info!=x)
			  {
				  if(x>temp->info)
				    {
					  pt=temp;
					  temp=temp->right;
				    }
				  else
				    {
					   if(x<temp->info)
						 {
						    pt=temp;
						    temp=temp->left;
						 }
				    }
			  }
			  if(temp==NULL)
				 {
				    cout<<"no elements"<<endl;
				    return(NULL);
				 }
			  else if(temp->info==x)
				 {
				    if(temp->left==NULL && temp->right==NULL)
					   {
						 if(pt==temp)
						 return(NULL);
						 if(x>pt->info)
						 pt->right=NULL;
						 else
						 pt->left=NULL;
						 return(this);
					   }
				    else if(temp->left!=NULL && temp->right==NULL && pt->right==temp)
					   {
						 pt->right=temp->left;
					   }
				    else if(temp->left!=NULL && temp->right==NULL && pt->left==temp)
					   {
						 pt->left=temp->left;
					   }
				    else if(temp->left==NULL && temp->right!=NULL && pt->right==temp)
					   {
						 pt->right=temp->right;
					   }
					else if(temp->left==NULL && temp->right!=NULL && pt->left==temp)
					   {
						pt->left=temp->right;
					   }
					 else if(temp->left!=NULL && temp->right!=NULL)
						{
						   prev=temp;
						   s=temp;
						   s=s->right;
						    while(s->left!=NULL)
							 {
							    prev=s;
							    s=s->left;
							 }
							temp->info=s->info;
							if(prev==temp)
							  {
								prev->right=NULL;
							  }
							 else  if(prev->right!=NULL)
								  {
								    temp->right=prev->right;
								    prev->left=NULL;
								  }

							else if(temp->left!=NULL && temp->right==NULL)
							    {
								  temp=temp->left;
								  return(temp);
							    }
							else if(temp->left==NULL && temp->right!=NULL)
							    {
								  temp=temp->right;
								  return(temp);
							    }
							    }
							    return(this);
							    }





}



  };

int main()
 {
   treenode *root=NULL;
   int c;
   clrscr();
   do
    {
	 cout<<"--------------"<<endl;
	 cout<<"    MENU     "<<endl;
	 cout<<"--------------"<<endl;
	 cout<<"1:INSERT"<<endl;
	 cout<<"2:PREORDER"<<endl;
	 cout<<"3:INORDER"<<endl;
	 cout<<"4:POSTORDER"<<endl;
	 cout<<"5:SEARCH"<<endl;
	 cout<<"6:DELETE"<<endl;
	 cout<<"7:EXIT"<<endl;
	 cout<<"Enter ur choice : ";
	 cin>>c;
	   switch(c)
		 {
		    case 1 : int a;
				   cout<<"Enter the element to be inserted : ";
				   cin>>a;
				   root=root->createtree(root,a);
				   break;
		    case 2 : root->preorder(root);
				   break;
		    case 3 : root->inorder(root);
				   break;
		    case 4 : root->postorder(root);
				   break;
		    case 5 : int ele;
				   cout<<"Enter the element to be searched : ";
				   cin>>ele;
				   root=root->search(root,ele);
				   break;
		    case 6 : int n;
				   cout<<"Enter the element to  be deleted : ";
				   cin>>n;
				   root=root->del(root,n);
				   break;

		    case 7 : exit(0);
		    default : cout<<"Invalid choice "<<endl;
		}
	}while(c!=7);
 getch();
 return(0);
}



