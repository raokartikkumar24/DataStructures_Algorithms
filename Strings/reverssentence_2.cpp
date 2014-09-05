#include<iostream>
using namespace std;

int main()
{

	char a[] = "my name is karthik kumar rao";
	int len = 0; int sp = 0;

	for(; a[len] != '\0'; len++) { if( a[len] == ' ') sp++ ;}

	sp+=1;

	char **ptr = NULL;

	ptr = new char*[sp];

	for(int i = 0 ; i < len ;i++)
		*ptr[i] = new char[len];


	int j = 0;
	for(int i = 0 ; i < len ; i++ )
	{
		
		while( a[j] != ' ')
		{
			*ptr[i] = a[j++];
		}

	}

return 0;
}
