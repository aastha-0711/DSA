class DisjointSet {
    vector<int> rank, parent, size;

public:
    // Constructor
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Check if two nodes are in the same set
    bool find(int u, int v) {
        return findParent(u) == findParent(v);
    }


    // Union by Size
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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int>mapmailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapmailnode.find(mail)==mapmailnode.end()){
                    mapmailnode[mail]=i;
                }
                else{
                    ds.unionBySize(i,mapmailnode[mail]);
                }
            }
        }
        vector<string>mergee[n];
        for(auto it:mapmailnode){
            string mail=it.first;
            int node=ds.findParent(it.second);
            mergee[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergee[i].size()==0)continue;
            sort(mergee[i].begin(),mergee[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:mergee[i]){
temp.push_back(it);
            }
            ans.push_back(temp);
        }return ans;
    }
};