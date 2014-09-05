#include<iostream>
#include<string>
#include<vector>
using namespace std;

int occur(string source, string pattern, int index)
{
	const char *so = source.c_str();
	const char *pat = pattern.c_str();
	int soLength = 0, patLength = 0;
	for(;so[soLength] != '\0' ;soLength++);
	for(;pat[patLength] != '\0' ;patLength++);
	//cout<<"source length : "<<soLength<<" Pattern Length : "<<patLength<<endl;
	int backupsolength = soLength;
	int backuppatlength = patLength;
	int *position = new int[soLength];
	int c=0;
	
	vector<int> pos;
	for(int i = 0 ; i < backupsolength ;i++)
		{
			patLength = backuppatlength;
			int y = 0;
			int z = patLength;
			int times = 0;
			while( y != patLength )
			{
				
				
				if(source.at(soLength-z) == pattern.at(y))
				{
					cout<<"Source Length : "<<soLength<<endl;
					cout<<"source.at(soLength-patLength) "<<source.at(soLength-z)<<" "<<"pattern.at(patLength -1) "<<pattern.at(y)<<endl;
					int x = soLength-z;
					cout<<"Position is : "<<x<<endl;
					times++;
					cout<<"Times is : "<<times<<endl;
					y++;z--;
						if( times == backuppatlength )
							{	
								cout<<"soLength-times"<<" "<<soLength-times<<endl;
								pos.push_back(soLength-times);
								soLength = soLength-patLength;
								//position[c] = soLength-times;
								//cout<<"***"<<position[c]<<"***"<<endl;
								//c++;
								
							}
					
				}
				else
					{
						//slide the window by 1.
						soLength = soLength-1;
					}
				
			}
		}	
		
		for(int i = 0 ; i < pos.size() ; i++)
			cout<<pos[i]<<endl;
			
			return 1;
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
	cout<<occur(s,p,i)<<endl;
}