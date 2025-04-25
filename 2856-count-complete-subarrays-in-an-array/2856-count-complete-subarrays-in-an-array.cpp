class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        // Ye set original array ke unique elements ko store karta hai
        set<int> st(nums.begin(), nums.end());

        int res = 0;

        // Count of unique elements in original array
        int count = st.size();

        // Har index se subarray start karke check karenge
        for (int i = 0; i < n; i++) {
            set<int> naya;  // Har baar naya set banayenge subarray ke elements ke liye

            // Subarray ke end points
            for (int j = i; j < n; j++) {
                naya.insert(nums[j]);  // current element daalo

                // Agar subarray mein saare unique elements aa gaye
                if (naya.size() == count)
                    res++;  // count increase karo
            }
        }

        return res;
    }
};
