class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = 3; len <= n; ++len) { // len is the length of the subarray from i to j
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1; // j is the other endpoint of the subarray
                dp[i][j] = INT_MAX;
                
                // Try every possible vertex k to form a triangle (i, j, k)
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return dp[0][n-1];
    }
};