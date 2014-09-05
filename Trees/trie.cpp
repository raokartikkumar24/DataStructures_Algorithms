#include<iostream>
#include<string>
using namespace std;


class dictionary
{

public:
// dictionary(char ch, int __val) {
// value = __val;
// c = ch;
// for(int i = 0 ; i < 26; i++)
	// alpha[i] = NULL;

// }

dictionary() {
for(int i = 0 ; i < 26; i++)
	alpha[i] = NULL;
}

dictionary* put(dictionary *node,string str, int i)
{

 if( i == str.length() ) node->end = true; 
  else
	node->alpha[str[i]-'a'] = put(node.alpha[str[i]-'a'],str,i+1);
	
	return node;
  
  
	
}

private:

bool end;
char c;
dictionary *alpha[26];
};

int main()
{
	dictionary *obj = new dictionary();
	obj = obj->put(obj,"shell",0);
	
	return 0;
	
}