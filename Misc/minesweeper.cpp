#include<iostream>
using namespace std;
int main()
{
	//TODO : Try to read from the file instead of user input
	int m,n;
	cout<<"Enter rows and cols : ";
	cin>>m>>n;
	char input[m][n];
	cout<<"Enter the input : "<<endl;
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < n ; j++ ) {
			cin>>input[i][j]; } }
	//May be we can deal with a single array. We can save space and time
	//TODO : Try to remove the second array
	int in[m+2][n+2]; //kinda sentinal so that we save boundry checking
	for(int i = 0 ; i < m+2 ; i++) {
		for(int j = 0 ; j < n+2 ; j++ ) {
			in[i][j] = 0;}}
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < n ; j++ )   {
			if( input[i][j] == '*' ) in[i+1][j+1] = 1;
			else	in[i+1][j+1] = 0;
		}
    }
	/*for(int i = 0 ; i < m+2; i++) {
		for(int j = 0 ; j < n+2 ; j++ ) {
			cout<<in[i][j]<<" "; } cout<<endl;}*/
	for(int i = 1 ; i < m+1; i++) {
		for(int j = 1 ; j < n+1 ; j++ ) {
			if( input[i-1][j-1] == '*') cout<<"*"<<" ";
			else cout<<in[i][j]+in[i][j-1]+in[i][j+1]+in[i-1][j]+in[i-1][j-1]+in[i-1][j+1]+in[i+1][j]+in[i+1][j+1]+in[i+1][j-1]<<" ";
		}
		cout<<endl;
		}
			return 0;
}

