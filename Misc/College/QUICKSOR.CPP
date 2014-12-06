#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
void swap(int &a,int &b)
{
   int temp;
   temp=a;
   a=b;
   b=temp;
}
void qsort(int *a,int first,int last)
 {
	int lower=first+1;
	int upper=last;
	swap(a[first],a[(first+last)/2]);
	int bound=a[first];
	while(lower<=upper)
	 {
	    while(a[lower]<bound)
	    lower++;
	    while(bound<a[upper])
	    upper--;
	    if(lower<upper)
		{
		  swap(a[lower++],a[upper--]);
		}
	    else
		 {
		   lower++;
		 }
	  }
	  swap(a[upper],a[first]);
	  if(first<upper-1)
	  qsort(a,upper+1,last);
	  if(upper+1<last)
	  qsort(a,upper+1,last);
}
int main()
{
  int arr[10];
  int i,n;
  clrscr();
  cout<<"Enter the no elements : ";
  cin>>n;
  cout<<"Enter elements ";
  for(i=0;i<n;i++)
  cin>>arr[i];
  qsort(arr,0,n-1);
  cout<<"The sorted elements are : "<<endl;
  for(i=0;i<n;i++)
  cout<<arr[i]<<endl;
  getch();
  return(0);
}
