class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> merged;

        // Insert all elements of nums1 into the map
        for (auto& num : nums1) {
            merged[num[0]] += num[1];
        }

        // Insert all elements of nums2 into the map
        for (auto& num : nums2) {
            merged[num[0]] += num[1];
        }

        // Convert map to the result vector
        vector<vector<int>> result;
        for (auto& pair : merged) {
            result.push_back({pair.first, pair.second});
        }

        return result;
    }
};