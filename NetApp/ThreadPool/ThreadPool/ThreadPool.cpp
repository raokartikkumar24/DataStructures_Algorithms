// ThreadPool.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<process.h>
#include<Windows.h>
#include<map>
#include<iostream>

using namespace std;

HANDLE m_event;

int i;

map<int,int> m_nThreads;
void ThreadFunction(void *key);

class CThreadPool
{

public:

	CThreadPool(int _N) : N(_N) 
	{
		m_pThreads = new HANDLE[N];
		for(i=0; i<N ;i++ )
		{
			m_pThreads[i] = (HANDLE)_beginthread(&ThreadFunction,0,&i);
		}

	}

	void AddThread()
	{
			i++;
			m_pThreads[N++] = (HANDLE)_beginthread(&ThreadFunction,0,&i);
	}

	void ListOfThreads()
	{

		map<int,int>::iterator mp = m_nThreads.begin();
		cout<<"Thread#"<<"\t"<<"ThreadID"<<endl;
		for(; mp != m_nThreads.end(); mp++) 
			cout<<mp->first<<"\t"<<mp->second<<endl;	

	}

	void WaitForThreads()
	{
		WaitForMultipleObjects(N,m_pThreads,TRUE,INFINITE);
	}

	int NumberOfThreads()
	{
			return N;
	}

private:
	HANDLE *m_pThreads;
	int threadCount;
	int N;

};

void ThreadFunction(void *key)
{
	int *id = (int*)key;
	m_nThreads.insert(pair<int,int>(*id,GetCurrentThreadId()));

	DWORD wait;
	wait = WaitForSingleObject(m_event,INFINITE);

	switch( wait )
	{
	case WAIT_OBJECT_0:
		cout<<"Hello!! I am thread : "<<GetCurrentThreadId()<<endl;
		_endthread();
		break;

	default:
		cout<<"Error while waiting for the event "<<endl;
		_endthread();

	}

}


int _tmain(int argc, _TCHAR* argv[])
{
	int __N;
	cout<<"Enter the number of threads :";
	cin>>__N;
	m_event  = CreateEvent(0,TRUE,FALSE,L"event1");
	CThreadPool *pool = new CThreadPool(__N);
	cout<<"The number of threads is "<<pool->NumberOfThreads()<<endl;
	pool->ListOfThreads();
	SetEvent(m_event);
	pool->WaitForThreads();




	return 0;
}

