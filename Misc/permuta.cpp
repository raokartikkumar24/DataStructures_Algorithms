#include<string>
#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{

	ofstream per("per.txt");
   std::string s="karthik";
   do
   {

      per<<s<<std::endl;

   }while(std::next_permutation(s.begin(),s.end()));
}
