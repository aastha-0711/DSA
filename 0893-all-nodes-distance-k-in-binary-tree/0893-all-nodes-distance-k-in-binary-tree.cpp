/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void mark(TreeNode*root,unordered_map<TreeNode*, TreeNode*>& parent,TreeNode *target)
{
queue<TreeNode*>qu;
qu.push(root);
while(!qu.empty()){
    TreeNode*current=qu.front();
    qu.pop();
    if(current->left){
        parent[current->left]=current;
        qu.push(current->left);
    }
    if(current->right){
        parent[current->right]=current;
        qu.push(current->right);
    }
}
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;
        mark(root,parent,target);
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true;
        int dist=0;
while(!q.empty()){
    int size=q.size();
    if(dist++==k) break;
for(int i=0;i<size;i++){
    TreeNode*current=q.front();
    q.pop();
    if(current->left && !visited[current->left]){
        q.push(current->left);
        visited[current->left]=true;
    }
      if(current->right && !visited[current->right]){
        q.push(current->right);
        visited[current->right]=true;
    }
    if(parent[current] && !visited[parent[current]]){
        q.push(parent[current]);
        visited[parent[current]]=true;
    }
}
}
vector<int>result;
while(!q.empty()){
   TreeNode*current=q.front();
   q.pop();
   result.push_back(current->val); 
}
return result;
    }
};