class Solution {
    private:
    bool check(int start, int v, vector<vector<int>>& graph, vector<int>&color){
       queue<int>q;
       q.push(start);
       color[start]=0;
       while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto x: graph[node]){
            if(color[x]==-1){
                color[x]=!color[node];
                q.push(x);
            }
            if(color[x]==color[node])
            {return false;}
        }
       }
       return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
       int n=graph.size();
       int m=graph[0].size();
       vector<int>color(n, -1) ;
       for(int i=0;i<n;i++){
        if(color[i]==-1){
            if(check(i,n,graph,color)==false){
                return false;
            }
        }
       }
       return true;

    }
};