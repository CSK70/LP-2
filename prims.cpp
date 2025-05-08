#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    vector<vector<int>> graph(vertices, vector<int>(vertices));
    cout << "Enter the adjacency matrix (0 for no edge):" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cin >> graph[i][j];
        }
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(vertices, INT_MAX);
    vector<int> parent(vertices, -1);
    vector<bool> inMST(vertices, false);

    int startVertex = 0;
    key[startVertex] = 0;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << " \tWeight: " << graph[i][parent[i]] << endl;
    }
    int sum=0;
    for (int i = 1; i < vertices; ++i) {
        sum+=graph[i][parent[i]];
    }
    cout<<"Sum:"<<sum;

    return 0;
}