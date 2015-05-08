#include<iostream>
#include<vector>
#include"graph.h"
using namespace std;

	CGraph::CGraph(int n,int e) : m_nNodes(n),m_nEdge(e){

		cout<<"Creating graph object with "<<n<<" nodes"<<" and "<<e<<" m_vEdges"<<endl;
		for (int i = 0; i < m_nNodes; ++i) {
			std::vector<int> v;
			CGraph::m_vEdges.push_back(v);
			}

				

	}

	CGraph::~CGraph(){}


	void CGraph::addEdges(int v, int u)
	{
		m_vEdges[v].push_back(u);
		m_vEdges[u].push_back(v);
	}


	void CGraph::display()
	{

		for (int i = 0; i < m_nNodes; ++i)
			for (int j = 0; j < m_vEdges[i].size(); ++j)
				cout<<i<<"-"<<m_vEdges[i][j]<<endl;
			

	}

	//TODO : The return should be a Iterable list
	//Not sure what to use in C++
	vector<int> CGraph::adj(int v)
	{

		return m_vEdges[v];
	}

	//Returns the #of nodes connected to the vertes
	int CGraph::degree(int vertex)
	{
		return m_vEdges[vertex].size();
	}

		
		


