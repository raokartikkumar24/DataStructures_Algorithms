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

private:
		vector<vector<int>> m_vEdges;
		int m_nNodes;
		int m_nEdge;
		


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


	graph.display();



	return 0;

}
 