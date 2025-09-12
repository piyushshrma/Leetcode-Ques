class Solution {
public:
    int rec(int i, int n, vector<int>& nums, vector<int>& dp){
        if(i>=n){
            return 0;
        }

        //check
        if(dp[i]!=-1) return dp[i];

        //take
        int take=nums[i]+rec(i+2,n,nums,dp);

        //nottake
        int nottake=rec(i+1,n,nums,dp);

        return dp[i]=max(take, nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1, -1);
        return rec(0,n,nums,dp);
    }
};