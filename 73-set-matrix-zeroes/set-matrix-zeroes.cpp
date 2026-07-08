class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //not optimised solution as per description but ya short and acceptable
        int m = matrix.size();
        int n = matrix[0].size();
        vector<bool>firstrow (m,false);
        vector<bool>firstcol (n,false);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    firstrow[i] = true;
                    firstcol[j] = true;
                }
            }
        }
        for(int i = 0;i<m;i++){
            for(int j=0;j<n;j++){
                if(firstrow[i] || firstcol[j]){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};