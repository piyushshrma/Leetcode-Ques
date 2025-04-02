class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;  // Initialize to long long minimum value for safety
        int n = nums.size();
        if (n < 3) return ans;  // Return ans if there are fewer than 3 elements

        // Iterate through all triplets (i, j, k) where i < j < k
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    // Make sure to cast (nums[i] - nums[j]) to long long to avoid overflow
                    long long val = (long long)(nums[i] - nums[j]) * nums[k];
                    ans = max(ans, val);  // Update ans if we find a larger value
                }
            }
        }
        return ans;
    }
};
