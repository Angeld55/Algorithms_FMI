#include "Graph.hpp"
int main()
{


	// Create a graph given in the above diagram 
	Graph g(8);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	g.addEdge(2, 5);
	g.addEdge(2, 6);

	g.addEdge(3, 7);
	g.addEdge(4, 7);

	g.addEdge(5, 7);
	g.addEdge(6, 7);
	std::cout << g.CountPaths(0, 7);
		
	//	return 0;
}

