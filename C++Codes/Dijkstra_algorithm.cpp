// A C++ program for Dijkstra's single source shortest path algorithm.
// The program takes input as edges of the graoh

#include <bits/stdc++.h>
using namespace std;

int V; //number of nodes
int E; //number of edges

int minDistance(int dist[], bool track[])
{
	int min = INT_MAX, min_index;

	for (int v = 1; v <= V; v++)
		if (track[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

//print solution
void print(int dist[])
{
	cout << "Vertex \t Distance from Source" << endl;
	for (int i = 1; i <= V; i++)
		cout << i << " \t\t" << dist[i] << endl;
}

// Function that implements Dijkstra's algorithm
void dijkstra(vector<vector<int>> adj, int src)
{
	int dist[V]; //array to hold the shortest distance 

	bool track[V]; 

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 1; i <= V; i++)
		dist[i] = INT_MAX, track[i] = false;

	// Distance of source always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 1; count < V; count++)
	{
		int u = minDistance(dist, track);

		// Mark the picked vertex as processed
		track[u] = true;

		for (int v = 1; v <= V; v++)
			if (!track[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v])
				dist[v] = dist[u] + adj[u][v];
	}

	// print the constructed distance array
	print(dist);
}

// driver program 
int main()
{
    cin >> V >> E;
	vector<vector<int>> adj(V + 1, vector<int>(V + 1, 0));
	int u, v, w;

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		adj[u][v] = w;
		adj[v][u] = w;
	}

	dijkstra(adj, 1);

	return 0;
}