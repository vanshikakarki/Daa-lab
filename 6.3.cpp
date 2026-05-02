#include <iostream>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];
int V;

bool hasCycle(int node) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < V; i++) {
        if (graph[node][i] == 1) {
            if (!visited[i]) {
                if (hasCycle(i))
                    return true;
            }
            else if (recStack[i]) {
                return true;
            }
        }
    }

    recStack[node] = false;
    return false;
}

int main() {
    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < V; i++) {
        visited[i] = false;
        recStack[i] = false;
    }

    bool cycle = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (hasCycle(i)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle)
        cout << "Yes Cycle Exists";
    else
        cout << "No Cycle Exists";

    return 0;
}