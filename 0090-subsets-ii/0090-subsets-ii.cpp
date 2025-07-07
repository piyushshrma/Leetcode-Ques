class Solution {
public:

    void getSub(vector<int>& arr, vector<int>& ans, int i, vector<vector<int>>& allSub)     {
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
        // Skip duplicates: Only move to the next different element
        while (i + 1 < arr.size() && arr[i] == arr[i + 1]) {
            i++; // Skip duplicate elements
        }

        // Exclude current element
        getSub(arr, ans, i + 1, allSub);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSub;
        vector<int> ans;
        int i = 0;

        getSub(nums, ans, i, allSub);  // Start the recursive subset generation
        return allSub;
    }
};