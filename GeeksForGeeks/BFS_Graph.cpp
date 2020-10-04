// Program to print BFS traversal from a given source vertex. BFS(int s) 
// traverses vertices reachable from s.
#include <iostream>
#include <list>
 
using namespace std;
 
// This class represents a directed graph using adjacency list representation
class Graph
{
	int V;		// No. of vertices
	list<int> *adj;	// Pointer to an array containing adjacency lists
public:
	Graph(int V);  // Constructor
	void addEdge(int v, int w); // function to add an edge to graph
	void BFS(int s);  // prints BFS traversal from a given source s
};
 
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
}
 
void Graph::addEdge(int v, int w)
{
	adj[v].push_back(w); // Add w to v’s list.
}

void Graph::BFS(int s)
{
	// Mark all the vertices as not visited
	bool *visited = new bool [V];
	for(int i=0; i<V; ++i)
		visited[i] = false;

	// Create a queue for BFS
	list<int> que;

	// Mark the current node as visited and enqueue it	
	cout << s << ' ';
	que.push_back(s);
	visited[s] = true;

	while(!que.empty())
	{
		// Dequeue a vertex from queue
		int temp = que.front();
		que.pop_front();
		
		// Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited
        // print it and enqueue it
        for(list<int>::iterator it = adj[temp].begin(); it != adj[temp].end(); it++)
		{
			if(visited[*it]==false)
			{
				visited[*it] = true;
				cout << *it << ' ';
				que.push_back(*it);
			}
		}
	}
	cout << '\n';
	return;
}
 
// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Graph g(4);
	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);
 
	cout << "Following is Breadth First Traversal "
		 << "(starting from vertex 2) \n";
	g.BFS(2);
 
	return 0;
}