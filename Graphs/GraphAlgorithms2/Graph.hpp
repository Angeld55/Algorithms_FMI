#include "GraphDPhelpFuncs.h"

#include <list> 
#include <limits.h> 
#include <vector>
#include <stack>
#include <queue>
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
	void addEdge(int v, int w, int weight);

	int getVerticesCount();

	int* TopologicalSort(); // Return an array with all the verticies in topologial-order
							

	// Dynamic programming algorithms


	void FloydWarshall();//path between all-pairs

	int* BellmanFord(int start); // path between a vertex and all other verticies


	int* LongestPath(int s); // longest paths form s to all other verticies (or between two vertices)


	int Dijkstra(int start, int end);// shorets paths from s to all other verticies (this function return the shoretst path to end only)



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
	edge t(w, weight);
	adj[v].push_back(t);
}

int Graph::getVerticesCount()
{
	return V;
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
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (minDistance[i][j] > minDistance[i][k] + minDistance[k][j])
				{
					if (minDistance[i][k] != MAX && minDistance[k][j] != MAX)
						minDistance[i][j] = minDistance[i][k] + minDistance[k][j];
				}
			}
		}
		cout << "k=" << k << endl;
		printMatrix(minDistance, V);
	}
}

int* Graph::BellmanFord(int start)
{
	int* distance = new int[V];
	for (int i = 0; i < V; i++)
		distance[i] = MAX;
	distance[start] = 0;


	for (int t = 0; t < V; t++)
	{
		bool isTheLastTime = t == V - 1;


		//Run through all the edges
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < adj[i].size(); j++)
			{
				if (distance[i] != MAX && distance[adj[i][j].dest] > distance[i] + adj[i][j].weight)
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
	delete[] visited;
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

int Graph::Dijkstra(int start, int end) //with lazy deletion
{
	struct tuple
	{
		int index;
		int distFromStart;
		tuple(int index, int distFromStart) :index(index), distFromStart(distFromStart){}
		bool tuple::operator<(const tuple&other)const
		{
			return (this->distFromStart > other.distFromStart);
		}
	};

	// dijkstra algorithm
	int* distances = new int[V];
	int* prev = new int[V];
	setAllTo(distances, V, INT_MAX);
	setAllTo(prev, V, INT_MAX); // let INT_MAX be UNDEFINED 


	distances[start] = 0;
	priority_queue<tuple> q;
	q.push(tuple(start, 0));
	while (!q.empty())
	{
		tuple current = q.top();
		q.pop();
		if (current.index == end)
		{
			printArray(distances, V);
			printPath(prev, V, start, end);
			int res = distances[end];
			delete[] distances, prev;
			return res;
		}
		int currNode = current.index;
		int distToCurr = current.distFromStart;
		for (int i = 0; i < adj[currNode].size(); ++i)
		{
			int newDest = adj[currNode][i].dest;
			int newDist = distToCurr + adj[currNode][i].weight;
			if (newDist < distances[newDest])
			{
				distances[newDest] = newDist;
				q.push(tuple(newDest, newDist));
				prev[newDest] = currNode;
			}
		}

	}
	return  INT_MAX;
}
