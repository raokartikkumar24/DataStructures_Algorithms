#include<iostream>
using namespace std;
#define MAX 10

class edge {
public:
int v; //other endpoint of the edge
int weight; 
edge *next;

edge() : v(0),weight(0),next(NULL) { /*cout<<endl<<"calling the ctor of edge"<<endl;*/ }

};


class graph {

public:
edge *edges[MAX];

int m_nvertices;

int m_nedges;


	graph(int vert)
		{

			m_nedges = 0;
			m_nvertices = vert;
			//*edges = new edge[MAX];
			for(int i = 0 ; i< vert ; i++) 
				edges[i] = NULL;//new edge[vert];

		}

};

void createEdge(graph *g, int u, int v)
{

	//cout<<endl<<"Creating the edge : "<<u<<" and "<<v<<endl;	
	edge *e = new edge;
	e->weight = 0;
	e->v= v;
	e->next = g->edges[u];
	g->edges[u] = e;
	
	edge *e2 = new edge;
	e2->weight = 0;
	e2->v = u ;
	e2->next = g->edges[v];
	g->edges[v] = e2;


}

void print_edges(graph *g)
{
	edge *p;
	int i;
	for(i = 0 ; i < g->m_nvertices; i++)
	{
		cout<<"Vertex : "<<i<<" edges are : ";
		p = g->edges[i];

		while( p  )
		{
	
			cout<<p->v<<" ";
			p = p->next;

		}

		cout<<endl;
	}
	
}

int main()
{

	graph *ptr = new graph(5);
	int v,u;
	for( int i = 0 ; i < 5 ; i++) {
		cin>>v>>u;
		createEdge(ptr,v,u);
	}

	print_edges(ptr);
	
		
	

	
}
