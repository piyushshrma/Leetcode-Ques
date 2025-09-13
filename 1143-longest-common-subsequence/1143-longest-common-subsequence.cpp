class Solution {
public:
    int rec(int i, int j, string& text1, string& text2, vector<vector<int>>& dp) {
        // Base case: If we reach the end of either string, no more common subsequence
        if (i == text1.size() || j == text2.size()) return 0;

        // If already computed, return the cached result
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, add 1 and recurse further
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + rec(i + 1, j + 1, text1, text2, dp);
        }

        // If characters don't match, explore both possibilities and take the max
        return dp[i][j] = max(
            rec(i, j + 1, text1, text2, dp), // Skip character from text2
            rec(i + 1, j, text1, text2, dp)  // Skip character from text1
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        // Initialize dp array with -1 to mark uncomputed subproblems
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // Start recursion from the beginning of both strings
        return rec(0, 0, text1, text2, dp);
    }
};
