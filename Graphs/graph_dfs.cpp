#include<iostream>
#include<vector>

using namespace std;

class CGraph
{
	
public:
	CGraph(int n,int e) : m_nNodes(n),m_nEdge(e){

		cout<<"Creating graph object with "<<n<<" nodes"<<" and "<<e<<" m_vEdges"<<endl;
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

		cout<<"Size : "<<m_vEdges.size()<<endl;
		for (int i = 0; i < m_nNodes; ++i)
			for (int j = 0; j < m_vEdges[i].size(); ++j)
				cout<<i<<"-"<<m_vEdges[i][j]<<endl;
			

	}


		vector<vector<int>> m_vEdges;
		int m_nNodes;
		int m_nEdge;


};



class CDepthFirstSearchPaths {


public:
	CDepthFirstSearchPaths(CGraph graphObject, int vertex):m_OGraph(graphObject)
	{
		for (int i = 0; i < vertex; ++i)
		{
			marked.push_back(false); //initially everything is unvisited
			edgeTo.push_back(-1); // init to soemthing 
		}
	}


	void dfs(int  vertex)
	{

		marked[vertex] = true;
		cout<<"DFS :: "<<vertex<<endl;

		for (int i = 0; i < m_OGraph.m_vEdges[vertex].size(); ++i)
		{
			if(!marked[m_OGraph.m_vEdges[vertex][i]])
			{
				dfs(m_OGraph.m_vEdges[vertex][i]);
				edgeTo[i] = vertex;
			}
		}
	}

	void printTo()
	{

		for (int i = 0; i < edgeTo.size(); ++i)
		{
			cout<<edgeTo[i]<<" ";
		}
		cout<<endl;
	}

private:
	vector<bool> marked;
	vector<int> edgeTo;
	CGraph m_OGraph;


};




int main()
{

	int nods,eds;
	cout<<"Nodes :";
	cin>>nods;
	cout<<"Edges :";
	cin>>eds;

	CGraph graph(nods,eds);
	//graph.display();
	cout<<"Adjacency Edges"<<endl;
	for(int i = 0 ; i < eds ;i++)
	{
		int v,u;
		cin>>v>>u;
		graph.addEdges(v,u);
	}


	//graph.display();

	CDepthFirstSearchPaths dfs_paths(graph,nods);
	dfs_paths.dfs(0); // start with 0th node for sinmplicity.

	dfs_paths.printTo();

	return 0;

}
