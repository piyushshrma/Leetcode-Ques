class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n =  nums.size();
        if(n<=0){
            return 0;
        }

        int maxVal=0;
        for(int num : nums){
            if(num>maxVal){
                maxVal=num;
            }
        }

        int maxLen=0;
        int currLen=0;

        for(int i=0; i<n; i++){
            if(nums[i]==maxVal){
                currLen++;
            }
            else{
                maxLen = max(maxLen, currLen);
                currLen=0;
            }
        }
        return max(maxLen, currLen);
    }
};