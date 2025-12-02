#include <iostream>
#include <climits>
using namespace std;
#define V 6 // number of vertices in the graph
// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[]) {
int min = INT_MAX, min_index;
for (int v = 0; v < V; v++)
if (visited[v] == false && dist[v] <= min)
min = dist[v], min_index = v;
return min_index;
}
// Function to print the shortest distances
void printSolution(int dist[]) {
cout << "Vertex \t Distance from Source\n";
for (int i = 0; i < V; i++)
cout << i << "\t\t" << dist[i] << endl;
}
// Dijkstra’s algorithm implementation
void dijkstra(int graph[V][V], int src) {
int dist[V]; // Output array: dist[i] holds the shortest distance from src to i

bool visited[V]; // visited[i] will be true if vertex i is processed
// Initialize all distances as INFINITE and visited[] as false
for (int i = 0; i < V; i++) {
dist[i] = INT_MAX;
visited[i] = false;
}
// Distance from source to itself is always 0
dist[src] = 0;
// Find shortest path for all vertices
for (int count = 0; count < V - 1; count++) {
int u = minDistance(dist, visited);
visited[u] = true;
// Update dist[v] only if:
// - it's not visited
// - there's an edge from u to v
// - and the total weight of path through u is smaller than current dist[v]
for (int v = 0; v < V; v++)
if (!visited[v] && graph[u][v] && dist[u] != INT_MAX
&& dist[u] + graph[u][v] < dist[v])
dist[v] = dist[u] + graph[u][v];
}
// Print the result
printSolution(dist);
}
int main() {
// Adjacency matrix representation of the graph
int graph[V][V] = {
{0, 4, 0, 0, 0, 0},
{0, 0, 8, 0, 0, 0},
{0, 0, 0, 7, 0, 4},
{0, 0, 0, 0, 9, 14},

{0, 0, 0, 0, 0, 10},
{0, 0, 0, 0, 0, 0}
};
int source = 0; // Starting vertex
dijkstra(graph, source);
return 0;
}
