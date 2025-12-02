#include <iostream>
#include <queue>
using namespace std;
int main() {
int n, e;
cout << "Enter number of vertices and edges: ";
cin >> n >> e;
int adj[10][10] = {0}; // adjacency matrix (max 10 vertices)
cout << "Enter edges (u v):\n";
for (int i = 0; i < e; i++) {
int u, v;
cin >> u >> v;
adj[u][v] = 1;
adj[v][u] = 1; // for undirected graph
}
int visited[10] = {0};
queue<int> q;
int start;
cout << "Enter starting vertex: ";
cin >> start;
visited[start] = 1;
q.push(start);

cout << "BFS Traversal: ";
while (!q.empty()) {
int node = q.front();
q.pop();
cout << node << " ";
// check all possible vertices
for (int i = 0; i < n; i++) {
if (adj[node][i] == 1 && visited[i] == 0) {
visited[i] = 1;
q.push(i);
}
}
}
cout << endl;
return 0;
}
