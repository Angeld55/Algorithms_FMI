#include<iostream> 
#include <list> 
#include <limits.h> 
#include <vector>
#include "HelpFunctions.cpp"

using namespace std;


class Graph
{
	int V;
	vector<vector<int>> adj;
	bool isCyclicDFS(int v, bool visited[], bool *rs);
	void visitedDFS(int start,bool* visited);
	Graph getTranspose();
	int getInDegree(int v);
	int getOutDegree(int v);
	bool allVerticesHasTheSameInAndOutDegree();
public:
	Graph(int V);
	void addEdge(int v, int w);
	
	
	
	bool isCyclic();
	
	bool hasOneStronglyConnectedComponent();
	
	int countPaths(int start,int end); //Must be acyclic-> Naive implementation. For better solution, check the GraphsAlgorithms2 or the Dynamic programming algorithms
	
	bool hasEulerCircuit();
	
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


bool Graph::isCyclicDFS(int v, bool visited[], bool *recStack)
{
	if (visited[v] == false)
	{
		visited[v] = true;
		recStack[v] = true;


		for (int i = 0; i < adj[v].size(); i++)
		{
			int child = adj[v][i];
			if (!visited[child] && isCyclicDFS(child, visited, recStack))
				return true;
			else if (recStack[child])
				return true;
		}

	}
	recStack[v] = false;
	return false;
}
int Graph::getInDegree(int v)
{
	int count = 0;
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			if (adj[i][j] == v)
				count++;
		}

	}
	return count;
}
int Graph::getOutDegree(int v)
{
	return adj[v].size();
}
bool Graph::allVerticesHasTheSameInAndOutDegree()
{
	for (int i = 0; i < V; i++)
	{
		if (getInDegree(i) != getOutDegree(i))
			return false;
	}
	return true;
}
Graph Graph::getTranspose() 
{
	Graph tr(V);
	for (int i = 0; i < adj.size(); i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			tr.addEdge(adj[i][j], i);
	}
	return tr;
}

void Graph::visitedDFS(int start,bool* visited)
{
	if (visited[start])
		return;
	visited[start] = true;
	for (int i = 0; i < adj[start].size(); i++)
		visitedDFS(adj[start][i], visited);
}
bool Graph::isCyclic() 
{
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = recStack[i] = false;

	bool isCyc = false;
	for (int i = 0; i < V; i++)
		if (isCyclicDFS(i, visited, recStack))
		{
			isCyc = true;
			break;
		}
	delete[] visited;
	delete[] recStack;
	return isCyc;
}


bool Graph::hasOneStronglyConnectedComponent()
{
	bool* visited = new bool[V];
	setAllTo(visited,V,false);
	
	visitedDFS(0, visited); //check witch are reachable from an arbitrary vertex

	if (!allTrue(visited, V)) // if there is a vertex that can not be reached -> false
		return false;

	Graph tr = getTranspose();

	setAllTo(visited,V, false);

	tr.visitedDFS(0, visited);

	return allTrue(visited,V);

} 
int Graph::countPaths(int start,int end)  //Must be acyclic-> Naive implementation. For better solution, check the GraphsAlgorithms2 or the Dynamic programming algorithms
{
	if (start == end)
		return 1;
	int paths = 0;
	for (int i = 0; i < adj[start].size(); i++)
		paths += countPaths(adj[start][i], end);
	return paths;
}
bool Graph::hasEulerCircuit()
{
	return hasOneStronglyConnectedComponent() && allVerticesHasTheSameInAndOutDegree();
}


int main()
{


	// Create a graph given in the above diagram 
	Graph g(8);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	g.addEdge(2, 5);
	g.addEdge(2, 6);

	g.addEdge(3, 7);
	g.addEdge(4, 7);

	g.addEdge(5, 7);
	g.addEdge(6, 7);

	std::cout << g.countPaths(0,7);

	//	return 0;
}