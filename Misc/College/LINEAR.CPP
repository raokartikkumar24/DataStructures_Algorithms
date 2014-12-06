#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
void main()
{
 float a[10][11],x[10];
 float t,q,s;
 int n,big,m,j,k1,b,j1,ne,kp1,k,jj,ip1,i,n1;
 clrscr();
 cout<<"enter the order of matrix";
 cin>>n;
 m=n+1;
 ne=n-1;
 cout<<"enter the system of linear equation";
 for(i=0;i<n;i++)
 for(j=0;j<m;j++)
 cin>>a[i][j];
 cin.precision(5);
 cout<<"the original matrix";
 for(i=0;i<n;i++)
 for(j=0;j<m;j++)
 cout<<a[i][j];
 for(k=0;k<ne;k++)
 jj=k;
 big=fabs(a[k][k]);
 kp1=k+1;
 for(i=kp1;i<n;i++)
 if(b<fabs(a[i][k]))
 {
  big=fabs(a[i][k]);
  jj=1;
 }
 if(jj!=k)
 for(j=k;j<m;j++)
 {
  t=a[j][j];
  a[jj][j]=a[k][j];
  a[k][j]=t;
 }
 for(i=kp1;i<n;i++)
 a[i][k]=0;
 cout<<"matrix after"<<k+1<<"elimination";
 for(i=0;i<n;i++)
 {
 for(j=0;j<m;j++)
 cout<<a[i][j];
 cout<<endl;
}
x[n-1]=a[n-1][m-1]/a[n-1][n-1];
for(n1=1;n1<ne;n1++)
{
 s=0;
 i=n-n-1;
 ip1=i+1;
 for(j=i+1;j<n;j++)
 s=s+a[i][j]*x[jj];
 x[i]=((a[i][m-1]-s)/a[i][j]);
}
cout<<"solution is";
for(i=0;i<n;i++)
cout<<x[i];
getch();
}
