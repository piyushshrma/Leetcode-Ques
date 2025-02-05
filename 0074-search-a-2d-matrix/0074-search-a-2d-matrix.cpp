class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        // int s=m*n;
        vector<int> allnum(m*n);
        int k=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                allnum[k]=matrix[i][j];
                k++;
            }
        }

        for(int i=0; i<allnum.size(); i++){
            if(allnum[i]==target) return true;
        }
        return false;

    }
};