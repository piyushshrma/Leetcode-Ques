class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;  // Initialize to long long minimum value for safety
        int n = nums.size();
        if (n < 3) return ans;  // Return ans if there are fewer than 3 elements

        vector<int> prefix_max(n);
        vector<int> suffix_max(n);

        // Preprocess suffix_max array
        prefix_max[0]=nums[0];
        for(int i=1; i<n; i++){
            prefix_max[i]=max(prefix_max[i-1], nums[i]);
        }

        // Preprocess suffix_max array
        suffix_max[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix_max[i] = max(suffix_max[i + 1], nums[i]);
        }

        // Iterate through all triplets (i, j, k) where i < j < k
        for (int i = 1; i < n - 1; i++) {
            int left = prefix_max[i - 1];
            int right = suffix_max[i + 1];
            ans = max(ans, (long long)(left - nums[i]) * right);
        }
        return ans;
    }
};