#include <iostream>
#include <string>
using namespace std;


class Trie
{

public:

Trie() {
for(int i = 0 ; i < 26; i++)
	alpha[i] = NULL;
end = false;
}

/* TODO : need to work on this recursive
Trie* put(Trie *node,string str, int i)
{
	
	if(node->alpha[str[i]-'a'] == NULL){
		node->alpha[str[i]-'a'] = new Trie;
		node->c = str[i];
		cout << "Adding " << str[i] << endl;
	}
 	if(i == str.length()){
 		node->end = true; 
 		return node;
 	} 
  	else {
		node->alpha[str[i]-'a'] = put(node->alpha[str[i]-'a'],str,i+1);
     }
	
	return node;
  
}
*/

Trie* insert(Trie *root, string str){
	Trie *nextNode = root;
	for(int i =0; i < str.length(); i++){
		if(nextNode->alpha[str[i] -'a'] == NULL) {
			nextNode->alpha[str[i] -'a'] = new Trie;
		}

		nextNode = nextNode->alpha[str[i] -'a'];

	}

	nextNode->end = true;
	return root;
}

/* Wrong code . TODO : need to check what is wrong with this
bool query(Trie* node, string str)
{
	bool found = false;
	if(node != NULL){
		Trie *nextNode = node->alpha[str[0]-'a'];
		cout << nextNode->c << endl;
		for(int i = 0; i < str.length(); i++){
			if(nextNode != NULL) {
			nextNode = nextNode->alpha[str[i]-'a'];
			if(nextNode){
				found = true;
				cout << nextNode->c <<  " ";
			}
		}
		}
	}

	return found;

} */


bool search(Trie *root, string str){
	Trie *nextNode = root;
	for(int i =0; i < str.length(); i++){
		if(nextNode->alpha[str[i] -'a'] == NULL) {
			return false;
		}
		nextNode = nextNode->alpha[str[i] -'a'];
	}

	return (nextNode != NULL && nextNode->end );
}

private:

bool end;
char c;
Trie *alpha[26];
};

int main()
{
	Trie *obj = new Trie();
	
	obj = obj->insert(obj,"hello");
	obj = obj->insert(obj,"world");
	obj = obj->insert(obj,"linkin");
	obj = obj->insert(obj,"park");

	cout << obj->search(obj,"park") << endl;
	cout << obj->search(obj,"qwertt") << endl;

	
	return 0;
	
}

