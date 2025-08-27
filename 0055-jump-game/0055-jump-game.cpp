class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(range<=0) return false;
            range=max(range-1, nums[i]);
        }
        return true;
    }
};