// Factorial.cpp : Defines the entry point for the console application.
//

// #include "stdafx.h"
#include<iostream>
#include<cstring>
using namespace std;
int maxim = 5000;

void display(int arr[]){
    int ctr = 0;
	long sum = 0;
    for (int i=0; i<maxim; i++){
    	if (!ctr && arr[i])	ctr = 1;
    	if(ctr) {
            
			sum+=arr[i];
			std::cout<<arr[i];
			}
    }
	
	cout<<endl<<sum<<endl;
}


void factorial(int arr[], int n){
    if (!n) return;
    int carry = 0;
    for (int i=maxim-1; i>=0; --i){
        arr[i] = (arr[i] * n) + carry;
        carry = arr[i]/10;
        arr[i] %= 10;
    }
    factorial(arr,n-1);
}

int main(){
    int *arr = new int[maxim];
    std::memset(arr,0,max*sizeof(int));
    arr[maxim-1] = 1;
    int num;
    std::cout<<"Enter the number: ";
    std::cin>>num;
    std::cout<<"factorial of "<<num<<"is :\n";
    factorial(arr,num);
    display(arr);
    delete[] arr;
		using namespace std;
	cout<<endl;
    return 0;
}


