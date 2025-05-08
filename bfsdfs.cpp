#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void bfs(vector<int> adj[], int startNode, int numNodes) {
    vector<bool> visited(numNodes, false);
    queue<int> q;

    visited[startNode] = true;
    q.push(startNode);

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int u = q.front();
        cout << u << " ";
        q.pop();

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << endl;
}

void dfs(vector<int> adj[], int startNode, int numNodes) {
    vector<bool> visited(numNodes, false);
    stack<int> s;

    s.push(startNode);

    cout << "DFS Traversal: ";
    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;
        }

        for (int v : adj[u]) {
            if (!visited[v]) {
                s.push(v);
            }
        }
    }
    cout << endl;
}

int main() {
    int numNodes = 6;
    vector<int> adj[numNodes];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);

    bfs(adj, 0, numNodes);
    dfs(adj, 0, numNodes);

    return 0;
}