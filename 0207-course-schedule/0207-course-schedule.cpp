class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);
for(auto it:prerequisites){
    adj[it[1]].push_back(it[0]);
indegree[it[0]]++;
}
queue<int>q;
for(int i=0;i<numCourses;i++){
    if(indegree[i]==0){
        q.push(i);
    }
}
vector<int>result;
while(!q.empty()){
    int course=q.front();
    q.pop();
    result.push_back(course);
    for(int x:adj[course]){
        indegree[x]--;
        if(indegree[x]==0){
            q.push(x);
        }
    }
}
if (result.size() == numCourses) return true;
        return false;

    }
};