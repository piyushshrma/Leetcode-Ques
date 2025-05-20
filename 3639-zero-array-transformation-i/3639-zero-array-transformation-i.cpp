class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (const auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l] += 1;
            if (r + 1 < diff.size()) diff[r + 1] -= 1;
        }

        int dec = 0;
        for (int i = 0; i < n; ++i) {
            dec += diff[i];
            if (nums[i] > dec) return false;
        }

        return true;
    }
};
