#include <iostream>
using namespace std;

int main() {
    int n, e;   // n = number of vertices, e = number of edges

    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // Initialize adjacency matrix with 0
    int adj[20][20] = {0};   // assuming max 20 vertices

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;   // mark edge
        adj[v][u] = 1;   // for undirected graph (remove if directed)
    }

    // Print adjacency matrix
    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}