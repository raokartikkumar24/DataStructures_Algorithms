#include<iostream>

using namespace std;




int main()
{
	int alpha[60] = {0};
	
	for(int i = 0 ; i < 60 ;i++)
		cout<<alpha[i]<<" ";
		
	cout<<endl;
	
	char a[] ="aBBcADassdfaaaaAAAAp";
	
	for(int i = 0 ; i < 20 ;i++)
		alpha[a[i] - 'A' ]++;
		
		for(int i = 0 ; i < 60 ;i++)
		if( alpha['A' + i ] == 1 ) cout<< (char)('A' + i)<<endl;
		//cout<<alpha[i]<<" ";
		
		return 0;
	

}
