class Solution {
public:
    int rec(int i, int n, vector<int>& nums, vector<int>& dp){
        //base case
        if(i>=n) return 0;

        //check
        if(dp[i]!=-1) return dp[i];

        int rob1=INT_MIN, rob2=INT_MIN;
        //rob it
        rob1=nums[i]+rec(i+2,n,nums,dp);

        // don't rob it
        rob2=rec(i+1,n,nums,dp);

        return dp[i]=max(rob1, rob2);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);

        return rec(0,n,nums,dp);
    }
};