class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> degree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(const auto& pre:prerequisites){
            int courses=pre[0];
            int prereq=pre[1];
            adj[prereq].push_back(courses);
            degree[courses]++;
            
            
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(degree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int a=q.front();
            q.pop();
            count++;
            for(int n:adj[a]){
                degree[n]--;
                if(degree[n]==0){
                    q.push(n);
                }
            }
        }
        return count==numCourses?true:false;
    }
};