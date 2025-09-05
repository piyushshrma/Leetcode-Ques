class Solution {
public:
    int rec(int n, vector<int>& dp){
        //Base Case
        if(n==0 || n==1){
            return 1;
        }

        //Check
        if(dp[n]!=-1){
            return dp[n];
        }

        return dp[n]=rec(n-1,dp)+rec(n-2,dp);        
    }
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return rec(n,dp);
    }
};