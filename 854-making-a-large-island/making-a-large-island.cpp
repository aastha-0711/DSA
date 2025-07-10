class DisjointSet {
public:
    vector<int> rank, parent, size;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
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
};

class Solution {
    bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step 1: Union adjacent 1s
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int node1 = i * n + j;
                        int node2 = newr * n + newc;
                        ds.unionBySize(node1, node2);
                    }
                }
            }
        }

        // Step 2: Try flipping each 0
        int mx = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) continue;
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = i + dr[ind];
                    int newc = j + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int root = ds.findParent(newr * n + newc);
                        components.insert(root);
                    }
                }
                int size = 0;
                for (auto it : components) {
                    size += ds.size[it];
                }
                mx = max(mx, size + 1); // +1 for the flipped cell
            }
        }

        // Step 3: Handle case when grid has all 1s
        for (int i = 0; i < n * n; i++) {
            mx = max(mx, ds.size[ds.findParent(i)]);
        }

        return mx;
    }
};
