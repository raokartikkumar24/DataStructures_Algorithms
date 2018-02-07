#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std::placeholders;
using namespace std;

std::condition_variable cv1, cv2,cv3;
std::mutex gMutex;
int gIndex = 1;

void printSequential1() {
    
    std::unique_lock<mutex> lock(gMutex);
    while(gIndex < 100) {
    printf("t1 %d \n",gIndex);
    gIndex++;
    cv2.notify_one();
    cv1.wait(lock);
    }
}


void printSequential2() {
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::unique_lock<mutex> lock(gMutex);
    while(gIndex < 100) {
    printf("t2 %d \n",gIndex);
    gIndex++;
    cv3.notify_one();
    cv2.wait(lock);
    }
}


void printSequential3() {
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::unique_lock<mutex> lock(gMutex);
    while(gIndex < 100) {
    printf("t3 %d \n",gIndex);
    gIndex++;
    cv1.notify_one();
    cv3.wait(lock);
    }
}


int main()
{
    std::thread thread_1(printSequential1);
    std::thread thread_2(printSequential2);
    std::thread thread_3(printSequential3);
    thread_1.join();
    thread_2.join();
    thread_3.join();
    return 0;
}

