#include<iostream>
#include<vector>
#include<queue>

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

		//cout<<"Size : "<<m_vEdges.size()<<endl;
		for (int i = 0; i < m_nNodes; ++i)
			for (int j = 0; j < m_vEdges[i].size(); ++j)
				cout<<i<<"-"<<m_vEdges[i][j]<<endl;
			

	}

//TODO:Make this private and provide a public iterable function 
//To access the adjacency
		vector<vector<int>> m_vEdges;
		int m_nNodes;
		int m_nEdge;
		


};


class CBFSTraversal
{

public:
	CBFSTraversal(CGraph graphObject , int v) : m_gGraph(graphObject),vertex(v)
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

		/*for (int i = 0; i < m_gGraph.m_vEdges[vertex].size(); ++i)
		{
					bfs_q.push(m_gGraph.m_vEdges[vertex][i]);
					marked[m_gGraph.m_vEdges[vertex][i]] = false;
		}*/
		
		bfs_q.push(v);

		while(!bfs_q.empty())
		{
			cout<<"Inside queue"<<endl;
			int u = bfs_q.front();
			bfs_q.pop();
			cout<<"Next node to be processed "<<u<<endl;
			for (int i = 0; i < m_gGraph.m_vEdges[u].size(); ++i)
			{
				if(!marked[m_gGraph.m_vEdges[u][i]])
				{
					marked[m_gGraph.m_vEdges[u][i]] = true;
					bfs_q.push(m_gGraph.m_vEdges[u][i]);
				}
			}

		}





	}


private:
	int vertex;
	CGraph m_gGraph;
	vector<bool> marked;
	vector<int> edgeTo;

};



int main()
{

	int nods,eds;
	cout<<"Nodes :";
	cin>>nods;
	cout<<"Edges :";
	cin>>eds;

	CGraph graph(nods,eds);
	
	cout<<"Adjacency Edges"<<endl;
	for(int i = 0 ; i < eds ;i++)
	{
		int v,u;
		cin>>v>>u;
		graph.addEdges(v,u);
	}


	CBFSTraversal bfstraversal(graph,nods);

	bfstraversal.bfs(0);//BFS from the node 0. For simplicity



	return 0;

}
 