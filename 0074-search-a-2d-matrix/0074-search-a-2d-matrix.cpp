class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
   int left=0;
   int m=matrix.size();
   int n=matrix[0].size();
   int right=m*n-1;
   while(left<=right){
    int mid=left+(right-left)/2;
int midElement=matrix[mid/n][mid%n];
if(midElement==target){
    return true;
}      
else if(midElement<target){
    left=mid+1;
}  
else{
    right=mid-1;
}
    }
   
    return false;}
};