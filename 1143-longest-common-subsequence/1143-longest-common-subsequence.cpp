class Solution {
public:
    int rec(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
        int m=text1.size();
        int n=text2.size();

        if(i>=m || j>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        if(text1[i]==text2[j]){
            return 1+rec(i+1, j+1, text1, text2,dp);
        }

        //ek baar text1
        int int1 = rec(i+1,j,text1,text2,dp);

        //ek baar text2
        int int2 = rec(i,j+1,text1,text2,dp);

        return dp[i][j] = max(int1, int2);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        return rec(0,0,text1,text2,dp);
    }
};