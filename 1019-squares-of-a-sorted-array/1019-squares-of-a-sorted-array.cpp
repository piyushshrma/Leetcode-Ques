class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            nums[i]=nums[i]*nums[i];
        }

        int l=0;
        int r=nums.size()-1;
        vector<int> ans(nums.size(),0);

        for(int i=nums.size()-1; i>=0; i--){
            if(nums[l]>=nums[r]){
                ans[i]=nums[l];
                l++;
            }
            else{
                ans[i]=nums[r];
                r--;
            }
        }
        return ans;
    }
};