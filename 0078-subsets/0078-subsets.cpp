class Solution {
public:

    void getAllSub(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSub) {
        if (i == nums.size()) {
            allSub.push_back(ans);  // Corrected: Add the current subset to allSub
            return;
        }

        ans.push_back(nums[i]);  // Include the current element in the subset
        getAllSub(nums, ans, i + 1, allSub);  // Recursive call to include the next element

        ans.pop_back();  // Exclude the current element from the subset
        getAllSub(nums, ans, i + 1, allSub);  // Recursive call to exclude the next element
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSub;  // To store all subsets
        vector<int> ans;  // To store the current subset

        getAllSub(nums, ans, 0, allSub);  // Start the recursion

        return allSub;  // Return the list of all subsets
    }
};
