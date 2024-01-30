#include <bits/stdc++.h>
using namespace std;

// Number of vertices in the graph
#define V 5
int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;
	for (int v = 0; v < V; v++)
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
	return min_index;
}

//print constructed MST 
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int i = 1; i < V; i++)
		cout << parent[i] << " - " << i << " \t"
			<< graph[i][parent[i]] << " \n";
}
//  construct MST 
void primMST(int graph[V][V])
{
	int parent[V]; //for storing MST 
  
	int key[V];
	bool mstSet[V];

	// Initialize all keys as INFINITE
	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	//root
	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++) 
  {
		int u = minKey(key, mstSet);
		mstSet[u] = true;

		for (int v = 0; v < V; v++)
		{
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
		}
	}
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = {  { 0, 3, 1, 6, 8 },
						{ 3, 0, 10, 9, 4 },
						{ 1, 10, 0, 2, 0 },
						{ 6, 9, 2, 0, 7 },
						{ 8, 4, 0, 7, 0 } };
  
	clock_t start, end;
  start = clock();
  
	primMST(graph);
  
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cout << time_taken;
  
	return 0;
}
