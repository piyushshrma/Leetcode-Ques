class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        int n = nums.size();
        
        while (i < n && j < n) {
            if (nums[i] % 2 == 0) {
                i += 2;  // move i to next even index
            } else if (nums[j] % 2 != 0) {
                j += 2;  // move j to next odd index
            } else {
                swap(nums[i], nums[j]);
                i += 2;  // after swap, move both indices
                j += 2;
            }
        }
        
        return nums;
    }
};