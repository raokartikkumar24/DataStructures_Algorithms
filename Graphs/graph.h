
#include<vector>
class CGraph {
	
public:

	CGraph(int n,int e);
	~CGraph();
	void addEdges(int v, int u);
	void display();
	int degree(int vertex);
	std::vector<int> adj(int v);

	std::vector<std::vector<int> > m_vEdges;
	int m_nNodes;
	int m_nEdge;




};