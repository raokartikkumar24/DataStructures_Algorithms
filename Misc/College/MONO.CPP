#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<stdio.h>
void main()
{
	char info[100],dec[100],en[100],info1[100];
	char alpha[]="abcdefghijklmnopqrstuvwxyz";
	char replace[]="qwertyuioplkjhgfdsazxcvbnm";
	int i,j=0,k=0,temp[100],s=0,store,t=0;
	clrscr();
	cout<<"Enter the information :";
	//cin>>info;
	gets(info);
	int len=strlen(info);
	cout<<len<<endl;
	cout<<"The Encrypted message is : ";
	for(i=0;i<len;i++)
		{
				  if(info[i]==32)
					{
						temp[k]=i-k;
						k++;
					}
			for(j=0;j<26;j++)
				{

					if(info[i]==alpha[j])
					{
						store=j;
						en[t]=replace[store];
						cout<<en[t];
						store++;
						t++;
					}
				   }
			}
			cout<<endl;
			int q=0,w=0;
			cout<<k<<endl;
			cout<<"The decrypted text is: ";
			for(i=0;i<len-k;i++)
				{
				if(i==temp[w])
					{
						//cout<<"In space";
						//cout<<i<<endl;
						dec[i]=' ';
						cout<<dec[i];
						w++;
					 }


					for(j=0;j<26;j++)
						{
							 if(en[i]==replace[j])
								{
									q=j;
									dec[s]=alpha[q++];
									cout<<dec[s];
									//++q;
									s++;

								 }
						  }



					  }
					getch();
   }









