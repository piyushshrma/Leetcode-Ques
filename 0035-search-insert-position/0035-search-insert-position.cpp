class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0;
        int end = nums.size() - 1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (nums[mid] == target) {
                return mid;  // Target found, return its index
            } else if (nums[mid] < target) {
                st = mid + 1;  // Narrow down to the right half
            } else {
                end = mid - 1;  // Narrow down to the left half
            }
        }

        // If the target is not found, return the insert position
        return st;  // 'st' will be the index where the target can be inserted
    }
};
