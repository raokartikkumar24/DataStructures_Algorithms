#include<iostream>
using namespace std;

int main()
{

	int ad[5][5];
	for(int i = 0 ; i < 5 ; i++)
		for(int j = 0 ; j <5 ; j++)
			ad[i][j] =0;
	int v,u;
	for(int i = 0 ; i< 5 ; i++ )
	 {

		cout<<"Enter the edge(u,v ) "<<endl;
		cin>>u>>v;
		ad[u][v] = 1;
		ad[v][u] = 1;

	 }

for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j <5 ; j++) {
			cout<<ad[i][j]<<" "; }
	cout<<endl;}

}
