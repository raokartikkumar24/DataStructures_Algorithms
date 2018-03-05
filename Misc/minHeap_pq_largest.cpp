#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

void printMaxElements(priority_queue<int, vector<int>, greater<int> > printer) {
     cout << "Max 5 elements so far are \n";
    while(!printer.empty()){
        cout << printer.top() << " ";
        printer.pop();
    }
	cout << "\n";
}


int main()
{
    
    int count = 0;
    priority_queue<int, vector<int>, greater<int> > minQ;
    
    while(count != 5) {
        count++;
        int ele;
        cin >> ele;
        minQ.push(ele);
    }
    
   
    printMaxElements(minQ);
    cout << "enter more elements, for stopping enter -1 \n";
     int e;
    do {
        cin >> e;
        if(minQ.top() < e) {
            minQ.pop();
            minQ.push(e);
        }
         printMaxElements(minQ);
    } while(e != -1);
    
    return 0;
}


