#include <iostream>

using namespace std;

int numberOfSteps( int n) {

	int f[n+1];
	f[0] = 0;
	f[1] = 1;
	f[2] = 3;
	
	for(int i = 3; i <=n ; i++)
		f[i] = f[i-1] + f[i-2] + f[i-3];

	return f[n];

}

int main()
{
	int N;
	cin >> N;

	printf("%d\n",numberOfSteps(N));
	
	return 0;

}
