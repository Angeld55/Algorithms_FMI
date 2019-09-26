#include "Graph.hpp"
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

	//Graph g(4);
	//g.addEdge(0, 1, 1);
	//g.addEdge(0, 2, 8);
	//g.addEdge(0, 3, 6);
	//g.addEdge(3, 2, 7);
	//g.addEdge(1, 2, 9);
	//
	//int* res = g.LongestPath(0);

	//printArray(res,4);

	Graph g(7);
	g.addEdge(0, 1, 5);
	g.addEdge(1, 0, 3);

	g.addEdge(0, 2, 6);
	g.addEdge(1, 3, 3);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 5, 1);
	g.addEdge(5, 6, 10);
	g.addEdge(3, 4, 2);
	g.addEdge(4, 6, 3);

	//cout << g.Dijkstra(0, 6);
	//printArray(g.LongestPath(0),g.getVerticesCount());
	//g.FloydWarshall();
	
}
