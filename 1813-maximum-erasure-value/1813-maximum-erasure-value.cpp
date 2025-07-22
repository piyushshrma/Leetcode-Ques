class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int currSum=0, maxSum=0;
        int i=0, j=0;
        int n=nums.size();
        map<int, int> mp;
        while(i<n && j<n){
            if(mp.find(nums[j])==mp.end()){
                mp[nums[j]]++;
                currSum+=nums[j];
                j++;
                maxSum = max(maxSum, currSum);
            }
            else{
                currSum-=nums[i];
                mp.erase(nums[i]);
                i++;
            }
        }
        // for(int i=0; i<nums.size(); i++){
        //     map<int, int> mp;
        //     for(int j=i; j<nums.size(); j++){
        //     if(mp.find(nums[j])==mp.end()){
        //         mp[nums[j]]++;
        //         currSum+=nums[j];
        //     }
        //     else{
        //         maxSum = max(maxSum, currSum);
        //         currSum=0;
        //         break;
        //     }
        //     }
        //     maxSum = max(maxSum, currSum);
        //     currSum=0;
        // }
        return maxSum;
    }
};