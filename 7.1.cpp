//dijkstra
#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
int dist[MAX];
bool visited[MAX];
int parent[MAX];
int V;

// Print path from vertex to source
void printPath(int node) {
    if (node == -1) return;
    
    if (parent[node] == -1) {
        cout << node;
        return;
    }

    cout << node << " ";
    printPath(parent[node]);
}

// Dijkstra
void dijkstra(int source) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[source] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = -1;
        int minDist = INF;

        for (int i = 0; i < V; i++) {
            if (!visited[i] && dist[i] < minDist) {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1) break;
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] > 0 && !visited[v] &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    // Print result
    for (int i = 0; i < V; i++) {
        if (i == source) continue;

        if (dist[i] == INF) {
            cout << i << " : No Path\n";
        } else {
            printPath(i);
            cout << " : " << dist[i] << endl;
        }
    }
}

int main() {
    int source;

    cin >> V;

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    cin >> source;

    dijkstra(source);

    return 0;
}