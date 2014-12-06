#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
int main()
  {
    int a[10],i,j,n,small,pos;
    clrscr();
    cout<<"Enter the no of elements : "<<endl;
    cin>>n;
    cout<<"Enter the elements : "<<endl;
    for(i=0;i<n;i++)
    {cin>>a[i];}
    cout<<"the unsorted ele are : "<<endl;
    for(i=0;i<n;i++)
    {cout<<a[i]<<endl;}
    for(i=0;i<n;i++)
	 {
	   small=a[i];
	   pos=i;
	   for(j=i;j<n;j++)
		{
		  if(a[j]<small)
		    {
			 small=a[j];
			 pos=j;

		    }
		   a[pos]=a[i];
		   a[i]=small;
		}
	   }
		cout<<"the sorted ele are : "<<endl;
		for(i=0;i<n;i++)
		{cout<<a[i]<<endl;}
		getch();
		return(0);
	  }

