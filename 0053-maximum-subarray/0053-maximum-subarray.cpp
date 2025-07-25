class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0;
        int maxSum=INT_MIN;

        for(int i=0; i<nums.size(); i++){
            currSum+=nums[i];
            maxSum=max(currSum, maxSum);

            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};

// Brute Force
// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int maxSum=INT_MIN;
//         for(int i=0; i<nums.size(); i++){
//             int currSum=0;
//             for(int j=i; j<nums.size(); j++){
//                 currSum+=nums[j];
//                 maxSum=max(currSum, maxSum);
//             }
//         }
//         return maxSum;
//     }
// };