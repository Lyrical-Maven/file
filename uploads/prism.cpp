#include <iostream>
using namespace std;

#define V 5
#define INF 9999   // <-- use this if you want a named constant

// Function to find the vertex with minimum key value not yet included in MST
int minKey(int key[], bool mstSet[]) {
    int min = 10000; // Just a large number instead of INT_MAX
    int min_index = -1;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }

    return min_index;
}

// Function to print the MST
void printMST(int parent[], int graph[V][V]) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

// Prim's algorithm
void primMST(int graph[V][V]) {
    int parent[V];  // Stores MST
    int key[V];     // Key values to pick minimum edge
    bool mstSet[V]; // True if vertex is included in MST

    // Initialize keys and mstSet
    for (int i = 0; i < V; i++) {
        key[i] = 10000;  // Large number
        mstSet[i] = false;
    }

    key[0] = 0;       // Start from vertex 0
    parent[0] = -1;   // Root has no parent

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        // Update keys of adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}

