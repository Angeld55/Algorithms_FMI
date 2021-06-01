
#include <iostream>
#include <vector>
#include <queue>
#include <stack>


class Graph
{
	std::vector<std::vector<int>> adj;
	size_t V;
	bool oriented;
	void topo_sort_rec(size_t start, std::vector<bool>& visited, std::stack<size_t>& st) const;



public:
	Graph(size_t V, bool isOriented);
	void addEdge(size_t start, size_t end);

	std::vector<size_t> topoSort() const;
	size_t countPathsDag(size_t s, size_t t) const;
};
Graph::Graph(size_t V, bool isOriented) : adj(V), V(V)
{}
void Graph::addEdge(size_t start, size_t end)
{
	adj[start].push_back(end);
}


void Graph::topo_sort_rec(size_t start, std::vector<bool>& visited, std::stack<size_t>& st) const
{
	visited[start] = true;
	for (int i = 0; i < adj[start].size(); i++)
	{
		size_t neihbor = adj[start][i];
		if (!visited[neihbor])
			topo_sort_rec(neihbor, visited, st);
	}
	st.push(start);
}
std::vector<size_t> Graph::topoSort() const
{
	std::vector<bool> visited(V);
	std::stack<size_t> st;

	for (int i = 0; i < V; i++)
	{
		if (!visited[i])
			topo_sort_rec(i, visited, st);
	}
	std::vector<size_t> result(V);

	for (int i = 0; i < V; i++)
	{
		result[i] = st.top();
		st.pop();
	}

	return std::move(result);
}
size_t Graph::countPathsDag(size_t start, size_t end) const
{
	std::vector<size_t> DP(V);
	DP[start] = 1;

	std::vector<size_t> topSort = topoSort();

	for (int i = 0; i < topSort.size(); i++)
	{
		for (int j = 0; j <adj[i].size(); j++)
		{
			size_t neihbor = adj[i][j];
			DP[neihbor] += DP[i];
		}
	}
	int res = DP[end];
	return res;
}

int main()
{
	Graph g(5, true);

	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 4);

	std::cout << g.countPathsDag(1, 4);
}
