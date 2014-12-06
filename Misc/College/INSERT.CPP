#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
int main()
{
   int a[10],i,j,n,temp;
   clrscr();
   cout<<"Enter the no of elements : ";
   cin>>n;
   cout<<"Enter the elements : ";
   for(i=0;i<n;i++)
	{
	   cin>>a[i];
	}
    for(i=1;i<n;i++)
	  {
		j=i;
		while(j>=1)
		  {
		    if(a[j]<a[j-1])
			 {
			   temp=a[j];
			   a[j]=a[j-1];
			   a[j-1]=temp;
			 }
			 j=j-1;
		   }
	  }
	  cout<<"The sorted elements are : "<<endl;
	  for(i=0;i<n;i++)
	  cout<<a[i]<<endl;
	  getch();
	  return(0);
    }


