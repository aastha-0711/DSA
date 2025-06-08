class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
       vector<bool> ZeroRows(n,false);
       vector<bool> ZeroCol(m,false);
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==0){
                ZeroRows[i]=true;
                ZeroCol[j]=true;
            }
        }
       } 
        for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(ZeroRows[i] || ZeroCol[j]){
                matrix[i][j]=0;
            }}}

    }
};