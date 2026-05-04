//bellmann-ford
#include <iostream>
#include <climits>
using namespace std;

const int MAX = 100;
const int INF = INT_MAX;

int graph[MAX][MAX];
int dist[MAX];
int parent[MAX];
int V;

void printPath(int node) {
    if (node == -1) return;

    if (parent[node] == -1) {
        cout << node;
        return;
    }

    cout << node << " ";
    printPath(parent[node]);
}

void bellmanFord(int source) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Relax edges V-1 times
    for (int k = 0; k < V - 1; k++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] > 0 &&
                    dist[u] != INF &&
                    dist[u] + graph[u][v] < dist[v]) {

                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
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

    bellmanFord(source);

    return 0;
}