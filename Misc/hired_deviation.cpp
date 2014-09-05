#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getdeviation(int a[], int dd)
{
	return (*max_element(a,a+dd) - *min_element(a,a+dd) );
}

void find_deviation( vector<int> v, int d) {
    int count = 0;
    int deviation = 0;
    int length = (int)v.size();
	for(int i = 0 ; i < length-d+1 ; i++)
    {
        int j = i;
		int *myptr = new int[d];
		while( count < 3 )
		{
			myptr[count] = v[j];
			j++;
			count++;
		}
       
		count = 0;
        int dump = getdeviation(myptr,d);
            if( dump > deviation)
            {   
                    deviation = dump;
            }
        }
    
	cout<<deviation<<endl;
}

int main()
{
	vector<int> vs;
	vs.push_back(6);
	vs.push_back(9);
	vs.push_back(4);
	vs.push_back(7);
	vs.push_back(4);
	vs.push_back(1);
	find_deviation(vs,3);
		return 0;
}

