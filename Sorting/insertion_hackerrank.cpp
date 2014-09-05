#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <iostream>
using namespace std;
/* Head ends here */

void print(int *a,int size)
{
    for(int i = 0 ; i < size ;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}

void swap(int *a,int i,int j)
{
    int temp = a[i];
    a[i]= a[j];
    a[j]= temp;
}

void insertionSort(int ar_size, int *  ar)
{

    for(int i = 0 ; i < ar_size; i++)
    {
        for(int j = i+1 ; j >= 0 ;j--)
        {
            if( ar[j-1] > ar[j])
            {
                swap(ar,j,j-1);
                
            }
        }
        if( i < ar_size-1)
            print(ar,ar_size);
    }

}
/* Tail starts here */
int main(void) 
{
   
    int _ar_size;
    cin >> _ar_size;
    //scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        cin >> _ar[_ar_i];
        //scanf("%d", &_ar[_ar_i]); 
    }

   insertionSort(_ar_size, _ar);
   
   return 0;
}