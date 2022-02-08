#include <iostream>
#include <vector>
using namespace std;

class RandomGraph
{
	std::vector<std::vector<size_t>> adj;
	size_t n;

public:
	RandomGraph(size_t n) : n(n), adj(n) {}
	void addEdge(size_t start, size_t end)
	{
		adj.at(start).push_back(end);
		adj.at(end).push_back(start);
	}
	const std::vector<size_t>& getAdjacentVertices(size_t start) const
	{
		if (start >= n)
			throw std::logic_error("Error in getAdjacentVertices. Given start doesn't exist! ");
		return adj.at(start);
	}
	size_t getVerticesCount() const
	{
		return n;
	}

};

bool hamilthonian_path_rec(const RandomGraph& currentGraph, size_t start, size_t currentVertex, std::vector<bool>& visited, size_t recursionDepth)
{
	visited[currentVertex] = true;
	auto currentAdj = currentGraph.getAdjacentVertices(currentVertex);
	for (size_t i = 0; i < currentAdj.size(); i++)
	{
		size_t neihbor = currentAdj[i];

		if (neihbor == start && recursionDepth == currentGraph.getVerticesCount())
			return true; //hamiltonian cycle spoted!

		if (visited[neihbor])
			continue;
		if (hamilthonian_path_rec(currentGraph, start, neihbor, visited, recursionDepth + 1))
			return true;
	}
	visited[currentVertex] = false;
	return false;
}

bool hamilthonian_path(const RandomGraph& currentGraph)
{
	for (size_t i = 0; i < currentGraph.getVerticesCount(); i++)
	{
		std::vector<bool> visited(currentGraph.getVerticesCount());
		if (hamilthonian_path_rec(currentGraph, i, i, visited, 1))
			return true;
	}
	return false;
}


int main()
{
	RandomGraph g(4);

	g.addEdge(0, 1);
	g.addEdge(2, 1);
	g.addEdge(3, 2);
	g.addEdge(3, 0);
	std::cout << hamilthonian_path(g) << std::endl;
}
