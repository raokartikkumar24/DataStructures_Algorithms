#include<iostream>
#include<string>

using namespace std;
int min(int a, int b);

int main()
{
	int i = 0 , j = 0;
	string s1;//("maths");
	string s2;//("compute");
	cin>>s1>>s2;
	int l1 = s1.size();
	int l2 = s2.size();
	
	//int mat[l1+1][l2+1];
	
	int **mat;
	
	mat = new int*[l1+1];
	
	cout<<"created the array"<<endl;
	
	for(int p = 0; p <= l2; p++)
		*mat = new int[l2+1];
	
	cout<<"After initializing the array"<<endl;
	
	// for( i = 0 ; i <= l1 ;i++)
		// mat[0][i] = 0;
		
	// for( i = 0 ; i <= l2 ;i++)
		// mat[i][0] = 0;
		
	int m ;
	int res = 0;
	cout<<"Entering the main logic"<<endl;
	for( i = 1 ; i <= l1 ; i++)
	{
		for(j = 1 ; j <= l2 ;j++)
		{
			m = max(mat[i-1][j], mat[i][j-1]) + 1;
			mat[i][j] = max(m, mat[i-1][j-1] + ( s1[i-1] == s2[j-1] ? 0 : 1 ));
			res = max(res,mat[i][j]);
		}
	}
	
	cout<<res<<endl;
	
	for(i = 0 ; i <= l1; i++)
	{
		for(j = 0 ; j <= l2 ; j++)
		{
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;

}

