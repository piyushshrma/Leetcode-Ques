class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]!=nums[i]){
                ans.push_back(nums[i]);
            }
        }
        nums=ans;

        return ans.size();
    }
};