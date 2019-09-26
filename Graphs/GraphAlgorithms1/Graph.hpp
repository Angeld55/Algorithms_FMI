#include "GraphHelpFuncs.h"

#include <list> 
#include <limits.h> 
#include <vector>
#include <stack>


class Graph
{
	int V;
	vector<vector<int>> adj;
	bool isCyclicDFS(int v, bool visited[], bool *rs);
	void visitedDFS(int start, bool* visited);
	void Graph::DfsTopSort(int vert, bool* visited, stack<int>& st);
	Graph getTranspose();
	int getInDegree(int v);
	int getOutDegree(int v);
	bool allVerticesHasTheSameInAndOutDegree();
public:
	Graph(int V);
	void addEdge(int v, int w);


	int* Graph::TopologicalSort();

	bool isCyclic();

	bool hasOneStronglyConnectedComponent();

	bool hasEulerCircuit();

	int CountPaths(int s, int t);

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

void Graph::DfsTopSort(int vert, bool* visited, stack<int>& st)
{
	visited[vert] = true;
	for (int i = 0; i < adj[vert].size(); i++)
	{
		if (!visited[adj[vert][i]])
			DfsTopSort(adj[vert][i], visited, st);
	}
	st.push(vert);
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

void Graph::visitedDFS(int start, bool* visited)
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
	setAllTo(visited, V, false);

	visitedDFS(0, visited); //check witch are reachable from an arbitrary vertex

	if (!allTrue(visited, V)) // if there is a vertex that can not be reached -> false
		return false;

	Graph tr = getTranspose();

	setAllTo(visited, V, false);

	tr.visitedDFS(0, visited);

	return allTrue(visited, V);

}

bool Graph::hasEulerCircuit()
{
	return hasOneStronglyConnectedComponent() && allVerticesHasTheSameInAndOutDegree();
}

int* Graph::TopologicalSort()
{
	bool* visited = new bool[V];
	setAllTo(visited, V, false);

	stack<int> st;
	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			DfsTopSort(i, visited, st);
	}

	int* sortedArr = new int[V];
	for (int i = 0; i < V; i++)
	{
		sortedArr[i] = st.top();
		st.pop();
	}
	return sortedArr;
}

int Graph::CountPaths(int s, int t)
{
	int* dyn = new int[V];
	for (int i = 0; i < V; i++)
		dyn[i] = 0;
	dyn[s] = 1;
	int* topSort = TopologicalSort();
	for (int x = s; x <= t; x++)
	{
		for (int j = 0; j <adj[x].size(); j++)
		{
			int y = adj[x][j];
			dyn[y] += dyn[x];
		}
	}
	int res = dyn[t];
	delete[] dyn, topSort;
	return res;
}

