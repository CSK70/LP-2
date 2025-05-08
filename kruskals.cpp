#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // for INT_MAX
using namespace std;

class DisjointSet {
    vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int findUPar(int node) {
        if (parent[node] != node)
            parent[node] = findUPar(parent[node]); // Path compression
        return parent[node];
    }

    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

struct Edge {
    int u, v, wt;
};

bool compare(const Edge &a, const Edge &b) {
    return a.wt < b.wt;
}

int kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compare);
    DisjointSet ds(V);

    int mstWeight = 0;
    vector<Edge> mstEdges;

    for (auto &edge : edges) {
        if (ds.findUPar(edge.u) != ds.findUPar(edge.v)) {
            mstWeight += edge.wt;
            mstEdges.push_back(edge);
            ds.unionBySize(edge.u, edge.v);
        }
    }

    cout << "Edges in MST:\n";
    for (auto &e : mstEdges)
        cout << e.u << " - " << e.v << " : " << e.wt << "\n";

    return mstWeight;
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> adjMatrix(V, vector<int>(V));
    cout << "Enter the adjacency matrix (use 0 or INT_MAX for no edge):\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    vector<Edge> edges;
    for (int i = 0; i < V; ++i) {
        for (int j = i + 1; j < V; ++j) { // upper triangle only to avoid duplicates
            if (adjMatrix[i][j] != 0 && adjMatrix[i][j] != INT_MAX) {
                edges.push_back({i, j, adjMatrix[i][j]});
            }
        }
    }

    int totalWeight = kruskalMST(V, edges);
    cout << "Total weight of MST: " << totalWeight << endl;

    return 0;
}
