#include "Graph.hpp"

int main()
{
    Graph g(6);
   
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);
    g.addEdge(1,4);
    g.addEdge(2,5);
  
    cout<<"BFS: ";
    g.BFS();
    cout<<endl;
    
    cout<<"DFS: ";
    g.DFS();
    cout<<endl;
    
    cout<<"DFS recursive: ";
    g.DFSrecursive();
    cout<<endl;
}
