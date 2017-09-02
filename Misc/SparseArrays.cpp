#include <iostream>
#include <map>
#include <string>

using namespace std;


int main()
{

	int N;
	cin >> N;
	map<string, int> words;

	for(int i = 0 ; i < N; i++)
	{
		string str;
		cin >> str;

		if(words.count(str) == 0 )
		{
			pair<string,int> p;
			p.first = str;
			p.second = 1;
			words.insert(p);
			//words.insert(make_pair<string,int>(str,1));
		}
		else
		{
			int cou = words.at(str);
			cou++;
			words[str] = cou;
			
		}

	}


	int Q;
	cin >> Q;

	for(int i = 0 ; i < Q; i++)
	{
		string query;
		cin >> query;

		if(words.count(query) == 0 ) cout << 0 << "\n";
		else
		 cout << words[query] << "\n";
		
	}

	return 0;
}

