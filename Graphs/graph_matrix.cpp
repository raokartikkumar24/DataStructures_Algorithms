#include<iostream>
#include<vector>

using namespace std;

class CGraph
{
	
public:
	CGraph(int n,int e) : m_nNodes(n),m_nEdge(e){

		cout<<"Creating graph object with "<<n<<" nodes"<<" and "<<e<<" m_vEdges"<<endl;
		
		m_pEdges = new int*[n];
		for (int i = 0; i < n; ++i)
			m_pEdges[i] = new int[n];

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				m_pEdges[i][j] = 0;
		
		

	}

	~CGraph(){

		cout<<"Freeing the space"<<endl;
		delete m_pEdges;
	}


	void addEdges(int v, int u)
	{
		m_pEdges[v][u] = 1;
		m_pEdges[u][v] = 1;
	}


	void display()
	{

		
		for (int i = 0; i < m_nNodes; ++i) {
			for (int j = 0; j < m_nNodes; ++j)
				{
					if( m_pEdges[i][j] != 0)
					{
						cout<<i<<" - "<<j<<endl;
					}
				}
			}
			

	}

private:
		
		int m_nNodes;
		int m_nEdge;
		int **m_pEdges;


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
 