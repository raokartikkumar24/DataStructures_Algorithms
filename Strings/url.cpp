#include<iostream>
#include<string>
#include<vector>

// http://www.google.com/this%20and%20thatnow%20/fresh%20page.com

using namespace std;

void parseURL(string csURL)
{
	vector<string> mURLS;
	int index =0;
	for(int i = 0 ; i < csURL.size(); i++)
	{
		string cstemp;
		index = i;
		while(csURL[i] != '%')
		{
			cstemp+=csURL[i];
			i++;
		}
		mURLS.push_back(cstemp);
		i += 2;
		
		
	}
	
}

int main()
{
	string url = "http://www.google.com/this%20and%20thatnow%20/fresh%20page.com";
	parseURL(url);
	return 0;
}