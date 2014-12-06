#include<iostream.h>
#include<conio.h>
#include<string.h>
main()
{
 char a[20],b[10];
 int i,j,m,n;
 clrscr();
 cout<<"Enter string : ";
 cin>>a;
 cout<<endl;
 cout<<"Enter the substring : ";
 cin>>b;
 cout<<endl;
 m=strlen(a);
 n=strlen(b);
  j=0;
  for(i=0;i<m && j<n;)
   {
	if(a[i]==b[j])
	 {
	  i++;
	  j++;
	 }
	  else if(a[i]!=b[j])
	   {
	    i++;
	    j=0;
	   }
	   else
	    {
		 j++;
	    }
   }
   if(j==n)
   {
    cout<<"Substring found"<<endl<<"position "<<i-j+1<<endl;
   }
   else
   {
    cout<<"substring not found"<<endl;
   }getch();
   return 0;
    }


