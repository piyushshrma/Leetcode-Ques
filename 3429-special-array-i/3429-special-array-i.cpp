#include <vector>

class Solution {
public:
    bool isArraySpecial(std::vector<int>& nums) {
        // Check each pair of consecutive elements.
        for (int i = 1; i < nums.size(); ++i) {
            // If two consecutive numbers have the same parity, return false
            if (nums[i] % 2 == nums[i - 1] % 2) {
                return false;
            }
        }
        // If no consecutive numbers have the same parity, return true
        return true;
    }
};