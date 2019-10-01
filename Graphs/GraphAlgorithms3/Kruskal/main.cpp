#include "Graph.hpp"
int main()
{
 
	Graph g(4);
	g.addEdge(0, 1, 6);
	g.addEdge(1, 3, 1);
	g.addEdge(3, 2, 3);
	g.addEdge(2, 0, 2);
	g.addEdge(0, 3, 5);
	g.addEdge(2, 1, 1);

	g.print();

	Graph MST = g.Kruskal();

	cout << endl;

	MST.print();
		
	//	return 0;
}

