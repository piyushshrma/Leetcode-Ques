class Solution {
public:
    int paths(vector<vector<int>>& dp, int m, int n){
        if(m==0 || n==0) return 0;
        if(m==1 && n==1) return 1;
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        return dp[m][n] = paths(dp,m,n-1)+paths(dp,m-1,n);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // for(int i=0; i<=m; i++){
        //     for(int j=0; j<=n; j++){
        //         arr[i][j]=-1;
        //     }
        // }
        return paths(dp,m,n);
    }
};