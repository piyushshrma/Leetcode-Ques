class Solution {
public:
    int rec(int i, int j, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return grid[i][j];
        }
        if(i>=m || j>=n){
            return INT_MAX;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int down= rec(i+1,j,m,n,grid,dp);

        int right= rec(i,j+1,m,n,grid,dp);

        return dp[i][j]= grid[i][j] + min(down,right);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return rec(0,0,m,n,grid,dp);
    }
};