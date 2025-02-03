class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;  // Edge case for empty array

        int inc = 1, dec = 1, longest = 1;
        int n = nums.size();
        
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1]){
                dec++;
                inc=1;
            }
            else if(nums[i-1]<nums[i]){
                inc++;
                dec=1;
            }
            else{
                inc=1;
                dec=1;
            }
            longest=max(longest,max(inc,dec));
        }
        
        return longest;
    }
};
