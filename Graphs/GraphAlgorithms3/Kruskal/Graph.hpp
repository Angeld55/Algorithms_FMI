#include "Union-Find.hpp"
#include <list> 
#include <limits.h> 
#include <vector>
#include <stack>
#include <algorithm>


class Graph
{
	struct edge
	{
		edge(int start, int end,int weight) :start(start), end(end),weight(weight){}
		int start;
		int end;
		int weight;
		bool operator<(const edge&other)const
		{
			return (this->weight < other.weight);
		}
	};
	vector<edge> graph;
	int V;
public:

	Graph(int V);
	void addEdge(int start, int end, int weight);
	void print();
	int getV();

	Graph Kruskal();
};

Graph::Graph(int V) :V(V)
{
}

void Graph::addEdge(int start, int end, int weight)
{
	graph.push_back(edge(start, end, weight));
}

inline void Graph::print()
{
	for (int i = 0; i < graph.size(); ++i)
		cout << "<" << graph[i].start << "," << graph[i].end << ",weight:" << graph[i].weight<<">"<< endl;
	
}

int Graph::getV()
{
	return V;
}

Graph Graph::Kruskal()
{
	Graph MST(V);
	UnionFind u(V);
	
	vector<edge> copyGraph = graph;

	sort(copyGraph.begin(), copyGraph.end());

	int edgesInMST = 0;
	int vectorInd = 0;
	while (edgesInMST!=V-1)
	{
		edge current = copyGraph[vectorInd];
		if (!u.AreInOneSet(current.start,current.end)) //does this edge makes a loop
		{
			MST.addEdge(current.start, current.end, current.weight);
			u.Union(current.start, current.end);
			edgesInMST++;
		}
		vectorInd++;

	}
	return MST;
}



