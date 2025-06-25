class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        //find the front k sum
        int lsum=0;
        for(int i=0; i<k; i++) lsum+=cardPoints[i];
        int n= cardPoints.size();
        int rsum=0;
        int ans= lsum;
        int rindex=n-1;
        //keep on adding elements from back
        for(int i= k-1; i>=0; i--){
            rsum= rsum+cardPoints[rindex];
            rindex-=1;
            lsum= lsum-cardPoints[i];
            ans= max(ans, rsum+lsum);
        }
        return ans;
    }
};