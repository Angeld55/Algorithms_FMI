#include <iostream>
using namespace std;
#include <queue>
#include <stack>

//The non-recursive implementation is similar to breadth-first search but differs from it in two ways:

//1.it uses a stack instead of a queue, and
//2.it delays checking whether a vertex has been discovered until the vertex is popped from the stack rather than making this check before adding the vertex.



class Graph
{
	int V;
	vector<vector<int>> adj;
        void DFSrec(int start,bool* visited);
public:
	Graph(int V);
	void addEdge(int v, int w);
	
	void BFS();
        void DFS();
        void DFSrecursive();
};

Graph::Graph(int V)
{
	this->V = V;
	for (int i = 0; i < V; i++)
	{
		vector<int> v;
		adj.push_back(v);
	}
}

void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w);
}
void Graph::BFS()
{
    bool* visited = new bool[V];
    for(int i = 0;i<V;i++)
        visited[i]=false;
    
    queue<int> q;
    q.push(0);
    visited[0]=true;
    
    while(!q.empty())
    {
        int currentVertex = q.front();
        q.pop();
        cout<<currentVertex<<" ";
        for(int i = 0; i < adj[currentVertex].size();i++)
        {
            int neighbor = adj[currentVertex][i];
            if(visited[neighbor])
                continue;
            visited[neighbor]=true;
            q.push(neighbor);
        }
    }
    delete[] visited;
    
}

void Graph::DFS()
{
    bool* visited = new bool[V];
    for(int i = 0;i<V;i++)
        visited[i]=false;
    
    stack<int> s;    
    s.push(0);
    
    while(!s.empty())
    {
        int currentVertex = s.top();
        s.pop();
        if(visited[currentVertex])
            continue;
        visited[currentVertex]=true;
        cout<<currentVertex<<" ";
        
        for(int i = 0; i < adj[currentVertex].size();i++)
        {
            int neighbor = adj[currentVertex][i];
            s.push(neighbor);
        }
    }
    delete[] visited;
    
}
void Graph::DFSrec(int start,bool* visited)
{
     visited[start]=true;
     cout<<start<<" ";
     for(int i = 0; i < adj[start].size();i++)
     {
        int neighbor = adj[start][i];
         if(!visited[neighbor])
            DFSrec(neighbor,visited);
     }
    
}
void Graph::DFSrecursive()
{
    bool* visited = new bool[V];
    for(int i = 0;i<V;i++)
        visited[i]=false;
    
    DFSrec(0,visited);
    
    delete[] visited;
}
