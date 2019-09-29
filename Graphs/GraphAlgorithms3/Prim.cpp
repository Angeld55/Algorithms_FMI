#include <iostream>
using namespace std;

#include <list> 
#include <limits.h> 
#include <vector>
#include <stack>
#include <queue>

struct edge
{
    int start;
	int dest;
	int weight;
	edge(int s, int d, int w)
	{
	    start = s;
		dest = d;
		weight = w;
	}
	bool operator<(const edge&other)const
	{
			return (this->weight > other.weight);
	}
	
};
class Graph
{
	int V;
	vector<vector<edge>> adj;

public:
    Graph(int V);
    void addEdge(int v, int w, int weight);
    int getVerticesCount();

    void Print();

    Graph Prim();



};

Graph::Graph(int V)
{
	this->V = V;
	for (int i = 0; i < V; i++)
	{
		vector<edge> v;
		adj.push_back(v);
	}
}

void Graph::addEdge(int v, int w, int weight)
{
	edge t(v,w, weight);
	adj[v].push_back(t);
	
	edge t2(w,v,weight);
	adj[w].push_back(t2);
}

int Graph::getVerticesCount()
{
	return V;
}

void Graph::Print()
{
    for (int i = 0; i < adj.size(); i++) 
    {
            std::cout<<i<<" -> ";
            for (int j = 0; j < adj[i].size(); j++) 
            {
               cout <<"<"<<adj[i][j].dest<<"(weight: "<<adj[i][j].weight<<")>";
               if(j!=adj[i].size()-1)
                cout<<',';
            }
            std::cout<<std::endl;
    }
}

Graph Graph::Prim()
{
    Graph result(V);
    
    bool* visited = new bool[V];
    for(int i =0;i<V-1;i++)
        visited[i]=false;
    
    visited[0]=true;
    
    priority_queue<edge> q;
    for (int i = 0; i < adj[0].size(); i++) 
        q.push(adj[0][i]);
        
    int includedEdges = 0;
    int spanningTreeWeight = 0;
    while(includedEdges<V-1)
    {
        edge currentEdge = q.top();
        q.pop();
        if(!visited[currentEdge.dest])
        {
            result.addEdge(currentEdge.start,currentEdge.dest,currentEdge.weight);
            spanningTreeWeight+=currentEdge.weight;
            includedEdges++;
            visited[currentEdge.dest]=true;
            for(int i = 0; i< adj[currentEdge.dest].size();i++)
                q.push(adj[currentEdge.dest][i]);
            
        }
    }
    delete[] visited;
    cout<<"Spanning tree weight: "<<spanningTreeWeight<<endl;
    return result;
}
int main()
{
    Graph g(6);
    g.addEdge(0,1,2);
    g.addEdge(0,3,1);
    g.addEdge(0,4,4);
    g.addEdge(1,3,3);
    g.addEdge(1,2,3);
    g.addEdge(1,5,7);
    g.addEdge(2,3,5);
    g.addEdge(2,5,8);
    g.addEdge(3,4,9);
    
    
    g.Print();
    
    
    Graph MST = g.Prim();
    MST.Print();
    
    return 0;
}
