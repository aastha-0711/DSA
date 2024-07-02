class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
           unordered_map<int,int> mp2;
       for(int num:nums1){
           mp[num]++;
       }
        for(int num:nums2){
            mp2[num]++;
        }
        vector<int> result;
        for(auto& pair : mp)
        {
            int num=pair.first;
            int count_num1=pair.second;
            if(mp2.find(num)!=mp2.end())
            {
                int count_num2=mp2[num];
                int fin=min(count_num1,count_num2);
                for(int i=0;i<fin;i++)
                {
                    result.push_back(num);
                }
            }
        }return result;
}};