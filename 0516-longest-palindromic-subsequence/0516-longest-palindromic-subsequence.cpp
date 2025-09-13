class Solution {
public:
    int rec(int i, int j, string& s, string& rev, int n, vector<vector<int>>& dp){
        if(i>=n || j>=n) return 0;

        if(s[i]==rev[j]){
            return 1+rec(i+1,j+1,s,rev,n,dp);
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int proins=rec(i+1,j,s,rev,n,dp);

        int proinrev=rec(i,j+1,s,rev,n,dp);

        return dp[i][j] = max(proins, proinrev);
    }
    int longestPalindromeSubseq(string s) {
        string rev = "";
        for(int i=s.size()-1; i>=0; i--){
            rev+=s[i];
        }
        int n=s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
        return rec(0,0,s,rev,n,dp);
    }
};