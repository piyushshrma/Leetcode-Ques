class Solution {
public:
    int findMin(vector<int>& cost, vector<int>& dp, int idx){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx] = cost[idx]+min(findMin(cost,dp,idx+1),findMin(cost,dp,idx+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(findMin(cost,dp, 0),findMin(cost,dp, 1));
    }
};