
#include <iostream>
#include <vector>
#include <queue>
#include <stack>


class Graph
{
	std::vector<std::vector<int>> adj;
	size_t V;
	bool oriented;

	size_t findBridgesDfsRec(size_t vertex, size_t vertexLevel, std::vector<size_t>& levels, std::vector<bool>& visited, std::vector<std::pair<size_t, size_t>>& result, std::vector<bool>& stack) const;

public:
	Graph(size_t V, bool isOriented);
	void addEdge(size_t start, size_t end);

	std::vector<std::pair<size_t, size_t>> Graph::findCutEdges() const;

};
Graph::Graph(size_t V, bool isOriented) : adj(V), V(V), oriented(isOriented)
{}
void Graph::addEdge(size_t start, size_t end)
{
	adj[start].push_back(end);
	if (!oriented)
		adj[end].push_back(start);
}

std::vector<std::pair<size_t, size_t>> Graph::findCutEdges() const
{
	std::vector<size_t> levels(V,9999);
	std::vector<bool> visited(V, false);
	std::vector<bool> stack(V, false);

	std::vector<std::pair<size_t, size_t>> result;
	
	findBridgesDfsRec(0,0, levels, visited,result, stack);

	return std::move(result);
}

size_t Graph::findBridgesDfsRec(size_t vertex, size_t vertexLevel, std::vector<size_t>& levels, std::vector<bool>& visited, std::vector<std::pair<size_t, size_t>>& result, std::vector<bool>& stack) const
{
	stack[vertex] = true;
	levels[vertex] = vertexLevel;
	size_t minBack = vertexLevel;

	for (int i = 0; i < adj[vertex].size(); i++)
	{
		size_t neihbor = adj[vertex][i]
			;
		if (!visited[neihbor] && !stack[neihbor])
		{
			size_t b = findBridgesDfsRec(neihbor, vertexLevel + 1, levels, visited, result, stack);

			if (b > levels[vertex])
				result.emplace_back(vertex, neihbor);
			else
				minBack = std::min(minBack, b);
		}

		if (!visited[neihbor] && stack[neihbor])
		{
			if (levels[neihbor] < minBack &&  levels[neihbor] != levels[vertex] - 1)
				minBack = levels[neihbor];
		}
	}
	visited[vertex] = true;
	stack[vertex] = false;

	return minBack;
}
int main()
{
	Graph g(9, false);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(3, 2);

	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 4);

	g.addEdge(1, 7);
	g.addEdge(8, 7);

	auto scc = g.findCutEdges();

	for (int i = 0; i < scc.size(); i++)
		std::cout << scc[i].first << " " << scc[i].second << std::endl;
}