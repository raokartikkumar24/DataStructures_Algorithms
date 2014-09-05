
#include<iostream>
#include<string>

using namespace std;

void longestSubstring(string source)
{
	int maxlength = 0;
	int i = 0, j = 0;
	int alpha[26];
	for(int k = 0 ; k < 26 ;k++)
		alpha[k] = -1;
		
	
	
	int end;
	int start;
	for(j=i; i < source.length(); )
	{
			if( alpha[source[i] - 'a' ] != -1  || i == source.length()-1)
			{
				
				int l = i ;
				if( l > maxlength )
				{
					maxlength = l;
					start = j;
					end = i-1;

					int temp = i;
					i = alpha[source[i]-'a'] + 1;
					j = i;
					alpha[source[temp]-'a']  = -1;
				}

				else i++;
				
				
				
			}
			else
			{
				
				alpha[source[i]-'a'] = i;
				i++;
				
			}
		
	}	

cout<<"The longest unique substring with length "<<maxlength<<" is : "<<endl;
for(int p = start ; p <= end ; p++)
 cout<<source[p];
 
cout<<endl;

// return maxlength;
}

int main()
{
	string mysource("sdfjlsdfjfdjsjldsj");
	longestSubstring(mysource);
	
	return 0;
}