class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int up = findParent(u);
        int vp = findParent(v);
        if (up == vp) return;

        if (size[up] < size[vp]) {
            parent[up] = vp;
            size[vp] += size[up];
        } else {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }

    int countSets(int n) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (parent[i] == i) count++;
        }
        return count;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1; // Not enough cables

        DisjointSet ds(n);
        int extra = 0;

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                extra++; // This is an extra/redundant cable
            } else {
                ds.unionBySize(u, v);
            }
        }

        int components = ds.countSets(n);
        int needed = components - 1;

        return (extra >= needed) ? needed : -1;
    }
};
