#include <iostream>
#include<math.h>
using namespace std;

// int getIntegerComplement(int n) {

    // int num = n;
    // int bin[17];
	
	// for(int k = 0 ; k < 17; k++)
		// bin[k] = -1;
		
    // int c = 16;
    // int count = 0;
    // while( num > 0 )
    // {
           // bin[c--] = !(num%2);
           // num/=2;
            // count++;
    // }

	// for(int k = 0 ; k < 17; k++)
		// cout<<bin[k]<<" ";
		
		// cout<<endl<<count<<endl;
    // int *invert = new int[count];
    // int i = 0,j =0;
	// for( ; i < 17; i++)
	// {
		// if( bin[i] != -1 )
			// invert[j++] = bin[i];
	// }
    
    // for(int k = 0 ; k < count; k++)
		// cout<<invert[k]<<" ";
	// cout<<endl;
    // i = 0 ;
    
    // int sum = 0;
    // j = count-1;
    // for(; i < count ; i++)
        // sum+=(int)((pow(2,j--))*invert[i]);
        
     // return sum;
// }



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //long number = 15;
   // cin>>number;
    //long  i =1;
    
    // for( ; i <=number ; i++ )
    // {
         // if( i % 3 == 0 )
         // {
              // if( i % 5 == 0 )
                 // cout<<"FizzBuzz"<<endl;
              // else
                  // cout<<"Fizz"<<endl;
         // }
          
        // else if( i % 5 == 0 )
               // cout<<"Buzz"<<endl;
        // else
            // cout<<i<<endl;
    // }
	
	// int k = 0;
	// int comp = !k;
	
	// cout<<comp;
	
	//cout<<getIntegerComplement(100);
	
	

    int num = 100;
    int arr[10] = {0};
    int i =1;
	int powersof10[] = { 1, 10, 100, 1000 };
    for(; i <=num ; i++ )
    {
     
            if( i < 10 )
                arr[i]++;
            else
            {
					int rem = (num/ powersof10[i] ) %10;
					arr[rem]++;
                 // int rem = 0;
				 // int num2 = i;
                 // while( num2 > 0 )
                 // {
                       // rem = num2 % 10;
					   // if( rem < 10 ) arr[rem]++;
                       // num2 /= 10;
                 // }
				 //arr[rem]++;
				 //arr[num2]++;
            }
    }

	
	for(int j = 0 ; j < 10; j++)
		cout<<arr[j]<<endl;




	
    
    return 0;
}