class DisjointSet {
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]); // Path compression
    }

    void unionSets(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if (up != vp) {
            parent[vp] = up; // Arbitrarily attach v's root to u's root
        }
    }

    int countSets(int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i)
                count++;
        }
        return count;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1; // Not enough cables

        DisjointSet ds(n);
        int extra = 0;

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                extra++; // Redundant connection
            } else {
                ds.unionSets(u, v);
            }
        }

        int components = ds.countSets(n);
        int needed = components - 1;

        return (extra >= needed) ? needed : -1;
    }
};
