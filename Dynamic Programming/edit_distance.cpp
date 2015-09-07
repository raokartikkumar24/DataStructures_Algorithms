#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

#define MATCH 0
#define INSERT 1
#define DELETE 2
#define MAXLEN 1024
using namespace std;
string text, pattern;


typedef struct{
public:
	int cost; // cost of an operation
	int parent; //from where did we arrive here
}data;

data cell[MAXLEN+1][MAXLEN+1];

//matching empty strings with i length of strings
void row_init(int i)
{
	cell[0][i].cost = i;
	if(i>0) cell[0][i].parent = INSERT;
	else cell[0][i].parent = -1;
}

//matching empty strings with i length of strings
void column_init(int i)
{
	cell[i][0].cost = i;
	if(i>0) cell[i][0].parent = DELETE;
	else cell[i][0].parent = -1;
}


int match(char c, char d)
{
	if(c == d ) return 0;
	return 1;
}

int indel(char c)
{
	return 1;
}

int EditDistance()
{
	int i,j,k;
	int opt[3];
	for( i = 0 ; i < MAXLEN; ++i) 
	{
		row_init(i);
		column_init(i);

	}

	for(i=1; i <= text.length(); ++i)
	{
		for(j = 1; j <= pattern.length(); ++j)
		{
			opt[MATCH] = cell[i-1][j-1].cost + match(text[i],pattern[j]);
			opt[INSERT] = cell[i][j-1].cost + indel(text[j]);
			opt[DELETE] = cell[i-1][j].cost + indel(pattern[i]);

			cell[i][j].cost = opt[MATCH];
			cell[i][j].parent = MATCH;
			for(k = INSERT; k <= DELETE ; ++k)
			{
				if( opt[k] < cell[i][j].cost )
				{
					cell[i][j].cost = opt[k];
					cell[i][j].parent = k;
				}
			}


		}
	}

//	cout << i << " " << j << endl;

	return (cell[i-1][j-1].cost);

}


void display()
{
	int i,j;
	ofstream output("C:\\temp\\matrix.txt");
	for(i = 0;  i <= text.length() + 10 ; i++) {
		for(j = 0 ; j <= pattern.length() + 10 ;++j) {
			output << cell[i][j].cost << "\t";
		}
		output << endl;
	}
}

void PrintSequence()
{
	//this will print the sequence of insertions/deletions/substitutions and match
	//TODO : Implement this next
}

int main()
{
	
	string t,p;



	getline(cin,t);
	getline(cin,p);

	//store dummy 0th character.
	text += '$'; //the calculation starts from 1 and not 0
	pattern += '$';//so we need to make sure we start from 1

	for(int i = 0 ; i < t.length(); ++i)
		text += t[i];

	for(int i = 0 ; i < p.length(); ++i)
		pattern += p[i];




	//cout << text.length() << "\t" << pattern.length() << endl;

	cout << "It will take " << EditDistance() << " insertion/deletion/substitution  to convert " << t << " into " << p << endl;

	display();
	//PrintSequence();
    return 0;
}