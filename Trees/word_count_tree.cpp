#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

map<int,string> wordcount;
map<string,int> wordcount2;
string getword(int rank)
{
	return wordcount[rank];
}

string getword2(int rank)
{
	map<string,int>::iterator it = wordcount2.begin();
	for(;it != wordcount2.end(); it++ )
	{
		if( (*it).second == rank ) return (*it).first;
	}
}
class tree 
{

public:

	tree(string _word) : left( NULL ), right ( NULL ), m_word(_word), count(1) {}
	
	tree* createTree(tree *newNode, string _word)
	{
		
		if( newNode == NULL )
			newNode = new tree(_word);
	
		else if( _word == newNode->m_word) 
			newNode->count++;
				
		else if( _word < newNode->m_word)
			newNode->left  = createTree(newNode->left,_word);

		else 
			newNode->right = createTree(newNode->right,_word);

		return newNode;
	}

	void inorder(tree *node)
	{

		if( node != NULL )
		{
			cout<<node->m_word<<" : "<<node->count<<endl;
			wordcount[node->count] = node->m_word;
			wordcount2[node->m_word] = node->count;
			inorder(node->left);
			//inorder(node->middle);
			inorder(node->right);

		}

	}

private:
string m_word;
int count;
tree *left;
tree *right;
};

int main()
{
	string csword;
	tree *node = NULL;
	ifstream str("word.txt");
	while( !str.eof())
	{
		str>>csword;
		node = node->createTree(node,csword);
		
	}

	node->inorder(node);
	int k;
	cout<<"enter the rank of the word : ";
	cin>>k;
	string theword = getword(k);
	cout<<endl;
	if( theword.empty()) cout<<"No word exists"<<endl;
	else cout<<k<<" ranked word is "<<theword<<endl;

	cout<<getword2(k)<<endl;
	return 0;
}