
#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <chrono>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <sstream>
#include <fstream>


std::ofstream jsonFile("output.json", std::ios::app);


std::mutex  datasend;
int processCounter;

std::queue<int> processCreation;
std::queue<int> processRunning;

std::mutex processCreateMutex;
std::mutex processRunningMutex;

std::mutex mainMutex;

std::map<std::string, std::queue<int> > mainQueue;

void ProcessCreateThread()
{
	std::cout << "Started the process create thread \n";
	while (1) {

		std::this_thread::sleep_for(std::chrono::seconds(5));
		processCreateMutex.lock();
		int item = (rand() * rand()) % 971;
		std::cout << "Pushed " << item << " to the queue\n";
		processCreation.push(item);
		processCreateMutex.unlock();

		if (processCreation.size() >= 5) {
			std::queue<int> tempQ;
			while (!processCreation.empty() && tempQ.size() != 5) {
				int x = processCreation.front();
				processCreation.pop();
				tempQ.push(x);
			}
			mainMutex.lock();
			mainQueue.insert({ "pcreate", tempQ });
			mainMutex.unlock();
		}
	}
}


void ProcessRunningThread()
{
	std::cout << "Started the process create thread \n";
	while (1) {

		std::this_thread::sleep_for(std::chrono::seconds(5));
		processRunningMutex.lock();
		int item = (rand() * rand()) % 871;
		std::cout << "Pushed " << item << " to the queue\n";
		processRunning.push(item);
		processRunningMutex.unlock();

		if (processRunning.size() >= 5) {
			
			std::queue<int> tempQ;
			while (!processRunning.empty() && tempQ.size() != 5) {
				int x = processRunning.front();
				processRunning.pop();
				tempQ.push(x);
			}
			mainMutex.lock();
			mainQueue.insert({ "prunning", tempQ });
			mainMutex.unlock();
		}

	
	}
}

void printJson(std::string key) {

	std::stringstream jsonStream;
	std::queue<int> processQueue = mainQueue[key];
	if (!processQueue.empty()) {
		int maxE = processQueue.front();
		int minE = processQueue.front();
		int sum = 0;
		int total = processQueue.size();
		while (!processQueue.empty()) {

			sum += processQueue.front();
			maxE = std::max(maxE, processQueue.front());
			minE = std::min(minE, processQueue.front());
			processQueue.pop();
		}

		jsonStream << key << " :{ \n"
			<< "min :" << minE << "\n"
			<< "max :" << maxE << "\n"
			<< "total :" << total << "\n"
			<< "count :" << sum << "\n"
			<< "}\n";

		if (jsonFile.is_open() == false)
			jsonFile.open("output.json", std::ios::app);
		jsonFile << jsonStream.str() << "\n";
		jsonFile.close();
	}
}

void runevery60seconds()
{
	std::cout << "Started the 60 seconds thread\n";
	while (1) {

		std::this_thread::sleep_for(std::chrono::seconds(60));
		mainMutex.lock();
		printJson("pcreate");
		printJson("prunning");
		mainQueue.clear();
		std::cout << "Cleared the main Q size : " << mainQueue.size() << "\n";
		mainMutex.unlock();
	}

}

void runforever()
{
	while (1)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

int main()
{
    
	std::thread one(ProcessCreateThread);
	one.detach();

	std::thread two(ProcessRunningThread);
	two.detach();

	std::thread mainThread(runevery60seconds);
	mainThread.detach();

	std::thread bgthread(runforever);
	bgthread.join();

	return 0;
}

