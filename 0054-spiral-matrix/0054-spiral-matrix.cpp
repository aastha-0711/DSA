class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      int bottom=matrix.size()-1;
      int left,top=0;
      int right=matrix[0].size()-1;
      vector<int>res;
      while(left<=right && top<=bottom){
        for(int i=left;i<=right;i++){
            res.push_back(matrix[top][i]);
        }
        top++;
        for(int i=top;i<=bottom;i++){
            res.push_back(matrix[i][right]);
        }
        right--;
       if(top <= bottom){
                // Bottom row
                for(int i = right; i >= left; i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right){
                // Left column
                for(int i = bottom; i >= top; i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
        
    }
};