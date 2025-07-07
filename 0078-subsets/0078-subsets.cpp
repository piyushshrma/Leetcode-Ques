class Solution {
public:

    void getSub(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& allSub) {
        if(i == arr.size()) {
            allSub.push_back(ans);  // Push the current subset (ans) to allSub
            return;
        }

        // Include current element
        ans.push_back(arr[i]);
        getSub(arr, ans, i + 1, allSub);

        // Backtrack, exclude current element
        ans.pop_back();
        
        // Exclude current element
        getSub(arr, ans, i + 1, allSub);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSub;
        vector<int> ans;
        int i = 0;

        getSub(nums, ans, i, allSub);  // No need to return from getSub, just modify allSub
        return allSub;  // Return the final result (allSub)
    }
};