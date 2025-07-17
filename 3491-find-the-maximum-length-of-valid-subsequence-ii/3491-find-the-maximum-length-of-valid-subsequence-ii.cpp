class Solution {
public:
    // int asns(vector<int>& nums, int k, vector<int>& dp){

    // }
    int maximumLength(vector<int>& nums, int k) {
        int maxL=0;
        for(int val=0; val<k; val++){
            vector<int> dp(k,0);
            for(int num:nums){
                int rem=num%k;
                int need=(val-rem+k)%k;
                int newLen = dp[need]+1;
                dp[rem] = max(dp[rem], newLen);
                maxL = max(maxL, dp[rem]);
            }
        }
        return maxL;
    }
};