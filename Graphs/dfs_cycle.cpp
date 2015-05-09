// graph_debug.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>

using namespace std;

class CGraph
{

public:
	CGraph(int n, int e) : m_nNodes(n), m_nEdge(e){

		cout << "Creating graph object with " << n << " nodes" << " and " << e << " m_vEdges" << endl;
		for (int i = 0; i < m_nNodes; ++i) {
			std::vector<int> v;
			m_vEdges.push_back(v);
		}
	}

	~CGraph(){}


	void addEdges(int v, int u)
	{
		m_vEdges[v].push_back(u);
		m_vEdges[u].push_back(v);
	}


	void display()
	{

		cout << "Size : " << m_vEdges.size() << endl;
		for (int i = 0; i < m_nNodes; ++i)
		for (int j = 0; j < m_vEdges[i].size(); ++j)
			cout << i << "-" << m_vEdges[i][j] << endl;


	}


	vector<vector<int> > m_vEdges;
	int m_nNodes;
	int m_nEdge;


};



class CDepthFirstSearchPaths {


public:
	CDepthFirstSearchPaths(CGraph graphObject, int vertex) :m_OGraph(graphObject), hasCycle(false)
	{
		for (int i = 0; i < vertex; ++i)
		{
			marked.push_back(false); //initially everything is unvisited
			edgeTo.push_back(-1); // init to soemthing 
			marked2.push_back(false);
		}
	}


	void dfs(int  vertex)
	{

		marked[vertex] = true;
		cout << "Processing... " << vertex << endl;

		for (int i = 0; i < m_OGraph.m_vEdges[vertex].size(); ++i)
		{
			if (!marked[m_OGraph.m_vEdges[vertex][i]])
			{
				dfs(m_OGraph.m_vEdges[vertex][i]);
				edgeTo[m_OGraph.m_vEdges[vertex][i]] = vertex;
			}
		}
	}

	void printTo()
	{

		for (int i = 0; i < edgeTo.size(); ++i)
			cout << i << "\t" << edgeTo[i] << "\n";
		cout << endl;
	}

	/*bool isCycle()
	{
		bool iscycle = false;
		//mark all false 
		for (int i = 0; i < m_OGraph.m_nNodes; ++i)
			marked.push_back(false);
		
		for (int i = 0; i < m_OGraph.m_nNodes; i++)
		{
			if (marked[i] == true)
			{
				for (int j = 0; j < m_OGraph.m_vEdges[i].size(); j++)
				{
					if (!marked[m_OGraph.m_vEdges[i][j]])
						iscycle = false;
					else
						iscycle = true;
				}
			}
			else
				iscycle = false;
		}

		return iscycle;
	}*/

	void findCycle(CGraph g, int v, int w)
	{
		marked2[v] = true;

		for (int i = 0; i < g.m_vEdges[v].size(); i++)
		{
			if (!marked2[i])
			{
				marked2[i] = true;
				findCycle(g, i, v);
			}
			else if (v != w)
			{
				hasCycle = true;
				return;
			}
			else
				hasCycle = false;
		}
	}

	inline bool HasCycle() { return hasCycle; }

private:
	vector<bool> marked;
	vector<int> edgeTo;
	CGraph m_OGraph;
	vector<bool> marked2;
	bool hasCycle;


};




int main()
{

	int nods, eds;
	cout << "Nodes :";
	cin >> nods;
	cout << "Edges :";
	cin >> eds;

	CGraph graph(nods, eds);
	//graph.display();
	cout << "Adjacency Edges" << endl;
	for (int i = 0; i < eds; i++)
	{
		int v, u;
		cin >> v >> u;
		graph.addEdges(v, u);
	}


	//graph.display();

	CDepthFirstSearchPaths dfs_paths(graph, nods);
	dfs_paths.dfs(0); // start with 0th node for sinmplicity.

	//dfs_paths.printTo();

	//finding cycle from origin...
	dfs_paths.findCycle(graph, 0, 0);
	
	if (dfs_paths.HasCycle())
		cout << "The graph has cycles!! \n";
	else
		cout << "There are no cycles !! \n";


	return 0;

}
