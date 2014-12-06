#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
int main()
  {
	int a[10],i,n,j,temp;
	clrscr();
	cout<<"Enter the no of elements : "<<endl;
	cin>>n;
	cout<<"Enter the elements : "<<endl;
	for(i=0;i<n;i++)
	{cin>>a[i];}
	cout<<"The unsorted elements are: "<<endl;
	for(i=0;i<n;i++)
	{cout<<a[i]<<endl;}
	for(i=1;i<n;i++)
	  {
		for(j=0;j<n-i;j++)
		   {
			 if(a[j]>a[j+1])
			    {
				  temp=a[j];
				  a[j]=a[j+1];
				  a[j+1]=temp;
			    }
		    }
	   }
	   cout<<"The sorted elements are: "<<endl;
	   for(j=0;j<n;j++)
	   {cout<<a[j]<<endl;}
	   getch();
	   return(0);
	   }





