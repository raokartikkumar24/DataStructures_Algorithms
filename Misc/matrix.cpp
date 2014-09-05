#include<iostream>
using namespace std;

int main()
{
	int mat[4][4];
	bool found = false;
	for(int i = 0 ; i < 4 ; i++ )
		for(int j = 0 ; j < 4 ; j++ )
			mat[i][j] = i+j+1;
			
	
	mat[1][2] = 0;
	
	for(int i = 0 ; i < 4 ; i++ )
	{
		for(int j = 0 ; j < 4 ; j++ )
		{
			cout<<mat[i][j]<"\t";

		}
		cout<<endl;
	}	
	cout<<endl<<"================================"<<endl;
	for(int i = 0 ; i < 4 ;)
	{
		for(int j = 0 ; j < 4 ;)
		{
			if( mat[i][j] == 0 )
				{
						found = true;
						//TODO : adhere  to good coding stds here
						mat[i][0] = mat[i][1] = mat[i][2] = mat[i][3] = 0;
						mat[0][j] = mat[1][j] = mat[2][j] = mat[3][j] = 0;
						break;
						
				}
			found = false;	
			j++;
		}
		if( found ) break;
		i++;
	}
			
	for(int i = 0 ; i < 4 ; i++ )
	{
		for(int j = 0 ; j < 4 ; j++ )
		{
			cout<<mat[i][j]<"\t";

		}
		cout<<endl;
	}	

	return 0;
}	

