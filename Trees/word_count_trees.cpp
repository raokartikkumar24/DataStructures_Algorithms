r#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class tree 
{

public:

	tree(string _word) : left( NULL ), right ( NULL ), m_word(_word),middle( NULL ), count(1) {}
	
	tree* createTree(tree *newNode, string _word)
	{
		
		if( newNode == NULL )
		{
			newNode = new tree(_word);
		}
	
		else if( _word == newNode->m_word) {
			cout<<"middle"<<endl;
			newNode->count++;
			newNode->middle = createTree(newNode->middle,_word);
		}
		
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
			cout<<node->count<<" ";
			inorder(node->left);
			inorder(node->middle);
			inorder(node->right);

		}

	}

private:
string m_word;
int count;
tree *left;
tree *right;
tree *middle;

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

	return 0;
}
