#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

int occur(string source, string pattern, int index)
{
	const char *so = source.c_str();
	const char *pat = pattern.c_str();
	int soLength = 0, patLength = 0;
	for(;so[soLength] != '\0' ;soLength++);
	for(;pat[patLength] != '\0' ;patLength++);
	int backupsolength = soLength;
	int backuppatlength = patLength;
	int *position = new int[soLength];
	int c=0;
	
	//vector<int> pos;
	map<int,int> posMap;
	for(int i = 0 ; i < backupsolength ;i++)
		{
			if( soLength <=0 ) break;			
			patLength = backuppatlength;
			int y = 0;
			int z = patLength;
			int times = 0;

			while( y != patLength )
			{
				
				if( soLength-z < 0) break;
				if(source.at(soLength-z) == pattern.at(y))
				{
					int x = soLength-z;
					times++;
					y++;z--;
						if( times == backuppatlength )
							{	
								posMap[c++] = soLength-times;
								//pos.push_back(soLength-times);
								soLength = soLength-patLength;
								
							}
					
				}
				else
					{
						//slide the window by 1.
						soLength = soLength-1;
					}
				
			}
		}	
		
		/*cout<<"vector"<<endl;
		for(int i = 0 ; i < pos.size() ; i++)
			cout<<pos[i]<<endl;

		cout<<"Map"<<endl;
		for(int i = 0 ; i < posMap.size() ; i++)
			cout<<posMap[i]<<endl;*/
			if( posMap.size() == 0 ) return -1;
			
			return posMap[posMap.size()-index];
}

int main()
{
	string s,p;
	cout<<"Enter the source string"<<endl;
	getline(cin,s);
	cout<<"Enter the pattern"<<endl;
	getline(cin,p);
	cout<<"Enter the index"<<endl;
	int i;
	cin>>i;
	int poss = occur(s,p,i);
	if( poss == -1 )
		cout<<"Pattern not found"<<endl;
	else
		cout<<i<<"th occurenace of"<<" "<<p<<" is present at"<<" "<<poss<<" position in the string"<<endl;
	return 0;
}
