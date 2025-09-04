class Solution {
public:
    bool rec(int i, int sum, int totalSum, vector<int>& nums, vector<vector<int>>& dp){
    //base
    if(i==nums.size()){
        return sum==(totalSum/2);
    }

    //check
    if(dp[i][sum]!=-1) return dp[i][sum];

    //recursive case

    //not take
    bool not_take = rec(i+1, sum, totalSum, nums,dp);

    //take
    bool take = false;
    if(sum+nums[i]<=totalSum/2){
    take = rec(i+1, sum+nums[i], totalSum, nums,dp);
}
    return dp[i][sum] = take || not_take;
}

    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        int n=nums.size();
        for(auto& it:nums){
            totalSum+=it;
        }
        vector<vector<int>> dp(n+1, vector<int>((totalSum / 2) + 1,-1));
        if(totalSum % 2 == 1){
            return false;
        }

        return rec(0,0,totalSum,nums,dp);
    }
};