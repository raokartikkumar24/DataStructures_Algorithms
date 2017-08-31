//For a given array of elements, return true if you find a pair that adds up to the sum
//[1,2,4,4] and sum =8 should return true
//one approach could be to sort the array and then have 2 pointers , one from beginning and one at the end,
// move the pointers based on the sum, if the resultant sum is less increment the low pointer
// if the resultant sum is more decrease the high pointer. 
// But this approach assumes that the array is sorted.


//Better approach is given below. Taken from google's videos
//Have a hash of array values complements, iterate the array, for every value check if complement is present
// return true if present else add that value to the set

#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>

using namespace std;

bool CheckIfContainsPairHavingSum(const vector<int>& data, int Sum)
{
	unordered_set<int> comp;

	for(int i =0 ; i < data.size(); i++)
	{
		if(comp.find(data[i]) != comp.end())
			return true;
		else
			comp.insert(Sum-data[i]);
	}

	return false;

}



int main()
{

	//case 1
	vector<int> data;
	data.push_back(1);
	data.push_back(2);
	data.push_back(4);
	data.push_back(9);


	int sum = 8;

	if(CheckIfContainsPairHavingSum(data,sum))
		cout << "YES \n";
	else
		cout << "NO\n";

		
	//case 2
	 vector<int> data2;
        data2.push_back(1);
        data2.push_back(2);
        data2.push_back(4);
        data2.push_back(4);



        if(CheckIfContainsPairHavingSum(data2,sum))
                cout << "YES \n";
        else
                cout << "NO\n";

	return 0;
}
