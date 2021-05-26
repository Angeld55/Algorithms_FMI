#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <iomanip> 
#include "Union-find/Union-find.h"

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


	bool is_bipartite_help(size_t start, std::vector<int>& visited);

public:
	Graph(size_t V, bool isOriented);
	void addEdge(size_t start, size_t end, int weight);

    size_t dijkstra(size_t start, size_t end, std::vector<size_t>& path) const;
	std::vector<size_t> bellmanFord(size_t start) const;
	std::vector<std::vector<int>> FloydWarshall() const;

	size_t Prim(std::vector<Edge>& MST) const;
	size_t Kruskal(std::vector<Edge>& MST) const;

};

Graph::Graph(size_t V, bool isOriented) : adj(V), V(V), isOriented(isOriented)
{}
void Graph::addEdge(size_t start, size_t end, int weight)
{
	adj[start].push_back(std::make_pair(end, weight));
	if (!isOriented)
		adj[end].push_back(std::make_pair(start,weight));
}

size_t Graph::dijkstra(size_t start, size_t end, std::vector<size_t>& path) const
{
	std::vector<size_t> distances(V, INT_MAX);
	std::vector<size_t> prevs(V);


	struct vertexAndDistancePair
	{
		size_t vertex;
		size_t distFromStart;

		bool operator<(const vertexAndDistancePair& other) const
		{
			return distFromStart > other.distFromStart;
		}
	};

	std::priority_queue<vertexAndDistancePair> q;

	distances[start] = 0;

	q.push({ start, 0 });

	while (!q.empty())
	{
		vertexAndDistancePair current = q.top();
		q.pop();

		if (current.vertex == end)
		{
			while (end != start)
			{
				path.push_back(end);
				end = prevs[end];
			}
			path.push_back(start);

			std::reverse(path.begin(), path.end());

			return distances[current.vertex];
		}
	
		for (int i = 0; i < adj[current.vertex].size(); i++)
		{
			size_t currentNeighbor = adj[current.vertex][i].first;

			size_t newDist = current.distFromStart + adj[current.vertex][i].second;
			if (distances[currentNeighbor] > newDist)
			{
				distances[currentNeighbor] = newDist;
				q.push({ currentNeighbor, newDist });
				prevs[currentNeighbor] = current.vertex;
			}
		}

	}
	return INT_MAX;

}

std::vector<size_t> Graph::bellmanFord(size_t start) const
{
	std::vector<size_t> distances(V, INT_MAX);

	distances[start] = 0;

	for (int t = 0; t < V; t++)
	{

		bool isLastIter = t == V - 1;

		for (int i = 0; i < V; i++)
		{
			if (distances[i] == INT_MAX)
				continue;

			for (int j = 0; j < adj[i].size(); j++)
			{
				if (distances[i] + adj[i][j].second < distances[adj[i][j].first])
				{
					if (isLastIter)
						throw std::exception("Negative cycle detected!");
					distances[adj[i][j].first] = distances[i] + adj[i][j].second;
				}
			}

		}
	}
	return distances;
}


size_t Graph::Prim(std::vector<Edge>& MST) const
{
	auto comp = [](const Edge& lhs, const Edge& rhs)
	{
		return std::get<2>(lhs) > std::get<2>(rhs);
	};

	std::priority_queue<Edge, std::vector<Edge>, decltype(comp)> q;

	std::vector<bool> visited(V);

	q.push(std::make_tuple(0, 0, 0));
	size_t addedEdges = 0;
	size_t result = 0;

	bool isFirst = true;

	while (addedEdges < V-1)
	{
		auto current = q.top();
		q.pop();
		
		size_t start =  std::get<0>(current);
		size_t dest = std::get<1>(current);
		int weight = std::get<2>(current);

		if (visited[dest])
			continue;

		visited[dest] = true;

		for (int i = 0; i < adj[dest].size(); i++)
		{
			q.emplace(dest, adj[dest][i].first, adj[dest][i].second);
		}

		if (isFirst)
		{
			isFirst = false;
			continue;
		}

		MST.emplace_back(start, dest, weight);
		result += weight;
		addedEdges++;
		isFirst = false;
	}
	return result;

}





size_t Graph::Kruskal(std::vector<Edge>& MST) const
{

	std::vector<Edge> edges;
	for (int i = 0; i < adj.size(); i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			edges.emplace_back(i, adj[i][j].first, adj[i][j].second);
	}
	std::sort(edges.begin(), edges.end(), [](const Edge& lhs, const Edge& rhs)
	{
		return std::get<2>(lhs) < std::get<2>(rhs);
	});

	size_t resultMSTWeight = 0;
	size_t edgesIncluded = 0;

	UnionFind uf(V);

	for (int i = 0; i < edges.size() && edgesIncluded < V - 1; i++)
	{
		auto& currentEdge = edges[i];
		size_t start = std::get<0>(currentEdge);
		size_t dest = std::get<1>(currentEdge);
		int weight = std::get<2>(currentEdge);

		if (!uf.Union(start, dest)) //checks for a cycle
			continue;

		resultMSTWeight += weight;

		MST.emplace_back(start, dest, weight);
	}

	return resultMSTWeight;
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

	{ //Dijkstra example
		std::vector<size_t> path;
		std::cout << "Shortest weight path from 0 to 4(with Dijkstra):" << g.dijkstra(0, 4, path) << std::endl;
		std::cout << "Path :";
		for (int i = 0; i < path.size(); i++)
			std::cout << path[i] << " ";
		std::cout << std::endl << std::endl << std::endl;
	}


	{ //Bellman-ford example

		std::cout << "Shortest paths from 0 to every other vertex (Bellman-Ford): " << std::endl;
		std::vector<size_t> paths = g.bellmanFord(0);

		for (int i = 0; i < paths.size(); i++)
			std::cout << "< To: " << i <<", path weight: " << paths[i] << " >   " <<std::endl;
		std::cout << std::endl << std::endl << std::endl;
	}


	{ //Floyd-Warshall  example

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

	{ // Prim example
		std::vector<Edge> MST;
		std::cout << "MST(Prim): " << g.Prim(MST) << std::endl;
		std::cout << "Edges: " << std::endl;

		for (int i = 0; i < MST.size(); i++)
			printEdge(MST[i]);
		std::cout << std::endl << std::endl << std::endl;
	}

	{ // Kruskal example
		std::vector<Edge> MST;
		std::cout << "MST(Kruskal): " << g.Prim(MST) << std::endl;
		std::cout << "Edges: " << std::endl;

		for (int i = 0; i < MST.size(); i++)
			printEdge(MST[i]);
	}
}

