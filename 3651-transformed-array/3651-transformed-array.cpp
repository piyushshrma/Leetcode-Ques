class Solution {
public:
    int mod(int a, int b) {
        return (a % b + b) % b;
    }
    
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> ans(nums.size(), -1);
        int ind=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                int idx=(i+nums[i])%nums.size();
                ans[i]=nums[idx];
            }
            else if(nums[i]<0){
                int idx = mod(i + nums[i], nums.size());
                if(idx < 0) idx += nums.size();
                ans[i] = nums[idx];
            }
            else if(nums[i]==0){
                ans[i]=nums[i];
            }
        }
        return ans;
    }
};