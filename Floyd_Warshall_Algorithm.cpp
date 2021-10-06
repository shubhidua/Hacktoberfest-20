// C++ Program for Floyd Warshall Algorithm

//The Floyd Warshall Algorithm is for solving the All Pairs Shortest Path problem.
//The problem is to find shortest distances between every pair of vertices in a
//given edge weighted directed Graph.

#include <bits/stdc++.h>
using namespace std;

int V; //number of nodes
int E; //number of edges

//Function to print solution matrix
void print(vector<vector<int>> &dist)
{
	cout << "Solution matrix for shortest distances"
			" between every pair of vertices \n";
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (dist[i][j] == INT_MAX)
				cout << "INF"
					 << "	 ";
			else
				cout << dist[i][j] << "	 ";
		}
		cout << endl;
	}
}

// function for Floyd Warshall algorithm
void floydWarshall(vector<vector<int>> &adj)
{
	//Output 2-D vector that store shortest distances
	vector<vector<int>> dist(V + 1, vector<int>(V + 1));
	int i, j, k;

	//Initialize the solution matrix same as input graph matrix.
	for (i = 1; i <= V; i++)
		for (j = 1; j <= V; j++)
			dist[i][j] = adj[i][j];

	for (k = 1; k <= V; k++)
	{ // Pick all vertices as source one by one
		for (i = 1; i <= V; i++)
		{ // Pick all vertices as destination for the above picked source
			for (j = 1; j <= V; j++)
			{
				if (dist[i][j] > (dist[i][k] + dist[k][j]) && (dist[k][j] != INT_MAX && dist[i][k] != INT_MAX))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}

	// finally print the solution
	print(dist);
}

// Driver code
int main()
{
	cin >> V >> E;
	vector<vector<int>> adj(V + 1, vector<int>(V + 1, INT_MAX));

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (i == j)
				adj[i][j] = 0;
		}
	}

	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		adj[u][v] = w;
	}

	floydWarshall(adj);
	return 0;
}
