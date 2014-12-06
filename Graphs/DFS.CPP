#include<iostream.h>
#include<iomanip.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 50
int m[20],mat[20][20];
class stack
{
 int a[MAX],visit[MAX];
 int top;
 public:
  stack()
   {
	top=-1;
   }
   int push(int n)
	{
	  if(top==MAX-1)
	    {
		   cout<<"overflow"<<endl;
		  }
		 else
		  {
		    a[++top]=n;
		  }
	 }
	 int pop()
	  {
		  if(top==-1)
		   {
		    return -1;
		   }
		  else
		   {
			a[top--];
		   }

	 }
	 int dfs(int n)
	   {
		int j;
		for(int k=0;k<n;k++)
		{visit[k]=0;}
		int i;
		push(0);
		visit[0]=1;
		i=pop();
		x:
		cout<<" "<<m[i]<<" ";
		for(j=n-1;j>0;j++)
		{
		  if(mat[i][j]==1 && visit[j]==0)
			{
			  push(j);
			  visit[j]=1;
			}
		}
		i=pop();
		if(i!=-1)
		goto x;

	   }

};
int main()
  {
    stack s;
    int vert;
	clrscr();
    cout<<"enter the no of vertices : ";
    cin>>vert;
    cout<<"Enter the values in order "<<endl;
    for(int i=0;i<vert;i++)
    cin>>m[i];
    cout<<"Enter the elements "<<endl;
    for(i=0;i<vert;i++)
	 {
	   for(int j=0;j<vert;j++)
		{
		   cin>>mat[i][j];
		}
	 }
	 cout<<"DFS"<<endl;
	s.dfs(vert);
    getch();
    return(0);
 }


