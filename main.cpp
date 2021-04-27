/***************************************************
*  Programmed by : Ethan Bockler, Tim Diersing,    *
*                  Alan Vuong                      *
*  Assignment : A11 : DFS and BFS			       *
*												   *
*  This program will demonstrate a depth - first   *
*  and breadth - first search of a directed graph. *
****************************************************/

#include "main_header.h"
#include "BfsGraph.h"
#include "DfsGraph.h"

/***********************************************************
* This program implements a DFS and BFS search algorithm
* on a directed graph and attempts to find and identify
* the edges. This program will also output the origin
* vertex, destination vertex, and total distance traveled.
**************************************************************/

int main() {
	// Prints heading
	PrintHeader();

	// Creates object for BFS and DFS
	DfsGraph dfs;
	BfsGraph bfs;

	// Adds the node and edges for the dfs graph
	cout << " DFS" << endl << "-----" << endl;
	dfs.addNode("Chicago");
	dfs.addNode("Seattle");
	dfs.addNode("Boston");
	dfs.addNode("San Francisco");
	dfs.addNode("Denver");
	dfs.addNode("New York");
	dfs.addNode("Los Angeles");
	dfs.addNode("Kansas City");
	dfs.addNode("Atlanta");
	dfs.addNode("Dallas");
	dfs.addNode("Houston");
	dfs.addNode("Miami");

	// Add edges for dfs graph
	dfs.addEdge("Chicago", "Seattle", 2097);
	dfs.addEdge("Chicago", "Boston", 983);
	dfs.addEdge("Denver", "Chicago", 1003);
	dfs.addEdge("New York", "Chicago", 787);
	dfs.addEdge("Seattle", "Denver", 1331);
	dfs.addEdge("Boston", "New York", 214);
	dfs.addEdge("Seattle", "San Francisco", 807);
	dfs.addEdge("Denver", "San Francisco", 1267);
	dfs.addEdge("Kansas City", "New York", 1260);
	dfs.addEdge("Kansas City", "Chicago", 533);
	dfs.addEdge("Kansas City", "Denver", 599);
	dfs.addEdge("San Francisco", "Los Angeles", 381);
	dfs.addEdge("Los Angeles", "Denver", 1015);
	dfs.addEdge("Dallas", "Los Angeles", 1435);
	dfs.addEdge("Dallas", "Kansas City", 496);
	dfs.addEdge("New York", "Atlanta", 888);
	dfs.addEdge("Kansas City", "Atlanta", 864);
	dfs.addEdge("Dallas", "Atlanta", 781);
	dfs.addEdge("Houston", "Dallas", 239);
	dfs.addEdge("Houston", "Atlanta", 810);
	dfs.addEdge("Atlanta", "Miami", 661);
	dfs.addEdge("Miami", "Houston", 1187);
	dfs.addEdge("Kansas City", "Los Angeles", 1663);

	// Starting point of DFS
	dfs.Dfs("Denver");
	cout << "-----------------------" << endl;
	cout << endl;
	// Prints the initial, terminal, and edge type
	dfs.print();


	// ********* BFS ****************
	cout << endl << " BFS" << endl << "-----" << endl;

	// Adds node for BFS
	bfs.addNode("Chicago");
	bfs.addNode("Seattle");
	bfs.addNode("Boston");
	bfs.addNode("San Francisco");
	bfs.addNode("Denver");
	bfs.addNode("New York");
	bfs.addNode("Los Angeles");
	bfs.addNode("Kansas City");
	bfs.addNode("Atlanta");
	bfs.addNode("Dallas");
	bfs.addNode("Houston");
	bfs.addNode("Miami");

	// Adds edges for BFS
	bfs.addEdge("Chicago", "Seattle", 2097);
	bfs.addEdge("Chicago", "Boston", 983);
	bfs.addEdge("Denver", "Chicago", 1003);
	bfs.addEdge("New York", "Chicago", 787);
	bfs.addEdge("Seattle", "Denver", 1331);
	bfs.addEdge("Boston", "New York", 214);
	bfs.addEdge("Seattle", "San Francisco", 807);
	bfs.addEdge("Denver", "San Francisco", 1267);
	bfs.addEdge("Kansas City", "New York", 1260);
	bfs.addEdge("Kansas City", "Chicago", 533);
	bfs.addEdge("Kansas City", "Denver", 599);
	bfs.addEdge("San Francisco", "Los Angeles", 381);
	bfs.addEdge("Los Angeles", "Denver", 1015);
	bfs.addEdge("Dallas", "Los Angeles", 1435);
	bfs.addEdge("Dallas", "Kansas City", 496);
	bfs.addEdge("New York", "Atlanta", 888);
	bfs.addEdge("Kansas City", "Atlanta", 864);
	bfs.addEdge("Dallas", "Atlanta", 781);
	bfs.addEdge("Houston", "Dallas", 239);
	bfs.addEdge("Houston", "Atlanta", 810);
	bfs.addEdge("Atlanta", "Miami", 661);
	bfs.addEdge("Miami", "Houston", 1187);
	bfs.addEdge("Kansas City", "Los Angeles", 1663);

	bfs.Bfs("Denver");

	bfs.print();

	cout << "\n";

	bool connection = dfs.isStronglyConnected();

	if (connection == true)
	{
		cout << "A directed graph is said to be strongly connected if there is a path between all pairs of vertices.\n";
		cout << "According to the definition, the graph ** IS **  strongly connected because each node can access every other node\n";
		cout << "at any point within the graph." << endl;
	}
	else
	{
		cout << "The graph is not strongly connected.";
	}

	return 0;
}