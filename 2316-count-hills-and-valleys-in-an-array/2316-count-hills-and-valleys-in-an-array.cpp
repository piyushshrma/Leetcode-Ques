class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int HandV=0;
        int n = nums.size();

        for(int i=1; i<n-1; i++){
            if (nums[i] == nums[i - 1]) continue;

            int j=i-1; // pichla element
            int k=i+1; // agla element
            
            while(j>=0 && nums[i]==nums[j]) j--;
            while(k<n && nums[i]==nums[k]) k++;
            
            if(j>=0 && k<n){
            if(nums[i]>nums[k] && nums[i]>nums[j]) HandV++;
            else if(nums[i]<nums[k] && nums[i]<nums[j]) HandV++;
        }}
        return HandV;
    }
};

// class Solution {
// public:
//     int countHillValley(vector<int>& nums) {
//         int hills = 0;
//         int val = 0;
//         int n = nums.size();

//         for (int i = 1; i < n - 1; i++) {
//             if (nums[i] == nums[i - 1]) continue;

//             // Check for hill
//             if (nums[i] > nums[i + 1] && nums[i - 1] < nums[i]) {
//                 hills++;
//             }
//             // Check for valley
//             else if (nums[i] < nums[i + 1] && nums[i - 1] > nums[i]) {
//                 val++;
//             }
//             // Check for duplicate with hill pattern (ensure bounds first!)
//             else if (i + 2 < n && nums[i] == nums[i + 1] &&
//                      nums[i] > nums[i - 1] && nums[i + 1] > nums[i + 2]) {
//                 hills++;
//             }
//             // Check for duplicate with valley pattern (ensure bounds first!)
//             else if (i + 2 < n && nums[i] == nums[i + 1] &&
//                      nums[i] < nums[i - 1] && nums[i + 1] < nums[i + 2]) {
//                 val++;
//             }
//         }

//         return hills + val;
//     }
// };