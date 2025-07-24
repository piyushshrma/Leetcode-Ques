class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1));

        for(int level=n-1; level>=0; level--){
            for(int i=0; i<=level; i++){
                dp[level][i] = triangle[level][i] + min(dp[level+1][i], dp[level+1][i+1]);
            }
        }
        return dp[0][0];
    }
};