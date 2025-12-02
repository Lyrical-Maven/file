#include <iostream>
using namespace std;
int adj[10][10]; // adjacency matrix (max 10 vertices)
int visited[10]; // to mark visited nodes
int n; // number of vertices
void dfs(int v) {
cout << v << " "; // print current vertex
visited[v] = 1; // mark as visited
// visit all adjacent unvisited vertices
for (int i = 0; i < n; i++) {
if (adj[v][i] == 1 && visited[i] == 0)
dfs(i);
}
}
int main() {
int e;
cout << "Enter number of vertices and edges: ";
cin >> n >> e;
// initialize adjacency matrix
for (int i = 0; i < n; i++)
for (int j = 0; j < n; j++)
adj[i][j] = 0;
cout << "Enter edges (u v):\n";

for (int i = 0; i < e; i++) {
int u, v;
cin >> u >> v;
adj[u][v] = 1;
adj[v][u] = 1; // for undirected graph
}
// initialize visited array
for (int i = 0; i < n; i++)
visited[i] = 0;
int start;
cout << "Enter starting vertex: ";
cin >> start;
cout << "DFS Traversal: ";
dfs(start);
cout << endl;
return 0;
}
