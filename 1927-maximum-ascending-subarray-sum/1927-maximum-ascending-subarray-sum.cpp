class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int finans=0;
        int ans;
        int idx=1;
        for(int i=0; i<n; i++){
            ans=nums[i];
            idx=i+1;
            while(idx<n && nums[idx-1]<nums[idx]){
                ans+=nums[idx];
                idx++;
            }
            finans=max(finans,ans);
        }
        return finans;
    }
};