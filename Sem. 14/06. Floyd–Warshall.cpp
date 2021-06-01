#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <iomanip> 


using Edge = std::tuple<size_t, size_t, int>;


class Graph
{
	bool isOriented;
	size_t V;
	std::vector<std::vector<std::pair<int, int>>> adj;

public:
	Graph(size_t V, bool isOriented);
	void addEdge(size_t start, size_t end, int weight);

	std::vector<std::vector<int>> FloydWarshall() const;


};

Graph::Graph(size_t V, bool isOriented) : adj(V), V(V), isOriented(isOriented)
{}
void Graph::addEdge(size_t start, size_t end, int weight)
{
	adj[start].push_back(std::make_pair(end, weight));
	if (!isOriented)
		adj[end].push_back(std::make_pair(start, weight));
}

std::vector<std::vector<int>> Graph::FloydWarshall() const
{

	std::vector<std::vector<int>> minDistances;
	minDistances.resize(V, std::vector<int>(V, INT_MAX));

	//mark all edges
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			minDistances[i][adj[i][j].first] = adj[i][j].second;
	}

	//min dist v to v is 0
	for (int i = 0; i < V; i++)
		minDistances[i][i] = 0;


	for (int k = 0; k < V; k++)
	{
		for (int i = 0; i < V; i++)
		{
			for (int j = 0; j < V; j++)
			{
				if (minDistances[i][j] > minDistances[i][k] + minDistances[k][j])
				{
					if (minDistances[i][k] != INT_MAX && minDistances[k][j] != INT_MAX)
						minDistances[i][j] = minDistances[i][k] + minDistances[k][j];
				}
			}
		}
	}
	return std::move(minDistances);
}


int main()
{
	Graph g(9, false);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 7, 11);
	g.addEdge(1, 2, 8);
	g.addEdge(7, 8, 7);
	g.addEdge(7, 6, 1);
	g.addEdge(8, 6, 6);
	g.addEdge(8, 2, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(6, 5, 2);
	g.addEdge(2, 3, 7);
	g.addEdge(3, 5, 14);
	g.addEdge(3, 4, 9);
	g.addEdge(5, 4, 10);

    //Floyd-Warshall  example

	std::cout << "Shortest paths between every pair of vertices (Floyd-Warshall): " << std::endl;
	std::vector<std::vector<int>> paths = g.FloydWarshall();

	for (int i = 0; i < paths.size(); i++)
	{
		for (int j = 0; j < paths[i].size(); j++)
			std::cout << std::setw(5) << paths[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << std::endl << std::endl << std::endl;

}
