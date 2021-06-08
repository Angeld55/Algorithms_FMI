#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <iomanip> 

using Edge = std::tuple<size_t, size_t, int>;
void printEdge(const Edge& e)
{
	size_t start = std::get<0>(e);
	size_t dest = std::get<1>(e);
	int weight = std::get<2>(e);

	std::cout << start << " " << dest << " " << weight << std::endl;
}

class Graph
{
	bool isOriented;
	size_t V;
	std::vector<std::vector<std::pair<int, int>>> adj;

	void dfs_help_rec(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const;

	size_t areConnected(size_t begin, size_t end) const;
public:
	Graph(size_t V, bool isOriented);
	void addEdge(size_t start, size_t end, int weight);

	Graph removeBiggerEdges(size_t weight);

	bool isPartOfMST(size_t start, size_t end);

};

Graph::Graph(size_t V, bool isOriented) : adj(V), V(V), isOriented(isOriented)
{}
void Graph::addEdge(size_t start, size_t end, int weight)
{
	adj[start].push_back(std::make_pair(end, weight));
	if (!isOriented)
		adj[end].push_back(std::make_pair(start, weight));
}

void Graph::dfs_help_rec(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const
{
	visited[start] = true;
	result.push_back(start);

	for (int i = 0; i < adj[start].size(); i++)
	{
		size_t neighbor = adj[start][i].first;
		if (!visited[neighbor])
			dfs_help_rec(neighbor, visited, result);
	}
}

size_t Graph::areConnected(size_t begin, size_t end) const
{
	std::vector<bool> visited(V);
	std::vector<size_t> result;

	dfs_help_rec(begin, visited, result);

	return visited[end];
}

Graph Graph::removeBiggerEdges(size_t weight)
{
	Graph res(V, false);

	for (int i = 0; i < adj.size(); i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
		{
			if (adj[i][j].second < weight)
				res.addEdge(i, adj[i][j].first, adj[i][j].second);
		}
	}
	return res;
}

bool Graph::isPartOfMST(size_t start, size_t end)
{
	//find edge weight
	size_t weight = -1;
	for (int j = 0; j < adj[start].size(); j++)
	{
		if (adj[start][j].first < end)
			weight = adj[start][j].second;
	}
	if (weight == -1)
		return false; // no edge between start and end.

	return removeBiggerEdges(weight).areConnected(start, end);
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


	std::cout << g.isPartOfMST(7, 1);


}