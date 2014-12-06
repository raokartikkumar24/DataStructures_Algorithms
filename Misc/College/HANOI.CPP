#include<iostream.h>
#include<iomanip.h>
#include<conio.h>
#include<math.h>
hanoi(int n,char sr,char inter,char dest)
{
  if(n!=0)
   {
	hanoi(n-1,sr,dest,inter);
	cout<<"Move disk "<<n<<"from "<<sr<<" to "<<dest<<endl;
	hanoi(n-1,inter,sr,dest);
   }


void main()
 {
  int x;
  clrscr();
  cout<<"Enter the value of x ";
  cin>>x;
  hanoi(x,'A','B','C');
  cout<<"the no moves are : "<<pow(2,x)-1;
  getch();
}




