class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        
        // Generate all subsets using bitwise representation
        for (int i = 0; i < (1 << n); ++i) { // There are 2^n subsets
            int xorResult = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) { // Check if j-th element is in the subset
                    xorResult ^= nums[j];
                }
            }
            ans += xorResult;
        }
        
        return ans;
    }
};
