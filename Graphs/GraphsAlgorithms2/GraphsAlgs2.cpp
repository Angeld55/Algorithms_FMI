#include "HelpFunctions.cpp"
#include <list> 
#include <limits.h> 
#include <vector>
#include <stack>
using namespace std;

struct edge
{
	int dest;
	int weight;
	edge(int d, int w)
	{
		dest = d;
		weight = w;
	}
};
class Graph
{
	int V;
	vector<vector<edge>> adj;
	void DfsTopSort(int vert, bool* visited, stack<int>& st);

public:
	Graph(int V);
	void addEdge(int v, int w,int weight);
	
	
	int* TopologicalSort();


	// Dynamic programming algorithms
	
	void FloydWarshall();//path between all-pairs

	int* BellmanFord(int start); // path between a vertex and all other verticies


	int* LongestPath(int s); // longest paths form s to all other verticies
	
	int CountPaths(int s,int t); // paths count between two verticies

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

void Graph::addEdge(int v, int w,int weight)
{
	edge t(w, weight);
	adj[v].push_back(t);
}

void Graph::FloydWarshall()
{
	int** minDistance = createMatrix(V);
	
	//mark all edges
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			minDistance[i][adj[i][j].dest] = adj[i][j].weight;
	}

	//min dist v to v is 0
	for (int i = 0; i < V; i++)
		minDistance[i][i] = 0;

	printMatrix(minDistance, V);


	for (int k = 0; k < V; k++)
	{
		for (int  i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (minDistance[i][j] > minDistance[i][k] + minDistance[k][j])
				{
					if (minDistance[i][k]!=MAX && minDistance[k][j]!=MAX)
						minDistance[i][j] = minDistance[i][k] + minDistance[k][j];
				}
			}
		}
		cout << "k=" << k<<endl;
		printMatrix(minDistance, V);
	}
}

int* Graph::BellmanFord(int start)
{
	int* distance = new int[V];
	for (int i = 0; i < V; i++)
		distance[i] = MAX;
	distance[start]=0;


	for (int t = 0; t < V; t++)
	{
		bool isTheLastTime = t == V - 1;


		//Run through all the edges
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < adj[i].size(); j++)
			{
				if (distance[i]!=MAX && distance[adj[i][j].dest] > distance[i] + adj[i][j].weight)
				{
					distance[adj[i][j].dest] = distance[i] + adj[i][j].weight;
					
					if (isTheLastTime)
					{
						std::cout << "Negative cycle detected";
						delete[] distance;
						return nullptr;
					}
				}
			}
			
		}
		printArray(distance, V);
	}
	return distance;

}

void Graph::DfsTopSort(int vert, bool* visited, stack<int>& st)
{
	visited[vert] = true;
	for (int i = 0; i < adj[vert].size(); i++)
	{
		if (!visited[adj[vert][i].dest])
			DfsTopSort(adj[vert][i].dest, visited, st);
	}
	st.push(vert);
}

int* Graph::TopologicalSort()
{
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

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

int* Graph::LongestPath(int s)
{
	int* topSort = TopologicalSort();

	int* dist = new int[V];
	for (int i = 0; i < V; i++)
		dist[i] = MIN;
	dist[s] = 0;
	for (int i = 0; i < V; i++)
	{	
		int currentVert = topSort[i];
		if (dist[currentVert] != MIN)
		{
			for (int j = 0; j < adj[currentVert].size(); j++)
			{
				if (dist[adj[currentVert][j].dest] < dist[currentVert] + adj[currentVert][j].weight)
					dist[adj[currentVert][j].dest] = dist[currentVert] + adj[currentVert][j].weight;
			}
		}
	}
	delete[] topSort;
	return dist;

}
int Graph::CountPaths(int s,int t)
{
	int* dyn = new int[V];
	for(int i = 0;i < V; i++)
		dyn[i]=0;
	dyn[s]=1;
	int* topSort = TopologicalSort();	
	for (int x = s; x <= t; x++)
	{
		for(int j =0; j <adj[x].size(); j++)
		{
			int y = adj[x][j].dest;
			dyn[y]+=dyn[x];
		}
	}
	return dyn[t];
}
int main()
{
	/*
	Graph g(5);
	g.addEdge(0, 1, 3);
	g.addEdge(1, 2, 2);
	g.addEdge(1, 3, 2);
	g.addEdge(3, 4, -7);
	g.addEdge(4, 1, -5);  
	
	g.BellmanFord(0);
	*/


	 //Bellman-ford
	/*
	Graph g(6);
	g.addEdge(0, 1, 10);
	g.addEdge(0, 5, 8);
	g.addEdge(2, 1, 1);
	g.addEdge(3, 2, -2);
	g.addEdge(4, 3, -1);
	g.addEdge(5, 4, 1);
	g.addEdge(4, 1, -4);
	g.addEdge(1, 3, 2);
	
	
	g.BellmanFord(0);
	*/

	Graph g(4);
	g.addEdge(0, 1, 1);
	g.addEdge(0, 2, 8);
	g.addEdge(0, 3, 6);
	g.addEdge(3, 2, 7);
	g.addEdge(1, 2, 9);
	
	int* res = g.longestPath(0);

	printArray(res,4);
//	printArray(g.longestPath(1),6);
	
}
