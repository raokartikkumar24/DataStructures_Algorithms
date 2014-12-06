#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
class binsort
  {
	int a[10],i,j;
	public:
	void getdata(int y)
	   {
		 cout<<"Enter the elements : ";
	 for(i=0;i<y;i++)
		 cin>>a[i];
	   }
	 void display(int m)
	    {
		 for(i=0;i<m;i++)
		 cout<<a[i]<<endl;
	    }
	    void sort(int m)
		  {
			int temp;
			for(i=0;i<m;i++)
			  {
			    for(j=0;j<m-i-1;j++)
				 {
				   if(a[j]>a[j+1])
					{
					  temp=a[j];
					  a[j]=a[j+1];
					  a[j+1]=temp;
					}
				 }
			   }
			}
	 void search(int ele,int c,int d)
	    {
		  int mid=0;
		  int lo,hi;
		  lo=c;
		  hi=d;
		  mid=(lo+hi)/2;
		  if(a[mid]==ele)
		    {
			 cout<<"Element "<<ele<<" found at "<<mid+1<<endl;
		    }
		  else if(ele<a[mid])
			{
			    search(ele,lo,mid);
			}
		  else if(ele>a[mid])
			{
			   search(ele,mid+1,hi);
			}
		  else
			 {
			   cout<<"Element not found "<<endl;
			 }
		 }

};
int main()
  {
    binsort s;
    int n,x;
    clrscr();
    cout<<"Enter the no. of elements : ";
    cin>>n;
    s.getdata(n);
    cout<<"the elements are"<<endl;
    s.display(n);
    cout<<"the sorted elements are "<<endl;
    s.sort(n);
    s.display(n);
    cout<<"enter the element to be searched ";
    cin>>x;
    s.search(x,0,n-1);
    getch();
    return(0);
  }


