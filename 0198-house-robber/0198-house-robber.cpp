class Solution {
public:
    int rec(int i, vector<int>& nums, vector<int>& dp){
        //base case
        if(i>=nums.size()){
            return 0;
        }

        //check
        if(dp[i]!=-1) return dp[i];

        int take=nums[i]+rec(i+2,nums,dp);

        int not_take=rec(i+1,nums,dp);

        return dp[i] = max(take, not_take);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return rec(0, nums,dp);
    }
};