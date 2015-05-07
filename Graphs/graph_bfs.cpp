#include <iostream>
#include <vector>
#include <queue>
//#include "graph.h"
#include "graph.cpp"
using namespace std;


class CBFSTraversal
{

public:
	CBFSTraversal(CGraph graphObject, int v) : m_gGraph(graphObject), vertex(v)
	{
		for (int i = 0; i < v; ++i)
		{
			marked.push_back(false);
			edgeTo.push_back(-1);
		}
	}



	void  bfs(int v)
	{
		queue<int> bfs_q;
		marked[v] = true;


		bfs_q.push(v);

		while (!bfs_q.empty())
		{
			//cout<<"Inside queue"<<endl;
			int u = bfs_q.front();
			bfs_q.pop();
			cout << "Next node to be processed " << u << endl;
			for (int i = 0; i < m_gGraph.m_vEdges[u].size(); ++i)
			{
				if (!marked[m_gGraph.m_vEdges[u][i]])
				{
					marked[m_gGraph.m_vEdges[u][i]] = true;
					bfs_q.push(m_gGraph.m_vEdges[u][i]);
					edgeTo[m_gGraph.m_vEdges[u][i]] = u;
				}
			}

		}

	}

	void displayEdgeTo()
	{
		for (int i = 0; i < vertex; ++i)
			cout << i << " " << edgeTo[i] << " ";
		cout << endl;
	}


private:
	int vertex; //Vertex to be processed
	CGraph m_gGraph; //The graph object
	vector<bool> marked; //Array to hold if the vertex was visited
	vector<int> edgeTo; // How we arrived at that edge

};



int main()
{

	int nods, eds;
	cout << "Nodes :";
	cin >> nods;
	cout << "Edges :";
	cin >> eds;

	CGraph graph(nods, eds);

	cout << "Adjacency Edges" << endl;
	for (int i = 0; i < eds; i++)
	{
		int v, u;
		cin >> v >> u;
		graph.addEdges(v, u);
	}


	CBFSTraversal bfstraversal(graph, nods);

	bfstraversal.bfs(0);//BFS from the node 0. For simplicity

	bfstraversal.displayEdgeTo();

	return 0;

}

