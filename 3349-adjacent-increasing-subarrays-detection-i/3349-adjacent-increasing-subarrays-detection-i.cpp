class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // If there are fewer than 2*k elements, it's impossible to have two increasing subarrays of length k
        if (n < 2 * k) return false;
        
        vector<bool> inc(n, false);
        
        // Mark all subarrays of length k as increasing or not
        for (int i = 0; i + k <= n; i++) {
            bool ok = true;
            for (int j = i + 1; j < i + k; j++) {
                if (nums[j] <= nums[j - 1]) {
                    ok = false;
                    break;
                }
            }
            inc[i] = ok;
        }
        
        // Check for two non-overlapping increasing subarrays of length k
        for (int i = 0; i <= n - 2 * k; i++) {
            if (inc[i] && inc[i + k]) return true;
        }
        
        return false;
    }
};
