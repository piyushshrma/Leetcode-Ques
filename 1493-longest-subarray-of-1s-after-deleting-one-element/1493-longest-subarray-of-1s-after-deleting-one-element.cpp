class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=0, maxLen=0;
        int zeroCount=0;
        
        for(int j=0; j<n; j++){
            if(nums[j]==0) zeroCount++;

            while(zeroCount>1){
                if(nums[i]==0) zeroCount--;
                i++;
            }
            maxLen=max(maxLen, j-i);
        }
        return maxLen;

    }
};