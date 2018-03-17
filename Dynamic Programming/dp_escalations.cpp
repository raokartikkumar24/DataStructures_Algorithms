#include<iostream>
using namespace std;

int getMinimumMonths(int k, int months[])
{
	int *min = new int[k+1];
	for(int idx = 0 ; idx <= k ; idx++)
		min[idx] = 9999 ;
		
	// int min[n] = { -1 };	
	min[0] = 0;
	int i = 1;
	int v =0;
	for(; i <= k ; i++)
	 {
		for(v=0; v < 12 ; v++)
		{
			if( ( months[v] <= i ) && ( (min[i - months[v]] + 1) < min[i] ))
			{
				min[i] = min[i-months[v]] + 1;
			}
		}
	 }
    
    if(min[k] == 9999) return -1;
    return min[k];
	
}

int main()
{
    int k;
    cin >> k;
    int months[12] = {0};
    for(int i = 0 ; i < 12; i++) {
        cin >> months[i];
    }

    cout << getMinimumMonths(k,months) << endl;
	return 0;
}
