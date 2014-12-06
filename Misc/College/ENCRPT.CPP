#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
void main()
{
	char info[100],in[100],temp[100];
	int t[100],i,j=0,key,len,k;
	clrscr();
	cout<<"Enter the information :";
	gets(info);
	len=strlen(info);
	cout<<"Enter the key  :";
	cin>>key;
	cout<<"The encrypted data is : ";
	for(i=0;i<len;i++)
		{
				if(info[i]=='x' || info[i]=='y' || info[i]=='z')
					{
						in[i]=info[i]-23;
						cout<<in[i];

					}

				else if(info[i]==' ')
					{
						t[j++]=i;
						//continue;
					}

				else
				 {
					in[i]=info[i]+(key%26);
					cout<<in[i];
				 }
					 }
				 int te=strlen(info)-j;
				 cout<<te<<endl;
				 /*for(i=0;i<j;i++)
				 {cout<<t[i];}*/
				 cout<<"Decrpypted msg is :";
				 for(i=0,k=0;i<len;i++)
					{
						if(i==t[k])
						 {
						    temp[i]=' ';
						    cout<<temp[i];
						    k++;
						 }
						else if(in[i]=='a' || in[i]=='b' || in[i]=='c')
							{
								temp[i]=in[i]+23;
								cout<<temp[i];
							}
						else
						{
							temp[i]=in[i]-(key%26);
							cout<<temp[i];
						}

				    }

		    getch();
		  }





