/*
 *
 Print the first non repeating character in the given string
Assumes the input is in small caps. 
 * 
*/
#include <iostream>
#include <string>
#include  <algorithm>
#include  <vector>

using  namespace std;

int main()
{
    string input;
    cin >> input ;
    
    pair<int,int> count_index[26] ;
    
    for(int i = 0 ;  i < 26; ++i)
    {
        count_index[i].first = 0;
        count_index[i].second = -1;
    }
    int length = input.length();
  
    for(int i = 0;  i < length; ++i)
    {
      
        count_index[input[i]-'a'].first++;
        count_index[input[i]-'a'].second = i;
    }
        
  
    int j = 0;
    for(int i = 0 ; i < 26 ; ++i)
    {
        if( count_index[i].first == 1 ) {
            cout << input[count_index[i].second];
            break;
        }
    }
    
    return 0;

}