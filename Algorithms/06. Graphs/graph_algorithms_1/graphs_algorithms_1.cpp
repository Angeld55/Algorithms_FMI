#include <iostream>
#include <vector>
#include <queue>
#include <stack>


class Graph
{
	std::vector<std::vector<int>> adj;
	size_t V;
	bool oriented;

	void dfs_help_rec(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const;
	bool contains_cycle_rec(size_t start, std::vector<bool>& visited, std::vector<bool>& stack) const;
	void topo_sort_rec(size_t start, std::vector<bool>& visited, std::stack<size_t>& st) const;

	bool is_bipartite_help(size_t start, std::vector<int>& visited) const;

	size_t findBridgesDfsRec(size_t vertex, size_t vertexLevel, std::vector<size_t>& levels, std::vector<bool>& visited, std::vector<std::pair<size_t, size_t>>& result, std::vector<bool>& stack) const;

public:
	Graph(size_t V, bool isOriented);
	void addEdge(size_t start, size_t end);

	std::vector<size_t> BFS(size_t start) const;

	std::vector <size_t> DFS_ITER(size_t start) const;
	std::vector<size_t>  DFS_REC(size_t start) const;

	int BFS_shortest_path(size_t start, size_t end) const;

	bool containsCycle() const;

	std::vector<size_t> topoSort() const;

	bool isConnected() const;

	bool isBipartite() const;

	Graph getTranspose() const;

	std::vector<std::vector<size_t>> getStronglyConnectedComponents() const;

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

std::vector<size_t> Graph::BFS(size_t start) const
{
	std::vector<size_t> result;

	std::vector<bool> visited(V);

	std::queue<size_t> q;
	q.push(start);
	visited[start] = true;

	while (!q.empty())
	{
		size_t currentVertex = q.front();
		q.pop();

		for (int i = 0; i < adj[currentVertex].size(); i++)
		{
			size_t neighbor = adj[currentVertex][i];
			if (visited[neighbor])
				continue;
			
			result.push_back(currentVertex);
			visited[neighbor] = true;
			q.push(neighbor);
		}
	}

	return std::move(result);
}

int Graph::BFS_shortest_path(size_t start, size_t end) const
{
	std::vector<size_t> result;

	std::vector<bool> visited(V);

	std::queue<std::pair<size_t, size_t>> q; // <връх, разстояние от началото>

	q.push(std::make_pair(start, 0));
	visited[start] = true;

	while (!q.empty())
	{
		auto current = q.front();
		size_t currentVertex = current.first;
		size_t dist = current.second;

		if (currentVertex == end)
			return dist;

		q.pop();

		for (int i = 0; i < adj[currentVertex].size(); i++)
		{
			size_t neighbor = adj[currentVertex][i];

			if (visited[neighbor])
				continue;

			q.push(std::make_pair(neighbor, dist + 1));
			visited[neighbor] = true;
		}
	}

	return -1;
}

std::vector<size_t> Graph::DFS_ITER(size_t start) const
{
	std::vector<size_t> result;

	std::vector<bool> visited(V);

	std::stack<size_t> s;
	s.push(start);

	while (!s.empty())
	{
		size_t current = s.top();
		s.pop();

		if (visited[current])
			continue;

		visited[current] = true;
		result.push_back(current);

		for (int i = 0; i < adj[current].size(); i++)
		{
			size_t neighbor = adj[current][i];
			s.push(neighbor);
		}
	}
	return std::move(result);
}

void Graph::dfs_help_rec(size_t start, std::vector<bool>& visited, std::vector<size_t>& result) const
{
	visited[start] = true;
	result.push_back(start);

	for (int i = 0; i < adj[start].size(); i++)
	{
		size_t neighbor = adj[start][i];
		if (!visited[neighbor])
			dfs_help_rec(neighbor, visited, result);
	}
}
std::vector<size_t>  Graph::DFS_REC(size_t start) const
{
	std::vector<bool> visited(V);
	std::vector<size_t> result;

	dfs_help_rec(start, visited, result);

	return result;
}

bool Graph::contains_cycle_rec(size_t start, std::vector<bool>& visited, std::vector<bool>& stack) const
{
	if (!visited[start])
	{
		visited[start] = true;
		stack[start] = true;

		for (int i = 0; i < adj[start].size(); i++)
		{
			size_t neihbor = adj[start][i];

			if (!visited[neihbor] && contains_cycle_rec(neihbor, visited, stack))
				return true;
			else if (stack[neihbor])
				return true;
		}
	}
	stack[start] = false;
	return false;
}
bool Graph::containsCycle() const
{
	if (!oriented)
		throw std::exception("Error! The graph should be oriented!");

	std::vector<bool> visited(V);
	std::vector<bool> inStack(V);

	for (int i = 0; i < V; i++)
	{
		if (contains_cycle_rec(i, visited, inStack))
			return true;
	}
	return false;

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

bool Graph::isConnected() const
{
	if (oriented)
		throw std::exception("Error! The graph should NOT be oriented!");

	return BFS(0).size() == V;
}

bool Graph::is_bipartite_help(size_t start, std::vector<int>& visited) const // 0 unvisited, 1 - white, 2 - black
{
	std::queue<size_t> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		size_t currentVertex = q.front();
		size_t currentColor = visited[currentVertex]; //0 unvisited, 1 white, 2 black
		q.pop();


		for (int i = 0; i < adj[currentVertex].size(); i++)
		{
			size_t neighbor = adj[currentVertex][i];

			if (visited[neighbor] == currentColor)
				return false;

			if (visited[neighbor] != 0)
				continue;

			q.push(neighbor);

			visited[neighbor] = currentColor == 1 ? 2 : 1;
		}
	}
	return true;
}

bool Graph::isBipartite() const
{
	if (oriented)
		throw std::exception("Error! The graph should NOT be oriented!");

	std::vector<int> visited(V);
	for (int i = 0; i < V; i++)
	{
		if (visited[i] == 0 && !is_bipartite_help(i, visited))
			return false;
	}
	return true;
}

Graph Graph::getTranspose() const
{
	Graph result(V, true);

	for (int i = 0; i < adj.size(); i++)
	{
		for (int j = 0; j < adj[i].size(); j++)
			result.addEdge(adj[i][j], i);
	}
	return result;
}

std::vector<std::vector<size_t>> Graph::getStronglyConnectedComponents() const
{
	std::vector<size_t> topo = topoSort();

	Graph transponsedGraph = getTranspose();

	std::vector<bool> visited(V);

	std::vector<std::vector<size_t>> result;
	for (int i = 0; i < topo.size(); i++)
	{
		if (visited[topo[i]])
			continue;

		std::vector<size_t> currentStronglyConnectedComponent;
		transponsedGraph.dfs_help_rec(topo[i], visited, currentStronglyConnectedComponent);
		result.push_back(currentStronglyConnectedComponent);
	}

	return result;

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
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 0);

	g.addEdge(2, 4);
	g.addEdge(4, 5);
	g.addEdge(5, 6);
	g.addEdge(6, 4);

	g.addEdge(7, 6);
	g.addEdge(7, 8);

	auto scc = g.findCutEdges();

	for (int i = 0; i < scc.size(); i++)
		std::cout << scc[i].first << " " << scc[i].second << std::endl;
}
