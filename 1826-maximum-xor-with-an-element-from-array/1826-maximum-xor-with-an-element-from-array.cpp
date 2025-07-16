struct Trienode{
    Trienode *children[2];
};
class Trie{
private: Trienode *root;
public: 
    Trie(){
        root = new Trienode();
    }

    void insert(int num){
        Trienode *current = root;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1; //1
            if(current->children[bit]==NULL){
                current->children[bit] = new Trienode();
            }
            current = current->children[bit];
        }
    }

    int getMax(int num){
        Trienode *current = root;
        int maximum = 0;
        for(int i=31;i>=0;i--){
            int bit = (num >> i) & 1;
            if(current->children[1-bit]!=NULL){ //opp bit value isn present
                maximum = maximum | (1<<i);
                current = current->children[1-bit];
            }else{
                current = current->children[bit];
            }
        }
        return maximum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());      
        Trie t;
        int q = queries.size();
        vector<int> ans(q,0);
        vector<pair<int,pair<int,int>>> offlineQuery; //vector-> pair->int,pair --> int,int,int
        
        for(int i=0;i<q;i++){
                                    // ai            xi         idx
            offlineQuery.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(offlineQuery.begin(),offlineQuery.end()); //ascending acc to ai

        int n = nums.size();
        int idx = 0;

        for(int i=0;i<q;i++){
            int ai = offlineQuery[i].first;
            int xi = offlineQuery[i].second.first;
            int qidx = offlineQuery[i].second.second;
            while(idx<n && nums[idx]<=ai){
                t.insert(nums[idx]);
                idx++;
            }
            if(idx==0) ans[qidx] = -1;
            else ans[qidx] = t.getMax(xi); 
        }
        return ans;
    }
};