class Solution {
public:
    bool isInc(vector<int>& nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]<=nums[i]){

            }
            else{
                return false;
            }
        }
        return true;
    }

    bool isDec(vector<int>& nums){
        for(int i=1; i<nums.size(); i++){
            if(nums[i-1]>=nums[i]){

            }
            else{
                return false;
            }
        }
        return true;
    }

    bool isMonotonic(vector<int>& nums) {
        return isInc(nums) || isDec(nums);
    }
};