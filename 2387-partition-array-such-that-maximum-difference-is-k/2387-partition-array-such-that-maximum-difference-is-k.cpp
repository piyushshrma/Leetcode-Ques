class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        //Sort the array nums.
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int ct=0, i=0;

        while(i<n){
            int st=nums[i];
            int j=i;

        // Keep extending the subsequence while the condition is met
        while(j<n && nums[j] - st <= k){
            j++;
        }
        // one subsequence formed
        ct++;

        // Move to the next unprocessed number
        i=j;
        }

        return ct;
    }
};