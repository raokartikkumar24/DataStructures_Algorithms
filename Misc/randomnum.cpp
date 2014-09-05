#include<iostream>
#include<stdlib.h>
#include<iostream>
#include<fstream>

using namespace std;

ofstream log("inputnumbers.txt");

int main()
{

	int j = rand();
	for(int i = 0 ;i < (RAND_MAX % 1000) + 50000 ; i++ )
		{
			log<<i+(rand() % 100) + 1000 + j % 100<<"\n";
			log<<i*2+(rand() % 100) + 1000 + j % 100<<"\n";

		}

	log.close();
	return 0;
}
