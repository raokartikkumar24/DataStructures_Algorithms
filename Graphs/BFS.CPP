#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#define MAX 30
int a[10][10];
class que
{
   int b[MAX],visited[MAX];
   int r,f;
   public:
	que()
	 {
	   r=-1;
	   f=-1;
	 }
	 void qinsert(int x)
		{
			  if(r==MAX-1)
			    {
				 cout<<"Q overflow";
				 }
				else if(r==-1 && f==-1)
				{
					f++;r++;
					b[r]=x;}
				else
					{
						r++;
						b[r]=x;}
		}
	int qdelete()
	 {
	  int temp;
	  if(r==-1 && f==-1)
	   {
	    cout<<"Q underflow";
	  }
	 else if(r==f)
	   {
	    temp=b[f];
	    f=r=-1;
	    cout<<"the deleted element is : "<<temp<<endl;
	   }
	   else
	    {
		 temp=b[f++];
		cout<<"The deleted element is :"<<temp<<endl;
	    }
	    }
    int bfs(int c,int n)
	 {
	   int j,t;
	   int d[30];
	   qinsert(c);
	   visited[c]=1;
	   int i=0;
	   while(i<n)
		{
		   t=qdelete();
		   j=0;
		   d[i++]=t;
		   while(j<n)
			{
			  if(a[t][j]!=0 && visited[j]!=1)
			    {
					qinsert(j);
					visited[j]=1;
			    }
			    j++;
			 }
		}
		cout<<"RESULT"<<endl;
		for(int p=0;p<i;i++)
		{cout<<d[p]<<endl;}
	  }
    };
    int main()
	{
	  que q;
	  int n,m,i,j;
	  clrscr();
	  cout<<"ENter the no of vertices : ";
	  cin>>n;
	  cout<<"Enter the elements "<<endl;
	  for(i=0;i<n;i++)
	    {
		 for(j=0;j<n;j++)
		  { cin>>a[i][j];}
	   }
	  q.bfs(0,n);
	  getch();
	  return(0);
    }
