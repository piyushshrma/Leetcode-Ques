class Solution {
public:
    int rec(int i, int j, int m, int n, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(i>=m || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int down=rec(i+1,j,m,n,obstacleGrid,dp);

        int right=rec(i,j+1,m,n,obstacleGrid,dp);

        return dp[i][j]=down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1]==1) return 0;

        vector<vector<int>> dp(m, vector<int>(n,-1));

        return rec(0,0,m,n,obstacleGrid,dp);
        
    }
};