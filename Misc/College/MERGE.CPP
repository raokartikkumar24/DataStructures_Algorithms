#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
class merge
  {
    int a[10],i,j,k;
    public:
    void getdata(int y)
	 {
	    cout<<"Enter the elements : ";
	    for(i=0;i<y;i++)
	    {cin>>a[i];}
	 }
	void display(int m)
	   {
		 for(i=0;i<m;i++)
		 cout<<a[i]<<endl;
	   }
    void mer(int lo, int mi,int hi)
	   {
		 int c[10];
		 i=lo;
		 j=mi+1;
		 k=lo;
		 while(i<=mi && j<=hi)
		    {
			  if(a[i]<a[j])
			    {
				  c[k]=a[i];
				  k++;i++;
			    }
			  else
			    {
				  c[k]=a[j];
				  k++;j++;
			    }
		   }
		  while(i<=mi)
			 {
			    c[k]=a[i];
			    k++;i++;
			 }
		  while(j<=hi)
			 {
			    c[k]=a[j];
			    k++;j++;
			 }
		   for(i=lo;i<=k-1;i++)
			 {
			   a[i]=c[i];
			 }
	    }
	    void sort(int l,int h)
		   {
			 int mid;
			 if(l<h)
			   {
				 mid=(l+h)/2;
				 sort(l,mid);
				 sort(mid+1,h);
				 mer(l,mid,h);
			   }
		    }
    };
    int main()
	 {
	    merge s;
	    int n;
	    clrscr();
	    cout<<"Enter the no of elements ";
	    cin>>n;
	    s.getdata(n);
	    s.sort(0,n-1);
	    cout<<"The sorted elements are : "<<endl;
	    s.display(n);
	    getch();
	    return(0);
	}






