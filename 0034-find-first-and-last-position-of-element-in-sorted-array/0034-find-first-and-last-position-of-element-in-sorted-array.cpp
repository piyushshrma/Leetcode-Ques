class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans(2, -1);  // Default to {-1, -1}
        
        if (n == 0) {
            return ans;
        }

        int st = 0;
        int end = n - 1;
        
        // Find the leftmost occurrence of target
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                // Try to find the leftmost index
                end = mid - 1;
                ans[0] = mid;
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        st = 0;
        end = n - 1;

        // Find the rightmost occurrence of target
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                // Try to find the rightmost index
                st = mid + 1;
                ans[1] = mid;
            }
            else if (nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};