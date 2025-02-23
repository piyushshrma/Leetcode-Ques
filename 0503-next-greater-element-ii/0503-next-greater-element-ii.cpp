class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);  // Initialize all values to -1

        // Traverse the array twice, because we need to handle the circular nature of the array
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < i + n; ++j) {  // Loop from i+1 to i+n to handle the circular nature
                if (nums[j % n] > nums[i]) {
                    ans[i] = nums[j % n];
                    break;
                }
            }
        }

        return ans;
    }
};
