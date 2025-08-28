class Solution {
public:

    int help(vector<vector<int>>& dp, int m, int n){
        if(m==0 || n==0) return 0;
        else if (m==1 || n==1) return 1;

        return dp[m][n]=help(dp,m-1,n)+help(dp,m,n-1);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return help(dp,m,n);
    }
};